#include "Camera.h"

Camera::Camera():position(),target(),up(0.0f,1.0f,0.0f)
{
}

Camera::~Camera()
{
}

void Camera::setPosition(const vec3& a)
{
  position = a;
}

void Camera::setTarget(const vec3& a)
{
  target = a;
}

void Camera::setUp(const vec3& a)
{
  up = a;
}

vec3 Camera::getPosition()
{
  return position;
}

vec3 Camera::getTarget()
{
  return target;
}

vec3 Camera::getUp()
{
  return up;
}

void Camera::move(const vec3& a)
{
  position += a;
}
