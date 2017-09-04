#include "Entity.h"

unsigned int Entity::master_id = 0;

Entity::Entity()
{
  id = master_id++;
}

Entity::~Entity()
{
}
