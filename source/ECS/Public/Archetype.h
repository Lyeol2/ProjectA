#pragma once

#include <type_traits>

namespace ECS
{

	class Chunk;


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
		Archetype(int chunkCapacity, int chunkSize, int chunkCount)
		{
			m_chunkCapacity = chunkCapacity;
			m_chunkUnit = chunkSize;
			m_chunkCount = chunkCount;
		}
		virtual ~Archetype() noexcept
		{

		}

		using current = SingleArchetype<Component>;

		using next = std::conditional_t<sizeof...(Components) == 1,
			SingleArchetype<Components...>,
			Archetype<Components...>>;

		constexpr static size_t size = sizeof(Component) + next::size;

	public:
		/** @details 아키타입내의   */
		Chunk* m_chunks = nullptr;
		int m_chunkCapacity;
		int m_chunkUnit = 0;
		int m_chunkCount = 0;


	};
};