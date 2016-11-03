//homework_5_5

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

typedef void (*Func)(int*, size_t);

void sort(int array[], size_t SIZE) {
  std::sort(array, array + SIZE);
}

void insertionSort(int array[], size_t SIZE) {
  for (size_t j = 1; j < SIZE; ++j) {
    int key = array[j];
    int k = j - 1;
    while (key < array[k] && k >= 0) {
      int temp = array[k];
      array[k] = key;
      array[k + 1] = temp;
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

void mergeSortMod(int array[], size_t SIZE) {
  if (SIZE < 16) {
    insertionSort(array, SIZE);
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

void generate(int array[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    array[i] = rand();
  }
}

void copyArray(int array[], int copy[], size_t SIZE) {
  for (size_t i = 0; i < SIZE; ++i) {
    copy[i] = array[i];
  }
}

int main(int argc, char** argv) {
  Func ptr[] = {insertionSort, mergeSort, mergeSortMod, sort};
  size_t func_size = sizeof(ptr) / sizeof(ptr[0]);
  printf("Size\tInsertion\tMerge\t\tMerge*\t\tstd::sort\n");
  
  double seconds = (double) NULL;
  clock_t time1 = clock();
  
  while (seconds < 5.0) {
    srand(GetTickCount() + rand());
    size_t SIZE = rand() + 10000;
    printf("%u", SIZE);
    
    int array[SIZE], copy[SIZE];
    generate(array, SIZE);
    
    for (size_t i = 0; i < func_size; ++i) {
      copyArray(array, copy, SIZE);
      clock_t start = clock();
      ptr[i](copy, SIZE);
      clock_t elapsed = clock() - start;
      printf("\t%-10.3f", ((double) elapsed / CLOCKS_PER_SEC));
      
    }
    printf("\n");
    
    clock_t time2 = clock() - time1;
    seconds = (double) time2 / CLOCKS_PER_SEC;
  }
  return 0;
}