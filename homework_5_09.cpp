// homework_5_9 
// ((х1-х3)(у2-у3)-(х2-х3)(у1-у3)) != 0

#include <cstdio>

struct DPoint {
  int x, y;
  
  DPoint();
};

DPoint::DPoint() {
  scanf("%i %i", &x, &y);
}

void onCircle(DPoint point1, DPoint point2, DPoint point3) {
  if ((point1.x - point3.x) * (point2.y - point3.y) - (point2.x - point3.x) * (point1.y - point3.y) == 0) {
    printf("NO");
  } else {
    printf("YES");
  }
  printf("\n");
}

int main(int argc, char** argv) {
  DPoint point1;
  DPoint point2;
  DPoint point3;
  
  onCircle(point1, point2, point3);
  return 0;
}