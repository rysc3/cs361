#include <stdio.h>

int *insertionSort(int *in, int n) {
  for (int i = 1; i < n; i++) {
    int key = in[i];
    int j = i - 1;
    while (j >= 0 && in[j] > key) {
      in[j + 1] = in[j];
      j = j - 1;
    }
    in[j + 1] = key;
  }
  return in;
}

void testInsertionSort(int *in, int size) {
  int *sort1;
  sort1 = insertionSort(in, size);
  printf("Array before sorting: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", in[i]);
  }
  printf("\n");

  printf("Array after sorting: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", sort1[i]);
  }
  printf("\n");
}

int main() {
  int arr1[] = {10, 198, 15, 78, 88, 61, 0, 17, 9};
  int arr2[] = {68, 28, 10, 84, 74, 45, 41, 2, 31, 85, 43, 26, 45, 61, 4, 74, 22, 54, 74, 15, 47, 58, 58, 18, 61, 100, 89};
  int arr3[] = {75, 51, 44, 86};
  int arr4[] = {78, 37, 3, 14, 83, 32, 30, 73, 5, 81, 37, 69, 95};
  int arr5[] = {27, 37, 49, 5, 45, 63, 51, 68, 5, 18, 84, 87, 40, 55, 58, 100, 90, 2, 61, 1, 89, 73, 60, 5, 92, 54, 32, 73, 36, 86, 10, 44, 82, 99, 67, 85, 14, 95, 32, 76, 47, 87, 48, 47, 75, 69};

  // test everything
  testInsertionSort(arr1, sizeof(arr1) / sizeof(arr1[0]));
  testInsertionSort(arr2, sizeof(arr2) / sizeof(arr2[0]));
  testInsertionSort(arr3, sizeof(arr3) / sizeof(arr3[0]));
  testInsertionSort(arr4, sizeof(arr4) / sizeof(arr4[0]));
  testInsertionSort(arr5, sizeof(arr5) / sizeof(arr5[0]));

  return 0;
}
