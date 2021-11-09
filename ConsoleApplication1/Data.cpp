#include "Data.h"
#include <iostream>

using namespace std;


Data::Data(){
}

Data::Data(int N){
	this->N = N;
}

int Data::getSize(){
	return N;
}

void Data::setSize(int N)
{
	this->N = N;
}

int* Data::getVectorFilledWithValue(int value){
	int* vector = new int[N];
	for (int i = 0; i < N; i++) {
		vector[i] = value; //rand() % 30;
	}

	return vector;
}

int** Data::getMatrixFilledWithValue(int value){
	int** matrix = new int*[N];
	for (int i = 0; i < N; ++i)
		matrix[i] = new int[N];
	for (int i = 0; i < N; ++i)
		for (int k = 0; k < N; ++k)
			matrix[i][k] = value; //rand() % 30;
	return matrix;
}

int** Data::multiplyMatrices(int** firstMatrix, int** secondMatrix){
	int** resultMatrix = new int* [N];
	for (int i = 0; i < N; ++i)
		resultMatrix[i] = new int[N];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			resultMatrix[i][j] = 0;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}

	return resultMatrix;
}

int* Data::vectorMultiplyByMatrix(int* vector, int** matrix){
	int* result = new int[N];
	for (int i = 0; i < N; i++) {
		result[i] = 0;
		for (int j = 0; j < N; j++) {
			result[i] += vector[j] * matrix[i][j];
		}
	}
	return result;
}

int* Data::addVectors(int* firstVector, int* secondVector){
	int* result = new int[N];
	for (int i = 0; i < N; i++) {
		result[i] = firstVector[i] + secondVector[i];
	}
	return result;
}

int** Data::transposeMatrix(int** matrix){
	int** resultMatrix = new int* [N];
	for (int i = 0; i < N; ++i)
		resultMatrix[i] = new int[N];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			resultMatrix[i][j] = matrix[j][i];
	return matrix;
}

int* Data::F1(int a[], int c[], int** ma, int** me, int* b)
{
	return addVectors(addVectors(a, vectorMultiplyByMatrix(c,  multiplyMatrices(ma, me))), b);
}

int** Data::F2(int** mk, int** mh, int** mf)
{
	return multiplyMatrices(transposeMatrix(mk), multiplyMatrices(mh, mf));;
}

int* Data::F3(int* o, int* p, int** mr, int** mt)
{
	return vectorMultiplyByMatrix(addVectors(o, p), transposeMatrix(multiplyMatrices(mr, mt)));
 
}

void Data::print(int** matrix) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%i ", matrix[i][j]);;
		printf("\n");
	}
	printf("\n");
}

void Data::print(int* vector) {
	for (int i = 0; i < N; i++)
	{
		 printf("%i ", vector[i]);
	}
	printf("\n");

}
