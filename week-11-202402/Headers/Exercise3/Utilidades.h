#pragma once
#include "iostream"
#include "vector"

using namespace System::Drawing;
using namespace std;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}