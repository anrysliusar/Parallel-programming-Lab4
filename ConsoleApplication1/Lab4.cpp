#include <iostream>
#include "F1.h"
#include "F2.h"
#include "F3.h"
#include <omp.h>



/**
 * Parallel and distributed computing.
 * Labwork 4. OpenMP.
 *
 * Andrii Sliusarenko
 * IO-91
 * 11.11.2021
 *
 * F1: E = A + C * (MA * ME) + B
 * F2: MG = TRANS(MK) * (MH * MF)
 * F3: S = (O + P) * TRANS(MR * MT)
 */

int N = 5;

int main()
{
    std::cout << "Lab 4 started!\n";

	Data data;
	data.setSize(N);
	F1* T1 = new F1(data);
	F2* T2 = new F2(data);
	F3* T3 = new F3(data);

	int tid;
	#pragma omp parallel num_threads(3)
	{
		tid = omp_get_thread_num();
		switch (tid) {
		case 0:
			T1->run();
		case 1:
			T2->run();
		case 2:
			T3->run();
		}
	}

	std::cout << "Lab 4 has finished!\n";	
}