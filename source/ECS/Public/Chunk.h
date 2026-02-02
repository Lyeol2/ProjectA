#pragma once
#include <vector>
#include <iterator>

namespace ECS
{
	template<size_t indexSize, size_t ChunkSize, size_t TypeSize>
	struct Chunk
	{
		char* m_data = nullptr;

		int m_size = 0;


		/** @details 유닛크기 = 색인크기 + 타입크기 */
		constexpr static size_t g_unitSize = indexSize + TypeSize;

		Chunk()
		{
			// KB 단위 -TODO- 색인크기랑 타입크기는 추가할 필요없을듯
			m_data = new char[1024 * (indexSize + ChunkSize)];
		}
		virtual ~Chunk() noexcept
		{
			if (m_data != nullptr)
			{
				delete[] m_data;
				m_data = nullptr;
			}
		}


		Chunk(const Chunk&) = delete;


		Chunk& operator=(const Chunk&) = delete;


		Chunk(Chunk&& other) noexcept
			: m_data(other.m_data), m_size(other.m_size)
		{
			other.m_data = nullptr;
			other.m_size = 0;
		}

		Chunk& operator=(Chunk&& other) noexcept {
			if (this != &other) {
				delete[] m_data;
				m_data = other.m_data;
				m_size = other.m_size;

				other.m_data = nullptr;
				other.m_size = 0;
			}
			return *this;
		}

	public:
		const int GetCount()
		{
			return m_size / g_unitSize;
		}

		bool AddData(const char* data)
		{
			// 사이즈가 넘는다면 추가하지 않음

			if (m_size + g_unitSize > 1024 * ChunkSize)
				return false;
			std::memcpy(m_data + m_size, data, g_unitSize);

			m_size += g_unitSize;
			return true;
		}

		bool RemoveData(size_t index)
		{
			// 인덱스가 유효하지 않다면 제거하지 않음
			if (index * TypeSize >= m_size)
				return false;
			// 마지막 데이터를 제거할 위치로 복사
			std::memcpy(m_data + (index * g_unitSize),
				m_data + (m_size - g_unitSize),
				g_unitSize);

			m_size -= g_unitSize;
			return true;
		}

		/**
		* @brief Chunk의 커스텀 Iterator
		* @details TypeSize만큼 쿼리를 돌려 컴포넌트 데이터를 접근하는 반복자를 생성합니다.
		* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
		*/
		class iterator {
		public:
			using iterator_category = std::input_iterator_tag;
			using value_type = char*;
			using difference_type = std::ptrdiff_t;

		private:
			char* ptr;

		public:
			explicit iterator(char* p) : ptr(p) {}

			char* operator*() const {
				return ptr + indexSize;
			}

			iterator& operator++() {
				ptr += g_unitSize;
				return *this;
			}

			bool operator==(const iterator& other) const {
				return ptr == other.ptr;
			}
		};

		iterator begin()
		{
			return iterator(m_data);
		}
		iterator end()
		{
			return iterator(m_data + m_size);
		}
	};


	template<size_t indexSize, size_t ChunkSize, size_t TypeSize>
	struct ChunkVector
	{
		std::vector<Chunk<indexSize, ChunkSize, TypeSize>> m_chunks;

		int m_size = 0;

		struct iterator {
			using iterator_category = std::input_iterator_tag;
			using value_type = char*;
			using difference_type = std::ptrdiff_t;

			ChunkVector* owner;
			size_t chunk_idx;

			using chunk_type = Chunk<indexSize, ChunkSize, TypeSize>;
			typename chunk_type::iterator inner{ nullptr };

			char* operator*() const {
				return *inner;
			}

			iterator& operator++() {
				++inner;
				if (inner == owner->m_chunks[chunk_idx].end()) {
					++chunk_idx;
					if (chunk_idx < owner->m_chunks.size())
						inner = owner->m_chunks[chunk_idx].begin();
					else
						return *this;
				}
				return *this;
			}

			bool operator==(const iterator& other) const {
				return chunk_idx == other.chunk_idx &&
					(chunk_idx == owner->m_chunks.size() || inner == other.inner);
			}
			bool operator!=(const iterator& other) const {
				return !(*this == other);
			};

			iterator begin() {
				if (m_chunks.empty())
					return end();

				return iterator{ this, 0, m_chunks[0].begin() };
			}

			iterator end() {
				return iterator{ this, m_chunks.size(), {} };
			}

		};
		/**
			* Archetype의 쿼리
		*/
		void AddData(const char* data)
		{
			if (m_chunks.size() < 1)
			{
				m_chunks.push_back(Chunk<sizeof(unsigned int), 16, TypeSize>());
			}

			if (!m_chunks[m_chunks.size() - 1].AddData(data))
			{
				m_chunks.push_back(Chunk<sizeof(unsigned int), 16, TypeSize>());
				m_chunks[m_chunks.size() - 1].AddData(data);
			}

		}
		void RemoveData(int index)
		{
			int eraseIdx = -1;
			for (size_t i = 0; i < m_chunks.size(); i++)
			{
				if (!m_chunks[i].RemoveData(index)) continue;

				if (m_chunks[i].GetCount() <= 0)
				{
					eraseIdx = i;
				}
			}
			if (eraseIdx >= 0)
				m_chunks.erase(m_chunks.begin() + eraseIdx);
		}

	};
}