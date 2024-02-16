#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quickSort(int arr[], int l, int r);
int *createRandomArray(int size);
double time_insertion_sort(int size);
double time_merge_sort(int size);
double time_quick_sort(int size);
void printArray(int arr[], int n);

int main()
{
  srand(time(NULL));

  // Size of arrays for the initial tests
  // int size = 2000000;   // roughly max (in millions) that ubuntu machine is handling for some reason.
  int size = 2147483647;   // works on insertion, doesn't on the other ones interestingly

  // Single Runs:
  printf("Insertion Sort: %.6f seconds\n", time_insertion_sort(size));
  printf("Merge Sort: %.6f seconds\n", time_merge_sort(size));
  printf("Quick Sort: %.6f seconds\n", time_quick_sort(size));

  // Multiple Runs for Mean:
  // double insert_total = 0;
  // double merge_total = 0;
  // double quick_total = 0;
  // for(int i=0; i<20; i++)
  // {
  //   // insert_total += time_insertion_sort(size);
  //   // printf("insertion: %d\n", i);
  //   merge_total += time_merge_sort(size);
  //   printf("merge: %d\n", i);
  //   quick_total += time_quick_sort(size);
  //   printf("quick: %d\n", i);
  // }

  // printf("Insertion Sort [MEAN]: %.6f seconds\n", insert_total/20);
  // printf("Merge Sort [MEAN]: %.6f seconds\n", merge_total/20);
  // printf("Quick Sort [MEAN]: %.6f seconds\n", quick_total/20);

  return 0;
}

double time_merge_sort(int size)
{
  int *randomArray = createRandomArray(size);

  clock_t start_time = clock();
  mergeSort(randomArray, 0, size - 1);
  clock_t end_time = clock();

  // printArray(randomArray, 25);   // check things are being sorted properly

  // Free memory allocated for array
  free(randomArray);

  // Calculate time difference in seconds
  return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

double time_quick_sort(int size)
{
  int *randomArray = createRandomArray(size);

  clock_t start_time = clock();
  quickSort(randomArray, 0, size - 1);
  clock_t end_time = clock();

  // printArray(randomArray, 25);   // check things are being sorted properly

  // Free memory allocated for array
  free(randomArray);

  // Calculate time difference in seconds
  return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

double time_insertion_sort(int size)
{
  int *randomArray = createRandomArray(size);

  clock_t start_time = clock();
  insertionSort(randomArray, size);
  clock_t end_time = clock();

  // Free memory allocated for array
  free(randomArray);

  // Calculate time difference in seconds
  return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

int *createRandomArray(int size)
{
  // printf("Creating random array of size: %d\n", size);
  int *randomArray = (int *)malloc(size * sizeof(int));
  if (randomArray == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // printf("-------------------------------------------------\n");
  // printf("Created random array of size: %d\n", size);
  // printf("Array is at memory address: %p\n", &size);
  // printf("Array is taking up %.4f GB of memory\n", (double)size * sizeof(int) / 1000000000);
  // printf("\n-------------------------------------------------\n");

  // printf("Filling array with random integers\n");
  for (int i = 0; i < size; i++)
  {
    randomArray[i] = rand(); // Fill with random integers
    if ((i + 1) % (size / 10) == 0)
    {
      // printf("Filled %.0f%% of array\n", (double)(i + 1) / size * 100);
    }
  }

  return randomArray;
}

void insertionSort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    // printf(":: %d / %d ::\n", i, n);
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

int partition(int arr[], int l, int r)
{
  int pivot = arr[r];
  int i = (l - 1);

  for (int j = l; j <= r - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi - 1);
    quickSort(arr, pi + 1, r);
  }
}

void printArray(int arr[], int n)
{
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
    if (i < n - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}
