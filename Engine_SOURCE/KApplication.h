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

		GameObject player;
	};
}



