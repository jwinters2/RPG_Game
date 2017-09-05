#include "src/GraphicsManager.h"
#include "src/ObjModel.h"
#include "src/Math.h"
#include "src/EntityManager.h"
#include "src/Entity.h"
#include "src/Object.h"
#include "src/Camera.h"

int main(int argc, char** argv)
{
  GraphicsManager* gm = GraphicsManager::getInstance();   // get a reference to the singleton
  //ObjModel person("../res/sample_person.obj","../res/sample_person_tex.bmp");
  //ObjModel person2("../res/sample_person.obj","../res/sample_person_tex.bmp");
  //ObjModel art("../res/art.obj","../res/art_tex.bmp");
  //person.setPosition(vec3(2.0f,0.0f,0.0f));
  //art.setScale(vec3(0.7f));
  //art.setPosition(vec3(-1.0f,-3.0f,-1.0f));

  //vec3 person_pos(2.0f,0.0f,0.0f);
  //vec3 person_scale(1.0f);
  //vec4 person_rot = identityQuat();

  //vec3 person2_pos(-2.0f,0.0f,0.0f);
  //vec3 person2_scale(0.5f);
  //vec4 person2_rot = identityQuat();


  //vec3 art_pos(-1.0f,-3.0f,-1.0f);
  //vec3 art_scale(0.7f);
  //vec4 art_rot = identityQuat();
  //person.readFile("../res/cube.obj");



  //gm->LoadBMP("../res/sample_person_tex.bmp");
  float angle=0.0f;

  if(gm != NULL)
  {
    if(!gm->init())       // initialize the graphics engine or whatever (setup OpenGL/DirectX/Vulkan etc)
    {
      return -1;
    }

    EntityManager* em = EntityManager::getInstance();
    em->setGraphicsManager(gm);

    Object::insertInstance("../res/art.obj","../res/art_tex.bmp")->setPosition(vec3( 5.0f,0.0f,0.0f));
    Object* o = Object::insertInstance("../res/art.obj","../res/art_tex.bmp");

    o->setPosition(vec3(-5.0f,0.0f,0.0f));

    o->setRotation(axisAngleToQuat(vec4(0.0f,0.0f,1.0f,45.0f)));

    Camera* c = Camera::insertInstance();
    c->setPosition(vec3(0.0f,0.0f,15.0f));
    gm->setCamera(c);
    //gm->loadObjModel(person);
    //gm->loadObjModel(person2);
    //gm->loadObjModel(art);
   
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
    }
    
    gm->deinit();     // undo gm->init()
  }

  return 0;
}
