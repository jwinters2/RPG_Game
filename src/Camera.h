#pragma once

#include "Object.h"
#include "Math.h"

class Camera: public Object
{
  public:
    virtual bool logic(int);
    virtual bool render();

    static Camera* insertInstance();

    void lookX(float);
    void lookY(float);

  private:
    Camera();
    ~Camera();

    float xangle;
    float yangle;
};
