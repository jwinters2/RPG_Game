#include "Object.h"

#include "ObjModel.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Math.h"

#include <string>

Object::Object(std::string mn,std::string tn):
              Entity(),
              position(),velocity(0.01f,0.0f,0.0f),rotation(identityQuat()),model_name(mn),texture_name(tn)
{

  std::cout << model_name << ", " << texture_name << std::endl;

  GraphicsManager* gm = GraphicsManager::getInstance();

  ObjModel* model = gm->getObjModel(mn);
  if(model == NULL)
  {
    model = new ObjModel(mn,tn);
  }

  std::cout << "gm: " << gm << std::endl;

  gm->loadObjModel(model);
}

Object::~Object()
{
}

Object* Object::insertInstance(std::string model_name,std::string texture_name)
{
  EntityManager* em = EntityManager::getInstance();

  if(em != NULL)
  {
    Object* temp = new Object(model_name,texture_name);
    em->insertEntity(temp);
    return temp;
  }

  return NULL;
}

bool Object::logic(int step)
{
  position += velocity; 
}

bool Object::render()
{
  std::cout << "Object render (id = " << getId() << ")" << std::endl;
  GraphicsManager::getInstance()->renderObjModel(model_name,texture_name,position,vec3(1.0f),rotation);
}

void Object::setPosition(const vec3& p)
{
  position = p;
}
