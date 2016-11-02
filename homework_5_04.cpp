//merge sort with SIZE < 16 insertion sort, +test

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <windows.h>

void insertionSort(int array[], size_t SIZE) {
  for (size_t j = 1; j < SIZE; ++j) {
    size_t k = j - 1;
    while (array[j] < array[k] && j != 0) {
      int temp = array[k];
      array[k] = array[j];
      array[k + 1] = temp;
      --j;
      --k;
    }
  }
}

void merge(int left[], int right[], size_t left_size, size_t right_size, int output[]) {
  size_t l = 0, r = 0, k = 0;
  while (l < left_size && r < right_size) {
    if (left[l] <= right[r]) {
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

void mergeSort(int array[], size_t SIZE) {
  if (SIZE <= 16) {
    insertionSort(array, SIZE);
    return;
  }
  
  size_t left_size = SIZE / 2;
  size_t right_size = SIZE - left_size;
  int left[left_size];
  int right[right_size];
  
  for (size_t i = 0; i < left_size; ++i) {
    left[i] = array[i];
  }
  for (size_t i = 0; i < right_size; ++i) {
    right[i] = array[i + left_size];
  }
  
  mergeSort(left, left_size);
  mergeSort(right, right_size);
  merge(left, right, left_size, right_size, array);
}

void generateArray(int array[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    array[i] = rand() % 1000;
  }
}

void printArray(int array[], size_t SIZE) {
  const char* delimiter = "array = (";
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s%i", delimiter, array[i]);
    delimiter = ", ";
  }
  printf(");\n");
}

void copyArray(int array[], int copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = array[i];
  }
}

bool compare(int array[], int copy[], size_t SIZE) {
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
    size_t SIZE = rand() % 99 + 1;
    int array[SIZE], copy[SIZE];
  
    generateArray(array, SIZE);
    copyArray(array, copy, SIZE);
    mergeSort(array, SIZE);
    std::sort(copy, copy + SIZE);
    if (compare(array, copy, SIZE)) {
      printf("OK\n");
    } else {
      printf("Error!\tcorn = %i\n", corn);
      printArray(array, SIZE);
      printArray(copy, SIZE);
      break;
    }
  }
  return 0;
}