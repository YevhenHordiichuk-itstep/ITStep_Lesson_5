// homework_5_9 
// ((х1-х3)(у2-у3)-(х2-х3)(у1-у3)) != 0

#include <iostream>
#include <cstdlib>
#include <windows.h>

struct DPoint {
  int x, y;
  
  DPoint(int& x, int& y) {
    this->x = x;
    this->y = y;
  }
  
  DPoint(const DPoint& obj) {
    this->x = obj.x;
    this->y = obj.y;
  }
  
};

DPoint generate() {
  int x = -10 + rand() % 20;
  int y = -10 + rand() % 20;
  return DPoint(x, y);
}

void onCircle(DPoint point1, DPoint point2, DPoint point3) {
  if ((point1.x - point3.x) * (point2.y - point3.y) - (point2.x - point3.x) * (point1.y - point3.y) == 0) {
    std::cout << "\a\nNO\n";
    Sleep(3000);
  } else {
    std::cout << "YES ";
  }
}

int main(int argc, char** argv) {
  srand(32);
  while(true) {
    DPoint point1 = generate();
    DPoint point2 = generate();
    DPoint point3 = generate();
    
    onCircle(point1, point2, point3);
  }
  return 0;
}