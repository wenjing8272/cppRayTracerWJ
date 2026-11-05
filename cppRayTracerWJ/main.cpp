// cppRayTracerWJ.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include<memory>

#include"Camera.h"

int main()
{
	auto cam = std::make_unique<WCRT::Camera>(16.0f / 9.0f, 1080, 9);
	cam->render();
}
