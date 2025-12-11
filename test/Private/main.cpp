#include <iostream>
#include <gtest/gtest.h>
#include <Archetype.h>
#include <Signature.h>
#include <Component.h>

#include <ECS/TEST_World.h>

using namespace std;
using namespace ECS;


int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);



	return RUN_ALL_TESTS();
}