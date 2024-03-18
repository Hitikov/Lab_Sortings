#pragma once
#include <vector>

using namespace std;


void CountingSort(vector<int>& vect) {
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

	int countArrLenght = mx_value - mn_value + 1;
	int* countArr = new int[countArrLenght] {};

	for (int i = 0; i < vect.size(); ++i) {
		countArr[vect[i] - mn_value]++;
	}

	int index = 0;
	for (int i = 0; i < countArrLenght; ++i) {
		for (int j = 0; j < countArr[i]; ++j) {
			vect[index++] = i + mn_value;
		}
	}

	delete[] countArr;

}