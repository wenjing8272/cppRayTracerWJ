#pragma once
#include<cmath>

namespace WCRT{
	class Vector3 {
	public:
		float e[3];

	public:
		~Vector3() = default;
		Vector3() :e{ 0.0, 0.0, 0.0 } {}
		Vector3(float ix, float iy, float iz) :e{ ix,iy,iz } {}

		float x()const
		{
			return e[0];
		}
		float y()const
		{
			return e[1];
		}
		float z()const
		{
			return e[2];
		}
		Vector3 operator-()const {
			return Vector3(-e[1], -e[2], -e[3]);
		}
		const float& operator[](int i) const
		{
			return e[i];
		}
		float& operator[](int i)
		{
			return e[i];
		}
		Vector3& operator+=(const Vector3& vec)
		{
			this->e[0] += vec.x();
			this->e[1] += vec.y();
			this->e[2] += vec.z();
			return *this;
		}
		Vector3& operator*=(float v)
		{
			this->e[0] *= v;
			this->e[1] *= v;
			this->e[2] *= v;
			return *this;
		}
		Vector3& operator/=(float v)
		{
			return *this *= (1 / v);
		}
		float sqrLength()const
		{
			return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
		}
		float length()const
		{
			return std::sqrt(sqrLength());
		}
	};
	inline Vector3 operator+(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(v1.x() + v2.x(),
					   v1.y() + v2.y(),
					   v1.z() + v2.z());
	}
	inline Vector3 operator-(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(v1.x() - v2.x(),
					   v1.y() - v2.y(),
					   v1.z() - v2.z());
	}
	inline Vector3 operator*(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(v1.x() * v2.x(),
					   v1.y() * v2.y(),
					   v1.z() * v2.z());
	}
	inline Vector3 operator*(float value, const Vector3& v)
	{
		return Vector3(v.x() * value,
					   v.y() * value,
			           v.z() * value);
	}
	inline Vector3 operator*(const Vector3& v, float value)
	{
		return value * v;
	}
	inline Vector3 operator/(const Vector3& v, float value)
	{
		return (1 / value) * v;
	}
	inline void normalize(Vector3& vec3)
	{
		float length = vec3.length();
		vec3 /= (length + 0.00001);
	}
	inline float dotProduct(const Vector3& v1, const Vector3& v2)
	{
		return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
	}
	inline Vector3 crossProduct(const Vector3& v1, const Vector3& v2)
	{
		return Vector3(v1.y() * v2.z() - v1.z() * v2.y(),
					   v1.z() * v2.x() - v1.x() * v2.z(), 
					   v1.x() * v2.y() - v1.y() * v2.x());
	}

	using Color = Vector3;
	using Point3 = Vector3;
}