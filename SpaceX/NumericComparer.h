#pragma once
#include "dllexport.h"

namespace SpaceX
{
	// Comparing simple numeric types like int, float, double.
	// Using static methods.
	// For this case use only for float numbers.
	// From The art of computer programming by Knuth.
	class SpaceX_ExportDll NumericComparer
	{
	public:
		NumericComparer() = delete;
		~NumericComparer() = delete;

		// Checking absolute difference of two numbers 
		// within epsilon multiplied by the maximum value.
		static bool IsEqual(float a, float b, float epsilon = 1e-7);
		
		// Check if a is greater than b 
		// within epsilon multiplied by the maximum value.
		static bool IsGreater(float a, float b, float epsilon = 1e-7);
		
		// The same as above method
		// but swap a and b numbers
		static bool IsLess(float a, float b, float epsilon = 1e-7);
	};
}