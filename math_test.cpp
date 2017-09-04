#include <iostream>

#include "Math.h"

void print(const vec3& v)
{
  std::cout << "[" << v.x << "," << v.y << "," << v.z << "]" << std::endl;
}

int main()
{
  vec3 a(1.0f,2.0f,3.0f);
  vec3 b(5.0f);

  print(a);
  print(b);

  a += b;

  print(a);
  print(b);
}
