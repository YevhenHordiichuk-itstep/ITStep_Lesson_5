//homework_5_7
//S=1/2((х1-х3)(у2-у3)-(х2-х3)(у1-у3)). 

#include <cstdio> 

struct Points {
  int x, y;
};

void line(Points point1, Points point2, Points point3) {
  int s = ((point1.x - point3.x) * (point2.y - point3.y) - (point2.x - point3.x) * (point1.y - point3.y)) / 2;
  if (s == 0) {
    printf("YES");
  } else {
    printf("NO");
  }
  printf("\n");
}

int main(int argc, char** argv) {
  Points point1, point2, point3;
  scanf("%i %i", &point1.x, &point1.y);
  scanf("%i %i", &point2.x, &point2.y);
  scanf("%i %i", &point3.x, &point3.y);
  line(point1, point2, point3);
  return 0;
}