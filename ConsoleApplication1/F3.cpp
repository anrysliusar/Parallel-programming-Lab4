#include "F3.h"
using namespace std;

F3::F3(Data data){
	this->data = data;
}

void F3::run()
{
	cout << "F3 started\n";
	//F3: S = (O + P) * TRANS(MR * MT)

	int* O = data.getVectorFilledWithValue(1);
	int* P = data.getVectorFilledWithValue(1);
	int** MT = data.getMatrixFilledWithValue(1);
	int** MR = data.getMatrixFilledWithValue(1);
	
	int* result = data.F3(O, P, MR, MT);
	
	data.print(result);

	cout << "F3 has finished\n";

	delete O;
	delete P;
	delete MT;
	delete MR;
}

