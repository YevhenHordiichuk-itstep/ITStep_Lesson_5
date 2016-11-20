//homework_5_03 merge sort of Point + test(fail, see "corn");

#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <windows.h>

struct Point {
  float x, y;
};

float distance(Point A, Point B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); 
}
operator < (Point left, Point right) {
  Point ZERO = {0, 0};
  return distance(left, ZERO) < distance(right, ZERO);
}
operator != (Point left, Point right) {
  return left.x != right.x || left.y != right.y;
}
operator == (Point left, Point right) {
  return left.x == right.x && left.y == right.y;
}

void merge(Point left[], Point right[], size_t left_size, size_t right_size, Point output[]) {  
  size_t l = 0, r = 0, k = 0;
  while (l < left_size && r < right_size) {
    if (left[l] < right[r]) {
      output[k] = left[l];
      ++l;
    } else {
      output[k] = right[r];
      ++r;
    }
    ++k;
  }
  
  if (l == left_size) {
    while (r < right_size) {
      output[k] = right[r];
      ++r;
      ++k;
    }
  }
  
  if (r == right_size) {
    while (l < left_size) {
      output[k] = left[l];
      ++l;
      ++k;
    }
  }
}
void mergeSort(Point points[], size_t SIZE) {
  if (SIZE < 2) {
    return;
  }
  
  size_t left_size = SIZE / 2;
  size_t right_size = SIZE - left_size;
  
  Point left[left_size];
  Point right[right_size];
  
  for (size_t i = 0; i < left_size; ++i) {
    left[i] = points[i];
  }
  
  for (size_t i = 0; i < right_size; ++i) {
    right[i] = points[i + left_size];
  }
  
  mergeSort(left, left_size);
  mergeSort(right, right_size);
  merge(left, right, left_size, right_size, points);
}

void copyArray(Point points[], Point copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = points[i];
  }
}

void printArray(Point points[], size_t SIZE) {
  const char* delimiter = "";
  printf("points = [");
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s(%0.6f, %0.6f)", delimiter, points[i].x, points[i].y);
    delimiter = ", ";
  }
  printf("]\n");
}

void generate(Point points[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    points[i].x = (float) rand() / RAND_MAX + rand() % 100;
    points[i].y = (float) rand() / RAND_MAX + rand() % 100;
  }
}
bool compare(Point array[], Point copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    if (array[i] != copy[i]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  while (true) {
    size_t corn = GetTickCount() + rand();
    srand(corn);
    size_t SIZE = 1 + rand() % 26;
    
    Point points[SIZE];
    Point points_copy[SIZE];
    generate(points, SIZE);
    copyArray(points, points_copy, SIZE);
    mergeSort(points, SIZE);
    
    std::sort(points_copy, points_copy + SIZE);
    
    if (compare(points, points_copy, SIZE)) {
      printf("OK\n");
    } else {
      printf("\aError!\t%i\nSize = %i\n", corn, SIZE);
      printArray(points, SIZE);
      printf("Test sort:\n");
      printArray(points_copy, SIZE);
      break;
    }
  }
  return 0;
}