#pragma once
#include <vector>
#include <type_traits>

namespace ECS
{
    struct ComponentBitGenerator
    {
    public:
        static size_t GetNextLayer()
        {
            static size_t counter = 0;
            if (counter == 0)
                return ++counter;
            else
                return counter <<= 1;
        }
    };

    template<typename Component>
    struct ComponentBit
	{
    public: 
        static size_t GetLayer()
        {
            static const size_t layer = ComponentBitGenerator::GetNextLayer();
            return layer;
        }
	};  


    template<typename... Components>
    struct Signature
    {
        inline static size_t g_layer = (ComponentBit<Components>::GetLayer() | ... | 0ull);

    };
}