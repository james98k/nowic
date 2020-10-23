// quicksort.cpp by idebtor@gmail.com
// A typical recursive implementation of quicksort
// using a function pointer for comparison.
// 2018.12.15	created by idebtor@gmail.com
// 2020.10.18	randomize() added before sorting.

#include <iostream>
#include "sort.h"
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// This function takes last element as pivot, places the pivot element at its
// correct position in sorted array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right of pivot.
int partition(int list[], int lo, int hi, int(*comp)(int, int)) {
	int x = list[hi];  // pivot
	int i = (lo - 1);  // Index of smaller element

	for (int j = lo; j <= hi - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (comp(x, list[j]) > 0) {
			i++;    // increment index of smaller element
			std::swap(list[i], list[j]);  // Swap current element with index
		}
	}
	std::swap(list[i + 1], list[hi]);
	return (i + 1);
}

// quickSort helper function for recursive operation
// list[]: array to be sorted, lo: starting index, h: ending index
// N is added only for debugging or DPRINT
void quick_sort(int *list, int lo, int hi, int N, int(*comp)(int, int)) {
	if (lo < hi) 	{
		int pi = partition(list, lo, hi, comp); // Partitioning index
		DPRINT(for (int x = 0; x < N; x++) cout << list[x] << " "; cout << endl;);
		quick_sort(list, lo, pi - 1, N, comp);
		quick_sort(list, pi + 1, hi, N, comp);
	}
}

void quickSort(int *a, int n) {
	quick_sort(a, 0, n - 1, n, ascending);
}

void quickSort(int *a, int n, int(*comp)(int, int)) {
	quick_sort(a, 0, n - 1, n, comp);
}

#if 0
int main() {
	int list[] = { 7, 3, 4, 1, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	quickSort(list, N);
	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	quickSort(list, N, descending);
	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;
}
#endif
