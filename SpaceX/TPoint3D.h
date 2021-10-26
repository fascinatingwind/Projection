#pragma once
#include "dllexport.h"

#include "NumericComparer.h"

namespace SpaceX
{
	template<class T>
	class SpaceX_ExportDll TPoint3D
	{
	public:
		TPoint3D() = default;
		~TPoint3D() = default;

		explicit TPoint3D(T x, T y, T z) : m_x (x), m_y(y), m_z(z){}

		std::array<T, 3> GetArray() const
		{
			return { m_x, m_y, m_z };
		}

		T GetX() const
		{
			return m_x;
		}

		T GetY() const
		{
			return m_y;
		}

		T GetZ() const
		{
			return m_z;
		}

	protected:
		T m_x;
		T m_y;
		T m_z;
	};
}