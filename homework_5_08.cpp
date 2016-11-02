// homework_5_8 
// (х1-х2)/(х3-х2)=(y1-у2)/(у3-у2)=(z1-z2)/(z3-z2)

#include <cstdio>

struct TPoint {
  int x, y, z;
  
  TPoint();
};

TPoint::TPoint() {
  scanf("%i %i %i", &x, &y, &z);
}

int exceptions(int a, int b, int c) {
  if (a - b == 0) {
    return 0;
  } else if (c - b == 0) {
    return 0;
  }
  return (a - b) / (c - b);  
}

void onLine(TPoint point1, TPoint point2, TPoint point3) {
  if (exceptions(point1.x, point2.x, point3.x) == 
      exceptions(point1.y, point2.y, point3.y) &&
      exceptions(point1.x, point2.x, point3.x) ==
      exceptions(point1.z, point2.z, point3.z)) {
    printf("YES");
  } else {
    printf("NO");
  }
  printf("\n");
}

int main(int argc, char** argv) {
  TPoint point1;
  printf("_\n");
  TPoint point2;
  printf("_\n");
  TPoint point3;
  printf("_\n");
  
  onLine(point1, point2, point3);
  return 0;
}