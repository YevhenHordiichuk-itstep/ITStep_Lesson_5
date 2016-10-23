// homework_5_01, merge sort descending

#include <cstdio>
#include <algorithm>
#include <ctime>

bool comp(int a, int b) {
  return a > b;
}

void merge(int left[], int right[], size_t left_size, size_t right_size, int output[]) {  
  size_t l = 0, r = 0, k = 0;
  while (l < left_size && r < right_size) {
    if (left[l] >= right[r]) {
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
  if (SIZE < 2) {
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

void arrayCopy(int array[], int copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = array[i];
  }
}

void print(int array[], size_t SIZE) {
  const char* delimiter = "";
  printf("array = [");
  for (size_t i = 0; i < SIZE; ++i) {
    printf("%s%i", delimiter, array[i]);
    delimiter = ", ";
  }
  printf("]\n");
}

void generate(int array[], size_t SIZE) {
  srand(time(0));
  for (size_t i = 0; i < SIZE; ++i) {
    array[i] = rand();
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
    srand(time(0));
    size_t SIZE = rand() + 1;
    int array[SIZE], copy[SIZE];
    generate(array, SIZE);
    arrayCopy(array, copy, SIZE);
    
    mergeSort(array, SIZE);
    std::sort(copy, copy + SIZE, comp);
    
    if (compare(array, copy, SIZE)) {
      printf("OK\n");
    } else {
      printf("Error! %i\n", SIZE);
      print(array, SIZE);
      print(copy, SIZE);
      break;
    }
  }
  return 0;
}