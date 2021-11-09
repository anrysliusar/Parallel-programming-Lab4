#include "F2.h"
using namespace std;


F2::F2(Data data){
	this->data = data;
}

void F2::run()
{
	cout << "F2 started\n";
	//F2: MG = TRANS(MK) * (MH * MF)

	int** MK = data.getMatrixFilledWithValue(1);
	int** MH = data.getMatrixFilledWithValue(1);
	int** MF = data.getMatrixFilledWithValue(1);

	int** result = data.F2(MK, MH, MF);

	data.print(result);

	cout << "F2 has finished\n";

	delete MK;
	delete MH;
	delete MF;
}
