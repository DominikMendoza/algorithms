#pragma once
#include "iostream"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}