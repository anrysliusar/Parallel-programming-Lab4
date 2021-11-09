#include "F1.h"
using namespace std;



F1::F1(Data data){
	this->data = data;
}


void F1::run()
{
	cout << "F1 started\n";

	//F1: E = A + C * (MA * ME) + B

	int* A = data.getVectorFilledWithValue(1);
	int* C = data.getVectorFilledWithValue(1);
	int** MA = data.getMatrixFilledWithValue(1);
	int** ME = data.getMatrixFilledWithValue(1);
	int* B = data.getVectorFilledWithValue(1);

	
	int* result = data.F1(A, C, MA, ME, B);

	data.print(result);

	cout << "F1 has finished\n";
	delete A;
	delete C;
	delete MA;
	delete ME;
	delete B;

}

