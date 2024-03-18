#pragma once
#include <vector>

using namespace std;

void HoarSort(vector<int>& vect, int beginIndex, int endIndex) {
	int leftIndex = beginIndex;
	int rightIndex = endIndex;
	int pivot = vect[(beginIndex + endIndex) / 2];

	do {
		while ((vect[leftIndex] < pivot) && (leftIndex < endIndex)) {
			++leftIndex;
		}
		while ((vect[rightIndex] > pivot) && (rightIndex > beginIndex)) {
			--rightIndex;
		}
		if (leftIndex <= rightIndex) {
			swap(vect[leftIndex++], vect[rightIndex--]);
		}
	} while (leftIndex <= rightIndex);

	if (rightIndex > beginIndex) {
		HoarSort(vect, beginIndex, rightIndex);
	}

	if (leftIndex < endIndex) {
		HoarSort(vect, leftIndex, endIndex);
	}
}

void HoarSort(vector<int>& vect) {
	if (vect.size() > 1) {
		HoarSort(vect, 0, vect.size() - 1);
	}
}