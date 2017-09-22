#pragma once

#include "Object.h"
#include "Camera.h"
#include "Math.h"

class Duck: public Object
{
  public:
    virtual bool logic(int);

    static Duck* insertInstance();

    void setCyclePos(int);

  private:
    Duck();
    ~Duck();

    int cyclePos;
};
