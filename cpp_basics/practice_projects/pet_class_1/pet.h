#include <iostream>

class Pet
{
public:
  //constructor and destructor
  Pet(std::string name, int age);

  ~Pet();

  // getters and setters
  std::string getName();
  int getAge();

  void setName(std::string name);
  void setAge(int age);
  // methods

private:
  std::string name;
  int age;
};
