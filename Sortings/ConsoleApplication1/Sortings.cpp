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
		{ 34, 55, 19, 87, 43, 4343, 73, -95, 49, 32, 100 },
		{ 34, 55, 19, 87, 43, 4343, 73, -95, 49, 32, 100 },
		{ 1, 4, 1, 3, 4, 4, 6, 4, 2, 2, 4, 3, 1, 5, 6, 3, 3, 2 },
		{ 1, 4, 1, 3, 4, 4, 6, 4, 2, 2, 4, 3, 1, 5, 6, 3, 3, 2 },
		{ 34, 55, 19, 87, 43, 433, 89, 45},
		{ 34, 55, 19, 87, 43, 433, 89, 45},
	};


	int vect_index = 0;
	for (ptr i : func_sort_ptr) {
		i(vect[vect_index]);
		PrintVector(vect[vect_index++]);
	}

	return 0;
}