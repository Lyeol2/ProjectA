#include "Entity.h"
#include "Archetype.h"
/**
* @brief Entity Component System
* @details 두 정수를 더하는 동작을 수행합니다.
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
	class World : Archetype
	{
		World() = default;
		virtual ~World() noexcept;






	};
}