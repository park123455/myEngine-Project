#include "Time.h"


namespace k
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currFrequency = {};
	float Time::deltaTime;

	void Time::Initialize()
	{
		// 이 프로그램을 실행하는 cpu의 클럭에 따른 1초당 카운트하는 값.
		QueryPerformanceFrequency(&cpuFrequency);

		// 프로그램이 시작할때 처음 측정 순간의 카운트 값
		QueryPerformanceCounter(&prevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&currFrequency);

		// 1프레임(이전 업데이트 -> 다음 업데이트) 동안 카운트된 수
		float frequencyDF = static_cast<float>(currFrequency.QuadPart - prevFrequency.QuadPart);
		// 델타타임 = 프레임당 카운트 / 1초당 카운트 => 즉 각 컴터의 1프레임당 지나간 현실시간을 말한다.
		deltaTime = frequencyDF / static_cast<float>(cpuFrequency.QuadPart);
		prevFrequency.QuadPart = currFrequency.QuadPart;

	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += deltaTime;
		float fps = 1.0f / deltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %f", time);
		int length = wcsnlen_s(str, 50);

		

		TextOut(hdc, 0, 0, str, length);
	}
}