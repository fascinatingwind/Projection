#pragma once
#include "dllexport.h"

namespace SpaceX
{
	// Point in 3d space using float type
	struct SpaceX_ExportDll FPoint3D
	{
		float X;
		float Y;
		float Z;

		FPoint3D() = default;
		~FPoint3D() = default;
		
		// Initialize constructor.
		explicit FPoint3D(float x, float y, float z);

		// Comparing points.
		bool operator==(const FPoint3D& other) const;

		// Sum the values for each coordinates.
		FPoint3D& operator+=(const FPoint3D& other);

		// Return the coordinate sum of two points.
		FPoint3D operator+(const FPoint3D& other) const;

		// Return the coordinate difference of two points.
		FPoint3D operator-(const FPoint3D& other) const;
		
		// Return a negative point.
		FPoint3D operator-() const;
		
		// Return the product of the coordinates of two points.
		FPoint3D operator*(const FPoint3D& other) const;

		// Check if one point is less than another by coordinates.
		bool operator<(const FPoint3D& other) const;
		
		// Check if one point is greater than another by coordinates.
		bool operator>(const FPoint3D& other) const;

		// Return sum of coordinates
		float Sum() const;
	};
}