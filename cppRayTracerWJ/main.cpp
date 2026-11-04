// cppRayTracerWJ.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include<vector>
#include<stb_image_write.h>

#include"Vector.h"

int main()
{
	int imageWidth = 256;
	int imageHeight = 256;

	std::vector<unsigned char> buffer(imageHeight * imageWidth * 3);

	for (int i = 0;i < imageHeight;++i)
	{
		for (int j = 0;j < imageWidth;++j)
		{
			auto r = double(j) / (imageWidth - 1);
			auto g = double(i) / (imageHeight - 1);
			auto b = 0.0;
			int index = (i * imageWidth + j) * 3;
			buffer[index + 0] = int(255.999 * r);
			buffer[index + 1] = int(255.999 * g);
			buffer[index + 2] = int(255.999 * b);
		}
	}
	stbi_write_jpg("image.png", imageWidth, imageHeight, 3, buffer.data(), 0);
}
