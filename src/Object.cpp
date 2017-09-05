#include "Object.h"

#include "ObjModel.h"
#include "EntityManager.h"
#include "Entity.h"
#include "Math.h"

#include <string>

Object::Object(std::string mn,std::string tn):
              Entity(),
              position(),velocity(0.0f,0.0f,0.0f),rotation(identityQuat()),model_name(mn),texture_name(tn)
{

  if(!mn.empty())
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
  GraphicsManager::getInstance()->renderObjModel(model_name,texture_name,position,vec3(1.0f),rotation);
}

vec3 Object::getPosition() const
{
  return position;
}

void Object::setPosition(const vec3& p)
{
  position = p;
}

void Object::addPosition(const vec3& p)
{
  position += p;
}

vec3 Object::getVelocity() const
{
  return velocity;
}

void Object::setVelocity(const vec3& v)
{
  velocity = v;
}

void Object::addVelocity(const vec3& v)
{
  velocity += v;
}

vec4 Object::getRotation() const
{
  return rotation;
}

void Object::setRotation(const vec4& q)
{
  rotation = q;
  rotation.normalize();
}

void Object::addRotation(const vec4& q)
{
  rotation = multiplyQuat(rotation,q);
  rotation.normalize();
}
