#pragma once

#include"Vector.h"

namespace WCRT {
	class Ray
	{
	public:
		Ray(){}
		Ray(const Point3& iOrigin, const Vector3& iDriection) :origin(iOrigin), direction(iDriection) {}
		const Point3& getOrigin()const
		{
			return origin;
		}
		const Vector3& getDirection()const
		{
			return direction;
		}
		Point3 at(float t)
		{
			return origin + t * direction;
		}
	private:
		Point3 origin;
		Vector3 direction;
	};
}