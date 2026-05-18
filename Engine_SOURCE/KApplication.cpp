#include "KApplication.h"
#include "Input.h"
#include "Time.h"

namespace k
{
	Application::Application()
		: myApiHandle(nullptr)
		, myHdc(nullptr)
		, screenWidth(0)
		, screenHeight(0)
		, backHdc(NULL)
		, backBuffer(NULL)
	{

	}	
	Application::~Application()
	{

	}
	void Application::Initialize(HWND Handle)
	{
		myApiHandle = Handle; // 포인터 주소 복사
		myHdc = GetDC(myApiHandle);


		RECT rect = { 0,0, 1600, 900 };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		screenWidth = rect.right - rect.left;
		screenHeight = rect.bottom - rect.top;

		SetWindowPos(Handle, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(Handle, true);

		// 백버퍼 (도화지 1개) 더 생성
		backBuffer = CreateCompatibleBitmap(myHdc, 1600, 900);

		// 백퍼를 가리킬 dc
		backHdc = CreateCompatibleDC(myHdc);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(backHdc, backBuffer);
		DeleteObject(oldBitMap);


		player.SetPosition(0, 0);

		Input::Initialize();
		Time::Initialize();
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
		Time::Update();

		player.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		Rectangle(backHdc, 0, 0, 1600, 900);

		Time::Render(backHdc);
		player.Render(backHdc);

		// 백 버퍼에 그린것을 원본 버퍼에 복사(그려준다)
		BitBlt(myHdc, 0, 0, screenWidth, screenHeight, backHdc, 0, 0, SRCCOPY);
	}



}