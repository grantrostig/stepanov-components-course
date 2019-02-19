#include "singleton.h"
#include <iostream>

typedef singleton<double> sd;
typedef singleton<double> si;

int main() {
  sd x(1.5);
  sd y(2.5);
  sd z(1);

  x = 5;

  y = x + x;
  z = x + y;

  double xx = x.value;
  double yy = y.value;
  double zz = z.value;
  std::cout << xx << std::endl;
  std::cout << yy << std::endl;
  std::cout << zz << std::endl;
//  std::cout << x + x << std::endl;
//  std::cout << y + y << std::endl;
//  std::cout << x + z << std::endl;

}
  
  
