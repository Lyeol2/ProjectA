namespace ECS
{
	template<size_t ChunkSize, size_t TypeSize>
	struct Chunk
	{


		char* m_data = nullptr;
		int m_size = 0;

		Chunk()
		{
			// KB 단위
			m_data = new char[1024 * ChunkSize];
		}
		virtual ~Chunk() noexcept
		{
			if (m_data != nullptr)
			{
				delete[] m_data;
				m_data = nullptr;
			}
		}

	

		/**
		* @brief Chunk의 커스텀 Iterator
		* @details TypeSize만큼 쿼리를 돌려 컴포넌트 데이터를 접근하는 반복자를 생성합니다.
		* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
		*/
		class iterator : std::iterator<std::input_iterator_tag, char>
		{
			T* _ptr;
		public:
			explicit iterator(T* ptr) :_ptr(ptr) {}


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