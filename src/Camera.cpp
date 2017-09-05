#include "Camera.h"
#include "EntityManager.h"
#include "GraphicsManager.h"

#include <iostream>

Camera::Camera():Object("","")
{
  addRotation(axisAngleToQuat(vec4(0.0f,1.0f,0.0f,10.0f)));
}

Camera::~Camera()
{
}

Camera* Camera::insertInstance()
{
  EntityManager* em = EntityManager::getInstance();

  if(em != NULL)
  {
    Camera* temp = new Camera();
    em->insertEntity(temp);
    return temp;
  }

  return NULL;
}

bool Camera::logic(int step)
{
  GraphicsManager* gm = GraphicsManager::getInstance();

  double mouse_x,mouse_y;
  gm->getMouseSpeed(mouse_x,mouse_y);

  float dt = gm->getDeltaTime();

  float dx = (float)(mouse_x * dt);
  float dy = (float)(mouse_y * dt);

  addRotation(axisAngleToQuat(vec4(0.0f,1.0f,0.0f,dx)));
  addRotation(axisAngleToQuat(vec4(1.0f,0.0f,0.0f,dy)));

  if(gm->getKeyDown(340)) // left shift
  {
    std::cout << "crouch" << std::endl;
    dt *= 0.2f;
  }

  if(gm->getKeyDown('W'))
  {
    addPosition(applyQuatToVec3(rotation,vec3(0.0f,0.0f,-1.0f)) * 15.0f * dt);
  }

  if(gm->getKeyDown('S'))
  {
    addPosition(applyQuatToVec3(rotation,vec3(0.0f,0.0f,1.0f)) * 15.0f * dt);
  }

  if(gm->getKeyDown('A'))
  {
    addPosition(applyQuatToVec3(rotation,vec3(-1.0f,0.0f,0.0f)) * 15.0f * dt);
  }

  if(gm->getKeyDown('D'))
  {
    addPosition(applyQuatToVec3(rotation,vec3(1.0f,0.0f,0.0f)) * 15.0f * dt);
  }
}

bool Camera::render()
{
  GraphicsManager* gm = GraphicsManager::getInstance();
  if(gm != NULL)
  {
    
  }
}
