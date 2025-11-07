#pragma once

#include "ECS.h"

namespace ECS
{
    /**
    * @brief 컴포넌트 구조체
	* @details 월드에서 엔티티들이 가지는 데이터의 단위입니다. 64바이트가 넘으면 좀 그럼.
    */
    struct Component
    {
        /**
		* @details 이 컴포넌트의 메모리 크기
        */
        unsigned int size;
    };
    struct ComponentA : Component
    {

    };
    struct ComponentB : Component
    {

    };
    struct ComponetC : Component
    {

    };
}