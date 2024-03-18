#pragma once
#include <vector>

using namespace std;


void Merge(vector<int>& vect, int beginIndex, int endIndex) {
	int leftIndex = beginIndex;
	int middleIndex = (beginIndex + endIndex) / 2;
	int	rightIndex = middleIndex + 1;
	int mergeArrLenght = endIndex - beginIndex + 1;

	int* merge_arr = new int[endIndex - beginIndex + 1];

	for (int i = 0; i < mergeArrLenght; ++i) {
		if ((leftIndex <= middleIndex) &&
			((rightIndex > endIndex) || (vect[leftIndex] < vect[rightIndex]))) {
			merge_arr[i] = vect[leftIndex++];
		}
		else {
			merge_arr[i] = vect[rightIndex++];
		}
	}

	for (int i = 0; i < mergeArrLenght; ++i) {
		vect[i + beginIndex] = merge_arr[i];
	}
	delete[] merge_arr;
}

void Divide(vector<int>& vect, int beginIndex, int endIndex) {
	if (beginIndex < endIndex) {
		Divide(vect, beginIndex, (endIndex + beginIndex) / 2);
		Divide(vect, (endIndex + beginIndex) / 2 + 1, endIndex);
		Merge(vect, beginIndex, endIndex);
	}
}

void MergeSort(vector<int>& vect) {
	if (vect.size() > 1) {
		Divide(vect, 0, vect.size() - 1);
	}
}