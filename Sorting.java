public class Sorting {
  public static void main(String[] args) {
    // arrays to be sorted
    int[] arr1 = { 10, 198, 15, 78, 88, 61, 0, 17, 9 };
    int[] arr2 = { 68, 28, 10, 84, 74, 45, 41, 2, 31, 85, 43, 26, 45, 61, 4, 74, 22, 54, 74, 15, 47, 58, 58, 18, 61, 100, 89 };
    int[] arr3 = { 75, 51, 44, 86 };
    int[] arr4 = { 78, 37, 3, 14, 83, 32, 30, 73, 5, 81, 37, 69, 95 };
    int[] arr5 = { 27, 37, 49, 5, 45, 63, 51, 68, 5, 18, 84, 87, 40, 55, 58, 100, 90, 2, 61, 1, 89, 73, 60, 5, 92, 54, 32, 73, 36, 86, 10, 44, 82, 99, 67, 85, 14, 95, 32, 76, 47, 87, 48, 47, 75, 69 };

    testInsertionSort(arr1);
    testInsertionSort(arr2);
    testInsertionSort(arr3);
    testInsertionSort(arr4);
    testInsertionSort(arr5);
  }

  public static void testInsertionSort(int[] in) {
    System.out.print("Array before sorting: ");
    printArray(in);

    int[] sorted = insertionSort(in);
    System.out.print("\nArray after sorting: ");
    printArray(sorted);

    System.out.println();
    System.out.println();
  }

  public static int[] insertionSort(int[] in) {   // p.51
    int n = in.length;
    for (int i = 1; i < n; ++i) {   // index 2..n
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

  public static void printArray(int[] arr) {
    for (int i = 0; i < arr.length; ++i) {
      System.out.print(arr[i] + " ");
    }
  }
}
