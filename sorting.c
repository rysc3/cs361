#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size);

int main()
{
  int arr1[] = {10, 198, 15, 78, 88, 61, 0, 17, 9};
  int arr2[] = {68, 28, 10, 84, 74, 45, 41, 2, 31, 85, 43, 26, 45, 61, 4, 74, 22, 54, 74, 15, 47, 58, 58, 18, 61, 100, 89};
  int arr3[] = {75, 51, 44, 86};
  int arr4[] = {78, 37, 3, 14, 83, 32, 30, 73, 5, 81, 37, 69, 95};
  int arr5[] = {27, 37, 49, 5, 45, 63, 51, 68, 5, 18, 84, 87, 40, 55, 58, 100, 90, 2, 61, 1, 89, 73, 60, 5, 92, 54, 32, 73, 36, 86, 10, 44, 82, 99, 67, 85, 14, 95, 32, 76, 47, 87, 48, 47, 75, 69};

  // insertion
  printf("------ Insertion Sort ------\n");
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  printf("Before:\n");
  printArray(arr1, size1);
  insertionSort(arr1, size1);
  printf("After:\n");
  printArray(arr1, size1);
  printf("\n");

  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  printf("Before:\n");
  printArray(arr2, size2);
  insertionSort(arr2, size2);
  printf("After:\n");
  printArray(arr2, size2);
  printf("\n");

  int size3 = sizeof(arr3) / sizeof(arr3[0]);
  printf("Before:\n");
  printArray(arr3, size3);
  insertionSort(arr3, size3);
  printf("After:\n");
  printArray(arr3, size3);
  printf("\n");

  int size4 = sizeof(arr4) / sizeof(arr4[0]);
  printf("Before:\n");
  printArray(arr4, size4);
  insertionSort(arr4, size4);
  printf("After:\n");
  printArray(arr4, size4);
  printf("\n");

  int size5 = sizeof(arr5) / sizeof(arr5[0]);
  printf("Before:\n");
  printArray(arr5, size5);
  insertionSort(arr5, size5);
  printf("After:\n");
  printArray(arr5, size5);
  printf("\n");
  printf("--------------------------\n");

  // merge
  printf("------ Merge Sort ------\n");
  mergeSort(arr1, 0, size1 - 1);
  printArray(arr1, size1);

  mergeSort(arr2, 0, size2 - 1);
  printArray(arr2, size2);

  mergeSort(arr3, 0, size3 - 1);
  printArray(arr3, size3);

  mergeSort(arr4, 0, size4 - 1);
  printArray(arr4, size4);

  mergeSort(arr5, 0, size5 - 1);
  printArray(arr5, size5);
  printf("--------------------------\n");

  return 0;
}

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
