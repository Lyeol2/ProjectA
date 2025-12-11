#pragma once
#include <gtest/gtest.h>
#include <Component.h>
#include <Signature.h>
#include <World.h>

using namespace std;
using namespace ECS;

class TEST_World : public ::testing::Test
{

protected:
	TEST_World()
	{
		world = new World(100000000);
	}
	~TEST_World() override 
	{
		delete world;
	}

	World* world;
};	
TEST(SignatureTest, layerTest)
{

	// 싱글 조합 체크
	EXPECT_EQ(Signature<ComponentA>::g_layer, 1);
	EXPECT_EQ(Signature<ComponentB>::g_layer, 2);
	EXPECT_EQ(Signature<ComponentC>::g_layer, 4);


	// 2개 조합 체크
	EXPECT_EQ((Signature<ComponentA, ComponentB>::g_layer), 3);
	EXPECT_EQ((Signature<ComponentB, ComponentC>::g_layer), 6);

	// 위치변경 체크
	EXPECT_EQ((Signature<ComponentC, ComponentA>::g_layer), 5);
	EXPECT_EQ((Signature<ComponentA, ComponentC>::g_layer), 5);

	// 3개 조합 체크
	EXPECT_EQ((Signature<ComponentA, ComponentB, ComponentC>::g_layer), 7);

}
TEST(ArchetypeTest, sizeTest)
{

	// 싱글 조합 체크
	EXPECT_EQ(Archetype<ComponentA>::g_size, sizeof(ComponentA));
	EXPECT_EQ(Archetype<ComponentB>::g_size, sizeof(ComponentB));
	EXPECT_EQ(Archetype<ComponentC>::g_size, sizeof(ComponentC));

	// 두개 조합 체크
	EXPECT_EQ((Archetype<ComponentA, ComponentB>::g_size), (sizeof(ComponentA) + sizeof(ComponentB)));
	EXPECT_EQ((Archetype<ComponentA, ComponentC>::g_size), (sizeof(ComponentA) + sizeof(ComponentC)));


}
TEST_F(TEST_World, CreateWorld)
{

}