#pragma once
#include "CommonInclude.h"
#include "GameObject.h"

namespace k
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND Handle); // 클래스 초기화
		void Run();

		void Update(); 
		void LateUpdate();
		void Render();

	private:
		HWND myApiHandle;
		HDC myHdc;

		HDC backHdc;
		HBITMAP backBuffer; // dc가 가진 도화지 1개(빈 그림파일)

		UINT screenWidth;
		UINT screenHeight;

		GameObject player;
	};
}



