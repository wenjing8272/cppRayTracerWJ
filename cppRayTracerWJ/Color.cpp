#include"Color.h"
#include<iostream>

namespace WCRT {
	void writeColor(std::vector<unsigned char>& buffer,const Color& pixelColor,const int index)
	{
		buffer[index + 0] = int(pixelColor.x() * 255.999);
		buffer[index + 1] = int(pixelColor.y() * 255.999);
		buffer[index + 2] = int(pixelColor.z() * 255.999);
	}
	Color rayColor(const Ray& r)
	{
		float a = 0.5f * (r.getDirection().y() + 1.0f);
		return (1.0f - a) * Color{ 1.0f,1.0f,1.0f } + a * Color { 0.5f, 0.7f, 1.0f };
	}
}