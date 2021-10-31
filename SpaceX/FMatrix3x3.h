#pragma once
#include "dllexport.h"

#include "FPoint3D.h"

namespace SpaceX
{
	// A 3-by-3 Matrix stores float numbers
	class SpaceX_ExportDll FMatrix3x3
	{
	public:

		explicit FMatrix3x3(
			const FPoint3D& row0, 
			const FPoint3D& row1, 
			const FPoint3D& row2);

		// Compare matrix equality.
		bool operator==(const FMatrix3x3& other) const;

		// Check if matrix row contains zero values.
		bool IsZeroRow(size_t row) const;

		// Return matrix row by index.
		FPoint3D GetRow(size_t row) const;

		// Return determinant of matrix.
		float Determinant() const;
		
		// Set row by index.
		void SetRow(const FPoint3D& point, size_t row);
		
		// Set column by index.
		void SetColumn(const FPoint3D& point, size_t column);
		
		// Return matrix dimension size.
		static size_t GetDimension();

	private :
		constexpr static size_t m_dimension = 3;
		std::array<std::array<float, m_dimension>, m_dimension> m_array;
	};
}