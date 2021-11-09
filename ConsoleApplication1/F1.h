#pragma once
#include <iostream>
#include <Windows.h>
#include "Data.h"

class F1 {
private:
	Data data;
public:
	F1(Data data);
	void run();
};
