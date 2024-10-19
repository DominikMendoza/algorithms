#pragma once
#include "iostream"
#include "vector"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

int RandInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

float RandFloat(float min, float max)
{
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
}