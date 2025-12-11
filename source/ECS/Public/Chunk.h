#pragma once
#include <cstring>
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
			// KB 단위
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

		void AddData(const char* data)
		{
			// 사이즈가 넘는다면 추가하지 않음
			
			if (m_size + g_unitSize > 1024 * ChunkSize)
				return;
			std::memcpy(m_data + m_size, data, g_unitSize);

			m_size += g_unitSize;
		}
		void RemoveData(size_t index)
		{
			// 인덱스가 유효하지 않다면 제거하지 않음
			if (index * TypeSize >= m_size)
				return;
			// 마지막 데이터를 제거할 위치로 복사
			std::memcpy(m_data + (index * g_unitSize),
				m_data + (m_size - g_unitSize),
				g_unitSize);

			m_size -= g_unitSize;
		}

		/**
		* @brief Chunk의 커스텀 Iterator
		* @details TypeSize만큼 쿼리를 돌려 컴포넌트 데이터를 접근하는 반복자를 생성합니다.
		* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
		*/
		class iterator : std::iterator<std::input_iterator_tag, char>
		{
			char* _ptr;
		public:
			explicit iterator(char* ptr) :_ptr(ptr) {}

			iterator& operator++() { _ptr += TypeSize; return (*this); }
			iterator operator++(int) { iterator retval = *this; _ptr += TypeSize; return retval; }

			reference operator*() { return *_ptr; }

			bool operator==(iterator other) const { return _ptr == other._ptr; }
			bool operator!=(iterator other) const { return _ptr != other._ptr; }
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
}