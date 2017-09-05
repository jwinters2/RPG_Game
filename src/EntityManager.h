#pragma once

#include <map>

class Entity;
class GraphicsManager;

class EntityManager
{
  public:
    static EntityManager* getInstance();

    bool setGraphicsManager(GraphicsManager*);

    bool LogicIterate();
    bool RenderIterate();

    bool insertEntity(Entity*);
    bool deleteEntity(unsigned int);

  private:
    EntityManager();
    ~EntityManager();

    static EntityManager* instance;
    GraphicsManager* gm;

    std::map<unsigned int,Entity*> entityList;
    
};
