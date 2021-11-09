#pragma once
#include <random>


class Data {
private:
	int N;
public:
	Data();
	Data(int N);
	int getSize();
	void setSize(int N);
	int* getVectorFilledWithValue(int value);
	int** getMatrixFilledWithValue(int value);
	int** multiplyMatrices(int** firstMatrix, int** secondMatrix);
	int* vectorMultiplyByMatrix(int* vector, int** matrix);
	int* addVectors(int* firstVector, int* secondVector);
	int** transposeMatrix(int** matrix);
	int* F1(int a[], int c[], int** ma, int** me, int* b);
	int** F2(int** mk, int** mh, int** mf);
	int* F3(int* o, int* p, int** mr, int** mt);
	void print(int** matrix);
	void print(int* vector);
};