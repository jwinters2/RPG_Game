#include "Model.h"

int main()
{
  Model m;
  m.readFile("../res/sample_person.obj");
  m.print();
}
