// cppRayTracerWJ.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include"Vector.h"

int main()
{
	WCRT::Vector3 v(1.0,2.0,3.0);

	std::cout << v.x() << "\n";
	std::cout << v.sqrLength() << "\n";
	std::cout << v.length() << "\n";
	std::cout << v[1] << "\n";

}
