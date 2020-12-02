/*
 * Author: Prescott J. Traversi
 *
 * Standard binary search on a sorted array.
 */

#include "binary_search.h"

int BinarySearch(int x, int arr[], int n) {
  int low, mid, high;
  low = 0;
  high = n - 1;
  
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] > x)
      high = mid - 1;
    else if (arr[mid] < x)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
