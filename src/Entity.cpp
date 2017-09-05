#include "Entity.h"

#include "GraphicsManager.h"
#include "EntityManager.h"

#include <iostream>

unsigned int Entity::master_id = 0;


Entity::Entity():id(master_id)
{
  master_id++;
}

Entity::~Entity()
{
}

bool Entity::logic(int step)
{
  return true;
}

bool Entity::render()
{
  std::cout << "Entity render (id=" << id << ")" << std::endl;
  return true;
}

unsigned int Entity::getId() const
{
  return id;
}

Entity* Entity::insertInstance()
{
  EntityManager* em = EntityManager::getInstance();

  if(em != NULL)
  {
    Entity* temp = new Entity();
    em->insertEntity(temp);
    return temp;
  }

  return NULL;
}
