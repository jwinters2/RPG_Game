#include "Math.h"

#include <cmath>
#include <string>

vec2::vec2()
{
  x = 0.0f;
  y = 0.0f;
}

vec2::vec2(const vec2& o)
{
  x = o.x;
  y = o.y;
}

vec2::vec2(float val)
{
  x = val;
  y = val;
}

vec2::vec2(float x_a,float y_a)
{
  x = x_a;
  y = y_a;
}

const float vec2::length()
{
  return (float)(sqrt( x*x + y*y ));
}

const std::string vec2::toString()
{
  return ("[" + std::to_string(x) + "," + std::to_string(y) + "]");
}

vec2 operator+(const vec2& a,const vec2& b)
{
  vec2 retval;
  retval.x = a.x + b.x;
  retval.y = a.y + b.y;
  return retval;
}

vec2 operator+=(vec2& v,const vec2& o)
{
  v.x += o.x;
  v.y += o.y;
  return vec2(v);
}

vec2 operator*(const vec2& v,float s)
{
  vec2 retval;
  retval.x = v.x * s;
  retval.y = v.y * s;
  return retval;
}

vec2 operator*(float s,const vec2& v)
{
  return v * s;
}



vec3::vec3()
{
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
}

vec3::vec3(const vec3& o)
{
  x = o.x;
  y = o.y;
  z = o.z;
}

vec3::vec3(float val)
{
  x = val;
  y = val;
  z = val;
}

vec3::vec3(float x_a,float y_a,float z_a)
{
  x = x_a;
  y = y_a;
  z = z_a;
}

const float vec3::length()
{
  return (float)(sqrt( x*x + y*y + z*z ));
}

const std::string vec3::toString()
{
  return ("[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) +"]");
}

vec3 operator+(const vec3& a,const vec3& b)
{
  vec3 retval;
  retval.x = a.x + b.x;
  retval.y = a.y + b.y;
  retval.z = a.z + b.z;
  return retval;
}

vec3 operator+=(vec3& v,const vec3& o)
{
  v.x += o.x;
  v.y += o.y;
  v.z += o.z;
  return vec3(v);
}

vec3 operator*(const vec3& v,float s)
{
  vec3 retval;
  retval.x = v.x * s;
  retval.y = v.y * s;
  retval.z = v.z * s;
  return retval;
}

vec3 operator*(float s,const vec3& v)
{
  return v * s;
}



vec4::vec4()
{
  x = 0.0f;
  y = 0.0f;
  z = 0.0f;
  w = 0.0f;
}

vec4::vec4(const vec4& o)
{
  x = o.x;
  y = o.y;
  z = o.z;
  w = o.w;
}

vec4::vec4(float val)
{
  x = val;
  y = val;
  z = val;
  w = val;
}

vec4::vec4(float x_a,float y_a,float z_a,float w_a)
{
  x = x_a;
  y = y_a;
  z = z_a;
  w = w_a;
}

const float vec4::length()
{
  return (float)(sqrt( x*x + y*y + z*z + w*w ));
}

const std::string vec4::toString()
{
  return ("[" + std::to_string(x) + "," + std::to_string(y) + "," + 
                std::to_string(z) + "," + std::to_string(w) + "]");
}

vec4 operator+(const vec4& a,const vec4& b)
{
  vec4 retval;
  retval.x = a.x + b.x;
  retval.y = a.y + b.y;
  retval.z = a.z + b.z;
  retval.w = a.w + b.z;
  return retval;
}

vec4 operator+=(vec4& v,const vec4& o)
{
  v.x += o.x;
  v.y += o.y;
  v.z += o.z;
  v.w += o.w;
  return vec4(v);
}

vec4 operator*(const vec4& v,float s)
{
  vec4 retval;
  retval.x = v.x * s;
  retval.y = v.y * s;
  retval.z = v.z * s;
  retval.w = v.w * s;
  return retval;
}

vec4 operator*(float s,const vec4& v)
{
  return v * s;
}



const double Math::PI = 3.14159263538979;
