#pragma once
#include "dllexport.h"

#include "NumericComparer.h"

namespace SpaceX
{
	template<class T>
	class SpaceX_ExportDll TPoint
	{
	public:
		TPoint() = default;
		~TPoint() = default;

		explicit TPoint(T x, T y, T z) : m_x (x), m_y(y), m_z(z){}

		TPoint& operator+=(const TPoint& other)
		{
			m_x += other.m_x;
			m_y += other.m_y;
			m_z += other.m_z;
			
			return this;
		}

		TPoint operator+(const TPoint& other)
		{
			return { m_x + other.m_x, m_y + other.m_y, m_z + other.m_z };
		}

	protected:
		T m_x;
		T m_y;
		T m_z;
	};
}