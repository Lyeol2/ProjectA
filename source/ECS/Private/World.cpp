#include "ECS.h"

namespace ECS
{
	World::World(const int& maxEntityCount)
	{
		Initialize(maxEntityCount);
	}
	World::~World() noexcept
	{
	}
	void World::Initialize(const int& maxEntityCount)
	{
		m_maxEntityCount = maxEntityCount;

		m_entities = new unsigned int[m_maxEntityCount];
	}
	void World::AlignEntities()
	{
	}
	void World::RigisterComponentType()
	{
	}
}