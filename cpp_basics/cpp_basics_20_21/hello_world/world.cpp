#include <iostream>
#include "world.h"

void World::hello()
{
  std::cout << "Hello world, it's the year " << year << std::endl;
}

World::World(int newYear)
{
  std::cout << "This world begins " << std::endl;
  year=newYear;
}

World::~World()
{
  std::cout << "This world ends " << std::endl;
}
