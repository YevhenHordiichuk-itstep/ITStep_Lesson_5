//homework_5_06         "Evklid distance"

#include <cmath>
#include <cstdio>

struct tPoint {
  float x, y, z;
};

float Evklid (tPoint A, tPoint B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) + (A.z - B.z) * (A.z - B.z));
}

int main(int argc, char** argv) {
  tPoint A, B;
  printf("point1 ");
  scanf("%f %f %f", &A.x, &A.y, &A.z);
  printf("point2 ");
  scanf("%f %f %f", &B.x, &B.y, &B.z);
  
  printf("Evklid distance %0.2f", Evklid(A, B));
  return 0;
}