#include "Entity.h"
#include "Archetype.h"
#include <queue>
/**
* @brief Entity Component System
* @details 
* @param[in] a 숫자1
* @param[in] b 숫자2
* @param[out] c 결과
* @return void
* @note 참고 설명
* @todo 할 일 설명
* @pre 미리 호출해야 할 사항
* @bug 버그 설명
* @warning 참고 링크, 페이지
* @see 참고할 함수 또는 페이지
*/
namespace ECS
{
	/**
	* @brief 이건 월드 클래스다
	* @details 월드는 ECS의 핵심 구성 요소로, 엔티티와 컴포넌트를 관리합니다.
	*/
	class World
	{
	public:
		World(const int& maxEntityCount);
		virtual ~World() noexcept;

	private:

		/** @details 월드의 entity 필드입니다 */
		unsigned int m_maxEntityCount = 0;
		/** @details 월드의 entity 필드입니다 */
		unsigned int* m_entities = nullptr;
		/** @details 월드의 컴포넌트 개수입니다. 이 컴포넌트 개수는 엔티티 구조를 정렬할때 쓰입니다. */
		unsigned int m_componentCount = 0;
		/** @details 컴포넌트에 따른 아키타입 개수입니다. 컴포넌트의 개수가 변할때마다 변경됩니다. */
		unsigned int m_archetypeCount = 0;

		std::queue<unsigned int> m_freeEntityIndices;

	public:
		/** @details 월드를 초기화 합니다. */
		void Initialize(const int& maxEntityCount);
		/** @details 월드의 엔티티 필드를 정렬합니다. 컴포넌트 개수에 영향을 받습니다. */
		void AlignEntities();
		/** @details 월드에 사용할 컴포넌트를 추가합니다. */
		void RigisterComponentType();

		void CreateEntity();

		void DestroyEntity(const Entity& entity);


	private:



	};
}