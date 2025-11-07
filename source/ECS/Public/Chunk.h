namespace ECS
{
	template<size_t ChunkSize, size_t TypeSize>
	struct Chunk
	{
		Chunk()
		{
			// KB ¥‹¿ß
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

		char* m_data = nullptr;

	};
}