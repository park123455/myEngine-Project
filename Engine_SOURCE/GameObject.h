#pragma once
#include "CommonInclude.h"

namespace k
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			posX = x;
			posY = y;
		}

		float GetPositionX()
		{
			return posX;
		}
		float GetPositionY()
		{
			return posY;
		}

	private:
		float posX;
		float posY;
	};
}



