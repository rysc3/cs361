#include <stdio.h>

int *insertionSort(int *in, int n) {  // p.51
  for (int i = 1; i < n; i++) {   // index 2 -> n
    int key = in[i];
    // insert in[i] into the sorted sequence in[1..i-1]
    int j = i - 1;
    while (j >= 0 && in[j] > key) {
      in[j + 1] = in[j];
      j = j - 1;
    }
    in[j + 1] = key;
  }
  return in;
}


int main() {
  // Give test data
  int array1[] = {10, 198, 15, 78, 88, 61, 0, 17, 9};


  printf("Array before sorting: ");
  for(int i=0; i<sizeof(array1)/sizeof(array1[0]); i++){
    printf("%d ", array1[i]);
  }
  printf("\n");


  // Sort
  int *sort1;
  sort1 = insertionSort(array1, sizeof(array1) / sizeof(array1[0])); // Corrected size calculation


  // Print array
  printf("Array before sorting: ");
  for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++) {
    printf("%d ", sort1[i]);
  }
  printf("\n");


  return 0;
}