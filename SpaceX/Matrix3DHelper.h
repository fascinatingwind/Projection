#pragma once

#include "FMatrix3x3.h"
#include "FLine3D.h"

namespace SpaceX
{
	// Contain methods for matrix in 3d space
	class Matrix3DHelper
	{
	public:
		Matrix3DHelper() = delete;
		~Matrix3DHelper() = delete;

		// Return matrix representation of line in 3d space
		static FMatrix3x3 GetMatrixRepresentation(const FLine3D& line);

		// Return two non zero points from matrix in 3d space
		static std::array<FPoint3D, 2> Get2NonZeroRows(const FMatrix3x3& matrix);
	};
}