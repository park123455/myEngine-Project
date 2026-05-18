#include "GameObject.h"
#include "Input.h"
#include "Time.h"

namespace k
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{

	}



	void GameObject::Update()
	{
		const int speed = 100.0f;

		if (Input::GetKey(keyCode::A))
		{
			posX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(keyCode::D))
		{
			posX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(keyCode::W))
		{
			posY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(keyCode::S))
		{
			posY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + posX, 100 + posY, 200 + posX, 200 + posY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}


}

	