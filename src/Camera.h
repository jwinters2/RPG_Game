#include "Math.h"

class Camera
{
  private:
    vec3 position;
    vec3 target;
    vec3 up;

  public:
    Camera();
    ~Camera();

    void setPosition(const vec3& a);
    void setTarget(const vec3& a);
    void setUp(const vec3& a);

    vec3 getPosition();
    vec3 getTarget();
    vec3 getUp();

    void move(const vec3& a);
};
