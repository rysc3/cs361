#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of times to run each sorting algorithm
int SIZE = 10;
int SIZE_LIMIT = 200000;
int NUM_ARRAYS = 1;

void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size);
int *createRandomArray(int *size);
void swap(int *a, int *b);
int partition(int arr[], int l, int r);
void quickSort(int arr[], int l, int r);
double calculateMeanTime();

int main()
{
  srand(time(NULL));

  // Arrays for calculating mean time
  int arrays[SIZE][SIZE];
  int size;
  createRandomArray(&size);

  for (int i = 0; i < SIZE; i++)
  {
    createRandomArray(&size); // Regenerate each time to ensure same size for all arrays
    for (int j = 0; j < size; j++)
    {
      arrays[i][j] = createRandomArray(&size)[j]; // fill with arrays
    }
  }

  // for (int i = 0; i < SIZE; i++)
  // {
  //   int size;
  //   int *randomArray = createRandomArray(&size);

  //   // Insertion Sort
  //   printf("------ Insertion Sort ------\n");
  //   printf("Generated array:\n");
  //   printArray(randomArray, size);
  //   printf("After:\n");
  //   insertionSort(randomArray, size);
  //   printArray(randomArray, size);
  //   printf("\n");

  //   free(randomArray);
  // }

  // for (int i=0; i<SIZE; i++)
  // {
  //   int size;
  //   int *randomArray = createRandomArray(&size);

  //   // Merge Sort
  //   printf("------ Merge Sort ------\n");
  //   printf("Generated array:\n");
  //   printArray(randomArray, size);
  //   mergeSort(randomArray, 0, size - 1);
  //   printf("After:\n");
  //   printArray(randomArray, size);
  //   printf("--------------------------\n\n");

  //   free(randomArray);
  // }

  // for (int i = 0; i < SIZE; i++)
  // {
  //   int size;
  //   int *randomArray = createRandomArray(&size);

  //   // Insertion Sort
  //   printf("------ Quick Sort ------\n");
  //   printf("Generated array:\n");
  //   printArray(randomArray, size);
  //   printf("After:\n");
  //   quickSort(randomArray, 0, size - 1);
  //   printArray(randomArray, size);
  //   printf("\n");

  //   free(randomArray);
  // }

  // Calculate mean time for insertion sort
  double insertion_mean_time = calculateMeanTime(insertionSort);
  printf("Insertion Mean time: %.6f seconds\n", insertion_mean_time);

  // Calculate mean time for merge sort
  double merge_mean_time = calculateMeanTime(mergeSort);
  printf("Merge Mean time: %.6f seconds\n", merge_mean_time);

  // Calculate mean time for quick sort
  double quick_mean_time = calculateMeanTime(quickSort);
  printf("Quick Mean time: %.6f seconds\n", quick_mean_time);

  return 0;
}

// Helpers

int *createRandomArray(int *size)
{
  *size = rand() % 20 + 1; // Random size between 1 and 20
  int *randomArray = (int *)malloc(*size * sizeof(int));
  if (randomArray == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < *size; i++)
  {
    randomArray[i] = rand() % 100; // Fill with completely random integers
  }

  return randomArray;
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/*
 * * * Sorting Stuff * * *
 */

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

double calculateMeanTime(void (*sortingFunction)(int arr[], int size)) {
    clock_t start, end;
    double total_time = 0.0;

    for (int i = 0; i < NUM_ARRAYS; i++) {
        // Generate random array
        int* arr = (int*)malloc(SIZE_LIMIT * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < SIZE_LIMIT; j++) {
            arr[j] = rand() % 1000;
        }

        // Measure time taken to sort the array
        start = clock();
        sortingFunction(arr, SIZE_LIMIT);
        end = clock();

        // Accumulate the time taken
        total_time += (double)(end - start) / CLOCKS_PER_SEC;

        // Free memory allocated for array
        free(arr);
    }

    // Calculate and return mean time
    return total_time / NUM_ARRAYS;
}