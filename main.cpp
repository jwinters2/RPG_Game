#include "src/GraphicsManager.h"
#include "src/ObjModel.h"
#include "src/Math.h"
#include "src/EntityManager.h"
#include "src/Entity.h"
#include "src/Object.h"
#include "src/Camera.h"
#include "src/Player.h"
#include "src/Duck.h"

int main(int argc, char** argv)
{
  GraphicsManager* gm = GraphicsManager::getInstance();   // get a reference to the singleton

  float angle=0.0f;

  if(gm != NULL)
  {
    if(!gm->init())       // initialize the graphics engine or whatever (setup OpenGL/DirectX/Vulkan etc)
    {
      return -1;
    }

    EntityManager* em = EntityManager::getInstance();
    em->setGraphicsManager(gm);

    for(float i=-10.0f;i<=10.0f;i+=5.0f)
    {
      for(float j=-10.0f;j<=10.0f;j+=5.0f)
      {
        //Duck* temp = Duck::insertInstance();//"../res/duck.obj","../res/duck_tex.bmp");
        //temp->setPosition(vec3(i,-1.0f,j));
        temp->setScale(vec3(0.4f));
        //temp->setCyclePos((int)(10 * (i+j)));
      }
    }

    Object* o = Object::insertInstance("../res/art.obj","../res/art_tex.bmp");

    o->setPosition(vec3(-40.0f,40.0f,0.0f));
    o->setScale(vec3(5.0f));

    o->setRotation(axisAngleToQuat(vec4(0.0f,0.0f,1.0f,45.0f)));

    Player* p = Player::insertInstance();
   
    //int frame = 0;
    while(!gm->closeButtonPressed())
    {
      em->LogicIterate();

      gm->startFrame();
      em->RenderIterate();
      //gm->renderObjModel(person,person_pos,person_scale,person_rot);
      //gm->renderObjModel(person2,person2_pos,person2_scale,person2_rot);
      //gm->renderObjModel(art,art_pos,art_scale,art_rot);
      gm->endFrame();

      //person_rot = axisAngleToQuat(vec4(1.0f,1.0f,1.0f,angle));
      //art_rot = axisAngleToQuat(vec4(1.0f,20.0f,0.0f,angle/3.0f));
      angle += 1.0f;
      if(angle >= 1080.0f)
      {
        angle = 0.0f;
      }

      o->addRotation(axisAngleToQuat(vec4(0.0f,1.0f,0.0f,1.0f)));

      //std::cout << "frame " << frame++ << std::endl;
    }
    
    gm->deinit();     // undo gm->init()
  }

  return 0;
}
