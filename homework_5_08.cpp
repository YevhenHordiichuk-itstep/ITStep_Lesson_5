// homework_5_8 
// (х1-х2)/(х3-х2)=(y1-у2)/(у3-у2)=(z1-z2)/(z3-z2)

#include <iostream>
#include <cstdlib>

struct TPoint {
  int X, Y, Z;
    
  TPoint(int x, int y, int z)
  : X(x), Y(y), Z(z) {
    
  }
};

int exceptions(int a, int b, int c) {
  if (a - b == 0) {
    return 0;
  } else if (c - b == 0) {
    return 0;
  }
  return (a - b) / (c - b);  
}

void onLine(TPoint point1, TPoint point2, TPoint point3) {
  if (exceptions(point1.X, point2.X, point3.X) == 
      exceptions(point1.Y, point2.Y, point3.Y) &&
      exceptions(point1.X, point2.X, point3.X) ==
      exceptions(point1.Z, point2.Z, point3.Z)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}

void generate(int& x, int& y, int& z) {
  x = -10 + rand() % 20;
  y = -10 + rand() % 20;
  z = -10 + rand() % 20;
}

int main(int argc, char** argv) {
  srand(32);
  while(true) {
    int x, y, z;
  
    generate(x, y, z);
    TPoint point1(x, y, z);
    generate(x, y, z);
    TPoint point2(x, y, z);
    generate(x, y, z);
    TPoint point3(x, y, z);
  
    onLine(point1, point2, point3);
  }
  return 0;
}