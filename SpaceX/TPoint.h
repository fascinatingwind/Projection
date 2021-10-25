#pragma once
#include "dllexport.h"

namespace SpaceX
{
	template<class T>
	class SpaceX_ExportDll TPoint
	{
	public:
		TPoint() = default;
		~TPoint() = default;

		explicit TPoint(T x, T y, T z) :m_x (x), m_y(y), m_z(z){}

	private:
		T m_x;
		T m_y;
		T m_z;
	};
}