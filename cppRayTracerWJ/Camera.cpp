#include"Camera.h"
#include"Color.h"
#include"Ray.h"

#include<iostream>
#include<vector>
#include<stb_image_write.h>

namespace WCRT {
	Camera::Camera(float iAspectRatio, int iImageHeight,int iViewportHeight) :imageAspectRatio(iAspectRatio), imageHeight(iImageHeight),viewportHeight(iViewportHeight)
	{
		imageWidth = iAspectRatio * iImageHeight;
		viewportWidth = static_cast<int>(viewportHeight * static_cast<float>(imageWidth / imageHeight));
		std::cout << "camera" << std::endl;
	}
	void Camera::render()
	{
		std::vector<unsigned char> buffer(imageHeight * imageWidth * 3);
		for (int i = 0;i < imageHeight;++i)
		{
			std::clog << "\rScanlines remaining: " << (imageHeight - i) << ' ' << std::flush;
			for (int j = 0;j < imageWidth;++j)
			{
				Vector3 pixelCenter = pixel00 + 0.5f * (i * deltaV + j * deltaU);
				Vector3 rayDirection = pixelCenter - cameraCenter;
				normalize(rayDirection);
				Ray r{ cameraCenter,rayDirection };
				auto color = rayColor(r);
				writeColor(buffer, color, (i * imageWidth + j) * 3);
			}
		}
		stbi_write_jpg("image.jpg", imageWidth, imageHeight, 3, buffer.data(), 0);
	}
}