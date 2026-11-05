#pragma once
#include<vector>

#include"Vector.h"
#include"Ray.h"

namespace WCRT {
	void writeColor(std::vector<unsigned char>& buffer,const Color& pixelColor,int index);
	Color rayColor(const Ray& r);
}
