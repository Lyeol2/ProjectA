#pragma once
#include <Chunk.h>
#include <map>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <Signature.h>
#include <TMPUtility.h>
#include <Query.h>

namespace ECS
{
	
	/**
	* @brief Entity Component System의 탐색 최적화를 위한 Archetype 구조체
	* @details Archetype은 특정 조합의 컴포넌트를 가진 엔티티들을 그룹화하여 메모리 접근 패턴을 최적화합니다.
	* @param[in] template Components... - Archetype에 속하는 컴포넌트 타입들
	*/
	template <int SignatureLayer, int DataSize>
	struct AlignArchetype
	{

	public:
		/** @details 아키타입내의 청크 */
		static ChunkVector<sizeof(unsigned int), 16, DataSize> g_chunks;

		/**
		* Archetype의 쿼리
		*/
		static void AddData(const char* data)
		{
			g_chunks.AddData(data);
		}
		static void RemoveData(int index)
		{
			g_chunks.RemoveData(index);
		}
	};

	template<typename... Components>
	struct Archetype
	{

	public:

		using Container = typename AlignArchetype<Signature<Components...>::g_layer, Signature<Components...>::g_size>;
		

		static void AddData()
		{
			Container::AddData();
		}
		static void RemoveData(int index)
		{
			Container::RemoveData(index);

		}
	};
};