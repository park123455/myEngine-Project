#include "KApplication.h"
#include "Input.h"

namespace k
{
	Application::Application()
		: myApiHandle(nullptr)
		, myHdc(nullptr)
	{

	}	
	Application::~Application()
	{

	}
	void Application::Initialize(HWND Handle)
	{
		myApiHandle = Handle; // 포인터 주소 복사
		myHdc = GetDC(myApiHandle);

		player.SetPosition(0, 0);

		Input::Initialize();
	}



	void Application::Run()
	{
		Update(); // 여기서 데이터의 변화를 실시간으로 갱신
		LateUpdate();	
		Render(); // 여기서 위에서 갱신된 데이터를 바탕으로 다시 화면을 그리기
	}
	
	

	void Application::Update()
	{
		Input::Update();

		player.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		player.Render(myHdc);
	}



}