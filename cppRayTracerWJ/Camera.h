#pragma once

#include"Vector.h"
#include"Color.h"

namespace WCRT {
	class Camera {
	public:
		Camera() = default;
		Camera(float iAspectRatio,int iImageHeight, int iViewportHeight);
		~Camera() = default;
		void render();
	public:
		float imageAspectRatio = 16.0f / 9.0f;
		int imageHeight = 1080;
		int imageWidth = static_cast<int>(imageAspectRatio * imageHeight);

		float focalLength = 1.0f;
		Point3 cameraCenter{ 0.0f,0.0f,0.0f };
		Vector3 viewportU{ static_cast<float>(imageWidth),0.0f,0.0f };
		Vector3 viewportV{ 0.0f,-static_cast<float>(imageHeight),0.0f };
		Vector3 deltaU = viewportU / imageWidth;
		Vector3 deltaV = viewportV / imageHeight;
		Vector3 viewportUpperLeft = cameraCenter - Vector3{ 0.0f,0.0f,focalLength } - viewportU / 2.0f - viewportV / 2.0f;
		Vector3 pixel00 = viewportUpperLeft + 0.5f * (deltaU + deltaV);
	private:
		int viewportWidth;
		int viewportHeight;
	};
}