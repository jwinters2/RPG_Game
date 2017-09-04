#include "src/GraphicsManager.h"
#include "src/ObjModel.h"
#include "src/Math.h"

int main(int argc, char** argv)
{
  GraphicsManager* gm = GraphicsManager::getInstance();   // get a reference to the singleton
  ObjModel person("../res/sample_person.obj","../res/sample_person_tex.bmp");
  ObjModel art("../res/art.obj","../res/art_tex.bmp");
  person.setPosition(vec3(2.0f,0.0f,0.0f));
  art.setScale(vec3(0.7f));
  art.setPosition(vec3(-1.0f,-3.0f,-1.0f));
  //person.readFile("../res/cube.obj");

  //gm->LoadBMP("../res/sample_person_tex.bmp");
  float angle=0.0f;

  if(gm != NULL)
  {
    if(!gm->init())       // initialize the graphics engine or whatever (setup OpenGL/DirectX/Vulkan etc)
    {
      return -1;
    }
    gm->loadObjModel(person);
    gm->loadObjModel(art);
   
    while(!gm->closeButtonPressed())
    {
      gm->startFrame();
      gm->renderObjModel(person);
      gm->renderObjModel(art);
      gm->endFrame();

      person.setRotation(vec4(0.0f,1.0f,0.0f,angle));
      angle += 0.01f;
      if(angle >= 360.0f)
      {
        angle = 0.0f;
      }

      gm->moveCamera(vec3(0.0f,0.0f,0.01f));
    }
    
    gm->unloadObjModel(person);
    gm->unloadObjModel(art);
    gm->deinit();     // undo gm->init()
  }

  return 0;
}
