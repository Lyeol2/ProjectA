#pragma once
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

		for (size_t i = 0; i < m_maxEntityCount; i++)
		{
			m_freeEntityIndices.push(i);
		}
	}
	void World::AlignEntities()
	{
	}
	void World::RigisterComponentType()
	{

	}

	void World::CreateEntity()
	{

	}
	void World::DestroyEntity(const Entity& entity)
	{


		m_freeEntityIndices.push(entity.m_entity);
	}
}