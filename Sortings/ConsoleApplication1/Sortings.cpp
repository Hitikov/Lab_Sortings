#include <iostream>
#include <vector>

using namespace std;

#include "QuickSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "ShellSort.h"
#include "HoarSort.h"
#include "BucketSort.h"


void PrintVector(vector<int>& vect) {
	if (vect.size() > 0) {
		cout << vect[0];
	}
	for (int i = 1; i < vect.size(); i++) {
		cout << ' ' << vect[i];
	}
	cout << '\n';
}

typedef void(*ptr)(vector<int>&);

int main() {

	ptr func_sort_ptr[] = { &QuickSort, &MergeSort, &CountingSort, &BucketSort, &ShellSort, &HoarSort };
	vector<int> vect [] = {
		{ 34, 55, 19, 87, 43, 4343, 73, -95, 49, 32, 100, 87, 346, 12, 3, -76, -32, 89, 109, 41, 85, 293, 44, 21, 743, 202 },
		{ 34, 55, 19, 87, 43, 4343, 73, -95, 49, 32, 100, 87, 346, 12, 3, -76, -32, 89, 109, 41, 85, 293, 44, 21, 743, 202 },
		{ 1, 4, 1, 3, 4, 4, 6, 4, 2, 2, 4, 3, 1, 5, 6, 3, 3, 2, 5, 6, 1, 2, 2, 3, 4, 6, 4, 4, 5, 2, 1 },
		{ 1, 4, 1, 3, 4, 4, 6, 4, 2, 2, 4, 3, 1, 5, 6, 3, 3, 2, 5, 6, 1, 2, 2, 3, 4, 6, 4, 4, 5, 2, 1 },
		{ 34, -77, 55, 87, 99, 20, 83, 43, 33, 73, 89, 45, 32, 75, 2, 33, 19, 7, 23, 83, 54, 30, 49, 29, 4, 99, 30, 12},
		{ 34, -77, 55, 87, 99, 20, 83, 43, 33, 73, 89, 45, 32, 75, 2, 33, 19, 7, 23, 83, 54, 30, 49, 29, 4, 99, 30, 12},
	};


	int vect_index = 0;
	for (ptr i : func_sort_ptr) {
		i(vect[vect_index]);
		PrintVector(vect[vect_index++]);
	}

	return 0;
}