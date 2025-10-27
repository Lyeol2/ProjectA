#include <iostream>
#include <ECS.h>
#include <Application.h>
using namespace ECS;
int main()
{
    
    struct Archetype<struct ComponentA> archetype(1,1,1);
    std::cout << "Hello World!" << std::endl;

    Application app;


    app.Run();
    
    return 0;
}