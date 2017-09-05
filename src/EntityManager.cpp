#include "EntityManager.h"

#include "GraphicsManager.h"
#include "Entity.h"

#include <iostream>

EntityManager* EntityManager::instance = NULL;

EntityManager::EntityManager():gm(NULL)
{
}

EntityManager::~EntityManager()
{
  for(std::map<unsigned int,Entity*>::iterator it=entityList.begin(); it!=entityList.end(); ++it)
  {
    delete it->second;
  }
  
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
  for(std::map<unsigned int,Entity*>::iterator it=entityList.begin(); it!=entityList.end(); ++it)
  {
    it->second->logic(0);
  }
}

bool EntityManager::RenderIterate()
{
  for(std::map<unsigned int,Entity*>::iterator it=entityList.begin(); it!=entityList.end(); ++it)
  {
    std::cout << it->first << " " << it->second << std::endl;
    it->second->render();
  }
}

bool EntityManager::insertEntity(Entity* e)
{
  std::cout << "inserting entity id = " << e->getId() << std::endl;
  if(e == NULL || entityList.find(e->getId()) != entityList.end())
  {
    return false;
  }

  entityList[e->getId()] = e;
  return true;
}

bool EntityManager::deleteEntity(unsigned int)
{
}
