#include <iostream>

#include <Application.h>


class A 
{

};
class B
{

};

#include <Archetype.h>

int main()
{

    std::cout << "Hello World!" << std::endl;

    Application app;
     
    std::cout << ECS::Archetype<A, B>::g_size << std::endl;



    app.Run();
    
    return 0;
}