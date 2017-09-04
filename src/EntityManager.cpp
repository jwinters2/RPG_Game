#include "EntityManager.h"

#include "GraphicsManager.h"
#include "Entity.h"

EntityManager* EntityManager::instance = NULL;

EntityManager::EntityManager():gm(NULL)
{
}

EntityManager::~EntityManager()
{
  if(instance != NULL)
  {
    delete instance;
  }
}

EntityManager* EntityManager::getInstance()
{
  if(instance == NULL)
  {
    instance = new EntityManager();
  }

  return instance;
}

bool EntityManager::setGraphicsManager(GraphicsManager* gm_a)
{
  if(gm_a == NULL)
  {
    return false;
  }

  gm = gm_a;
  return true;
}

bool EntityManager::LogicIterate()
{
}

bool EntityManager::RenderIterate()
{
}

bool EntityManager::insertEntity(Entity*)
{
}

bool EntityManager::deleteEntity(unsigned int)
{
}
