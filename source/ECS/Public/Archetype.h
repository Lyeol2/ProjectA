#pragma once
#include <Chunk.h>
#include <vector>
#include <type_traits>

namespace ECS
{


	/**
	* @brief 단일 Entity Component System의 탐색 최적화를 위한 Archetype 구조체
	* @details Archetype은 특정 조합의 컴포넌트를 가진 엔티티들을 그룹화하여 메모리 접근 패턴을 최적화합니다.
	* @param[in] template Component 단일 컴포넌트 타입
	*/
	template <typename Component>
	struct SingleArchetype
	{
		constexpr static size_t size = sizeof(Component);
	};


	/**
	* @brief Entity Component System의 탐색 최적화를 위한 Archetype 구조체
	* @details Archetype은 특정 조합의 컴포넌트를 가진 엔티티들을 그룹화하여 메모리 접근 패턴을 최적화합니다.
	* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
	*/
	template <typename Component, typename... Components>
	struct Archetype
	{
		using current = SingleArchetype<Component>;

		using next = std::conditional_t<sizeof...(Components) == 1,
			SingleArchetype<Components...>,
			Archetype<Components...>>;

		constexpr static size_t g_size = sizeof(Component) + next::size;

	public:
		/** @details 아키타입내의 청크 */
		static std::vector<Chunk<4, 16, g_size>> g_chunks;


		/**
		* Archetype의 쿼리
		*/
		static void Query(void(*query)(Component arg, Component... args))
		{
			for (size_t i = 0; i < length; i++)
			{

			}
		}

		static void AddData()
		{

		}
		static void RemoveData()
		{

		}

	};
};