// homework_5_11 + test
// template char, int, double, Point

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h>

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
    return false; 
  } else if (x < array[first]) {
    return false;
  } else if (x > array[SIZE - 1]) {
    return false;
  } else if (x == array[first]) {
    return true;
  } else if (x == array[SIZE - 1]) {
    return true;
  }
  
  while (first < last) {
    size_t mid = first + (last - first) / 2;
    if (x <= array[mid]) {
      last = mid;
    } else {
      first = mid + 1;
    }
  }
   
  return array[last] == x;
}

void generate(double* value) {
  *value = -100 + rand() % 200 + rand() / RAND_MAX;
}
void generate(int* value) {
  *value = -100 + rand() % 200;
}
void generate(char* letter) {
  *letter = (char)97 + rand() % 26;
}
void generate(Point* points) {
  points->x = rand();
  points->y = rand();
  points->z = rand();

}
template<typename T>
void generateArray(T array[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    generate(&array[i]);
  }
  insertionSort(array, SIZE);
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

template<typename T>
void copyArray(T array[], T copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = array[i];
  }
}

int main(int argc, char** argv) {
  while (true) {
    srand(GetTickCount() + rand());
    const size_t SIZE = rand() % 100;
    
    char chars[SIZE];
    char copy_c[SIZE];
    char letter;
    generate(&letter);
    generateArray(chars, SIZE);
    copyArray(chars, copy_c, SIZE);
    
    int ints[SIZE];
    int copy_i[SIZE];
    int x1;
    generate(&x1);
    generateArray(ints, SIZE);
    copyArray(ints, copy_i, SIZE);
    
    double doubles[SIZE];
    double copy_d[SIZE];
    double x2;
    generate(&x2);
    generateArray(doubles, SIZE);
    copyArray(doubles, copy_d, SIZE);
    
    Point points[SIZE];
    Point copy_po[SIZE];
    Point x3;
    generate(&x3);
    generateArray(points, SIZE);
    copyArray(points, copy_po, SIZE);
    
    if (binarySearch(chars, SIZE, letter) == std::binary_search(copy_c, copy_c + SIZE, letter) &&
    binarySearch(ints, SIZE, x1) == std::binary_search(copy_i, copy_i + SIZE, x1) &&
    binarySearch(doubles, SIZE, x2) == std::binary_search(copy_d, copy_d + SIZE, x2) &&
    binarySearch(points, SIZE, x3) == std::binary_search(copy_po, copy_po + SIZE, x3)) {
      printf("OK\n");
    } else {
      printf("\aError\n");
    }
  }
  return 0;
}