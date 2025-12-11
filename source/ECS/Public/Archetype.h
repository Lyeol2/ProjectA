#pragma once
#include <Chunk.h>
#include <vector>
#include <type_traits>
#include <Signature.h>

namespace ECS
{


	/**
	* @brief Entity Component System의 탐색 최적화를 위한 Archetype 구조체
	* @details Archetype은 특정 조합의 컴포넌트를 가진 엔티티들을 그룹화하여 메모리 접근 패턴을 최적화합니다.
	* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
	*/
	template <typename... Components>
	struct Archetype
	{
		Signature<Components...> signature;


		constexpr static size_t g_size = (sizeof(Components) + ... + 0);

	public:
		/** @details 아키타입내의 청크 */
		static std::vector<Chunk<sizeof(unsigned int), 16, g_size>> g_chunks;


		/**
		* Archetype의 쿼리
		*/
		static void Query(void(*query)(Components... args))
		{
			if (g_chunks.size() < 1)
			{
				return;
			}
			for (size_t i = 0; i < g_chunks.size(); i++)
			{
				for (auto data : g_chunks[i])
				{

				}
			}
		}

		static void AddData()
		{
			if (g_chunks.size() < 1)
			{
				g_chunks.push_back(Chunk<sizeof(unsigned int), 16, g_size>());
			}

			for (size_t i = 0; i < g_chunks.size(); i++)
			{
				for (auto data : g_chunks[i])
				{

				}
			}

		}
		static void RemoveData()
		{

		}

	};


	template<int Layer>
	struct AlignArchetype
	{
		static void Chunk()
		{

		}
	};
};