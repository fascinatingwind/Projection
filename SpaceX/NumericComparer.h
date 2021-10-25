#pragma once
#include "dllexport.h"

namespace SpaceX
{
	class SpaceX_ExportDll NumericComparer
	{
	public:
		NumericComparer() = delete;
		~NumericComparer() = delete;

		static bool IsEqual(float a, float b, float epsilon = 1e-7);
		static bool IsGreater(float a, float b, float epsilon = 1e-7);
		static bool IsLess(float a, float b, float epsilon = 1e-7);
		
		static bool IsEqual(double a, double b, double epsilon = 1e-7);
		static bool IsGreater(double a, double b, double epsilon = 1e-7);
		static bool IsLess(double a, double b, double epsilon = 1e-7);

	private:
		template<class T>
		static bool approximatelyEqual(T a, T b, T epsilon = std::numeric_limits<T>().epsilon())
		{
			return std::abs(a - b) <= ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
		}

		template<class T>
		static bool essentiallyEqual(T a, T b, T epsilon = std::numeric_limits<T>().epsilon())
		{
			return std::abs(a - b) <= ((std::abs(a) > std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
		}

		template<class T>
		static bool definitelyGreaterThan(T a, T b, T epsilon = std::numeric_limits<T>().epsilon())
		{
			return (a - b) > ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
		}

		template<class T>
		static bool definitelyLessThan(T a, T b, T epsilon = std::numeric_limits<T>().epsilon())
		{
			return (b - a) > ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
		}
	};
}