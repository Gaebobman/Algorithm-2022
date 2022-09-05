#include <stdio.h>

void printArray(int* _array, int _len) {
	for (int i = 0; i < _len; i++) {
		printf("%d ", _array[i]);
	}
	printf("\n");
}

void swapArray(int* _arrayA, int* _arrayB) {
	int tmp, len = 0;
	while (len < 4) {
		tmp = _arrayA[len];
		_arrayA[len] = _arrayB[len];
		_arrayB[len] = tmp;
		len++;
	}
}


void main(void) {
	int arrayA[4] = { 1, 2, 3, 4 };
	int arrayB[4] = { 11,22,33,44 };
	int* pA = arrayA;
	int* pB = arrayB;
	printArray(pA, 4);
	printArray(pB, 4);
	swapArray(pA, pB);
	printArray(pA, 4);
	printArray(pB, 4);
}
