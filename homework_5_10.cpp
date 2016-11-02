// homework_5_10
// template char, int, double, Point

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

struct Point {
  int x, y, z;
};

int distance(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}

bool operator < (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) < distance(right, zero);
}

bool operator > (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) > distance(right, zero);
}

bool operator <= (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) <= distance(right, zero);
}

bool operator >= (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) >= distance(right, zero);
}

bool operator == (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) == distance(right, zero);
}

bool operator != (Point left, Point right) {
  Point zero = {0, 0, 0};
  return distance(left, zero) != distance(right, zero);
}

template<typename T>
void insertionSort (T array[], size_t SIZE) {
  for (size_t j = 1; j < SIZE; ++j) {
    T key = array[j];
    int k = j - 1;
    while (key < array[k] && k >= 0) {
      T temp = array[k];
      array[k] = key;
      array[k + 1] = temp;
      --k;
    }
  }
}

template<typename T>
int binarySearch(T array[], size_t SIZE, T x) {
  size_t first = 0;
  size_t last = SIZE;
  if (SIZE == 0) {
    return -1; 
  } else if (x < array[first]) {
    return -1;
  } else if (x > array[SIZE - 1]) {
    return -1;
  } else if (x == array[first]) {
    return first;
  } else if (x == array[SIZE - 1]) {
    return SIZE - 1;
  }
  
  while (first < last) {
    size_t mid = first + (last - first) / 2;
    if (x <= array[mid]) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }
  
  //return (array[last] == x) ? last : -1; 
  if (array[last] == x) {
    return last;
  } else {
    return -1;
  }
}

void print(char* letter) {
  printf("%c", *letter);
}

void print(int* value) {
  printf("%i", *value);
}

void print(double* value) {
  printf("%0.2f", *value);
}

void print(Point* point) {
  printf("(%i, %i, %i)", point->x, point->y, point->z);
}


template<typename T>
void printArray (T array[], size_t SIZE) {
  const char* delimiter = "array = [";
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s", delimiter);
    print(&array[i]);
    delimiter = ", ";
  }
  printf("]\n");
}

void generatePoint(Point points_array[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    points_array[i].x = -100 + rand() % 200;
    points_array[i].y = -100 + rand() % 200;
    points_array[i].z = -100 + rand() % 200;
  }
}

int main(int argc, char** argv) {
  const size_t SIZE = 10;
  
  char chars[] = {'m', 'a', 't', 'h', 'e', 'm', 'a', 't', 'i', 'x'};
  char letter = 'x';
  insertionSort<char>(chars, SIZE);
  printArray<char>(chars, SIZE);
  printf("Searching letter = '%c'\nInteger = %i\n\n", letter, binarySearch<char>(chars, SIZE, letter));
  
  int ints[] = {-10, -33, 2, 0, 6, 51, 19, 6, 11, -12};
  int value = 6;
  insertionSort<int>(ints, SIZE);
  printArray<int>(ints, SIZE);
  printf("Searching value = %i\nInteger = %i\n\n", value, binarySearch<int>(ints, SIZE, value));
  
  double doubles[] = {3.14, -0.05, 2.71, 7.71, 0.01, -0.06, 8.09, 10.0, 0.0, 2.71};
  double d_value = 2.71;
  insertionSort<double>(doubles, SIZE);
  printArray<double>(doubles, SIZE);
  printf("Searching value = %0.2f\nInteger = %i\n\n", d_value, binarySearch<double>(doubles, SIZE, d_value));
  
  Point points[] = {{91, 14, 10}, {-11, -54, 54}, {0, -11, 3}, {41, 93, 40}, {-14, 94, 10}, {67, -1, 0}, {1, -1, 66}, {-74, -5, -5}, {23, 9, -4}, {-14, 10, 94}};
  Point point = {-14, 94, 10};
  insertionSort<Point>(points, SIZE);
  printArray<Point>(points, SIZE);
  printf("Searching point(%i, %i, %i)\nInteger = %i\n\n", point.x, point.y, point.z, binarySearch<Point>(points, SIZE, point));
  
  return 0;
}