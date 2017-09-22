#pragma once

#include "Object.h"
#include "Camera.h"
#include "Math.h"

class Player: public Object
{
  public:
    virtual bool logic(int);
    virtual bool render();

    static Player* insertInstance();

  private:
    Player();
    ~Player();

    Camera* camera;
};
