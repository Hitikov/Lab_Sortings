#pragma once
#include <vector>
#include "QuickSort.h"

using namespace std;

void BucketSort(vector<int>& vect) {
	if (vect.size() < 2) {
		return;
	}

	int mx_value = vect[0];
	int mn_value = vect[0];

	for (int i = 1; i < vect.size(); ++i) {
		if (mx_value < vect[i]) {
			mx_value = vect[i];
		}
		else if (mn_value > vect[i])
		{
			mn_value = vect[i];
		}
	}

	int diff_step = 10;

	int bucketsCount = (int)((mx_value - mn_value)/diff_step) + 1;
	vector<int>* buckets = new vector<int>[bucketsCount] {};

	for (int i = 0; i < vect.size(); ++i) {
		buckets[vect[i] / 10 - mn_value / 10].push_back(vect[i]);
	}

	for (int i = 0; i < bucketsCount; ++i) {
		QuickSort(buckets[i]);
	}

	int index = 0;
	for (int i = 0; i < bucketsCount; ++i) {
		for (int j = 0; j < buckets[i].size(); ++j) {
			vect[index++] = buckets[i][j];
		}
	}

	delete[] buckets;
}