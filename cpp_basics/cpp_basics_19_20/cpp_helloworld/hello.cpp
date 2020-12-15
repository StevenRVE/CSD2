#include <iostream>

/* class HelloWorld

  members:
  constructor
  hello()
*/

class HelloWorld
{
public: // members
  HelloWorld() // constructor
  {
    year = 1970; // default value
  }

  int setYear(int newyear)
  {
    year = newyear;
  }

  int hello()
  {
    std::cout << "Hello in the year " << year << "!" << std::endl;
    return 0;
  }

////////////////////////////////////////////////////////////////////////////////
  int year;
};


int main()
{
  HelloWorld hw1();
  HelloWorld hw2();
  HelloWorld hw3();

  hw1.setYear(2019);
  hw1.hello();
  hw2.setYear(2020);
  hw2.hello();
  hw3.hello();

  return 0;
}
