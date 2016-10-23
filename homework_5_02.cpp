// homework_5_02, merge sort of Point

#include <cstdio>
#include <algorithm>
#include <cmath>

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
    printf("%s(%0.2f, %0.2f)", delimiter, points[i].x, points[i].y);
    delimiter = ", ";
  }
  printf("]\n");
}

int main(int argc, char** argv) {
  Point points[] = {{3.14, -0.05}, {71.3, 1.1}, {82.2, -4.13}, {91.5, 32.6}, {-11.01, 54.02}, {71.9, 2.0}, {0, 13.0}, {30.03, 0}, {61.0, 6.0}, {-41.99, 66.5}};
  size_t SIZE = sizeof(points) / sizeof(points[0]);
  Point copy_points[SIZE];
  copyArray(points, copy_points, SIZE);
  
  mergeSort(copy_points, SIZE);
  printArray(points, SIZE);
  printf("After merge sort:\n");
  printArray(copy_points, SIZE);
  return 0;
}