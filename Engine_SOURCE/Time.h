#pragma once
#include "CommonInclude.h"


namespace k
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime()
		{
			return deltaTime;
		}

	private:
		static LARGE_INTEGER cpuFrequency; // LARGE_INTEGER 자료형은 long long 변수 2개치의 저장공간이다.
		// myCpuFrequency : 해당 컴퓨터 cpu의 고유의 클럭속도를 말한다.

		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currFrequency;
		static float deltaTime;
		// deltaTime은 각 컴퓨터의 1프레임당 지나간 현실시간을 말하는데, (60fbs면 1/60초), (240fbs면 1/240초)
		// 이 값을 시간에 따른 변화량 데이터에 곱하면 
		// 그 변화량 증감량을 컴퓨터 프레임에 맞게 보정해버린다.
		// 즉 좋은 컴퓨터일수록 1프레임당 변화량이 줄어들고,
		// 안좋은 컴퓨터일수록 1프레임당 변화량이 증가한다.
		// 이때 1프레임당 변화량이 화면에 그려질 경우,
		// 1.deltaTime을 적용 안한다면 
		// 좋은 컴퓨터는 게임속도 자체가 빨라지는것처럼 보이고,
		// 안좋은 컴퓨터는 게임속도 자체가 느려지는것처럼 보인다.
		// 2.deltaTime을 적용 한다면
		// 좋은 컴퓨터는 같은 게임속도인 대신 같은 시간에 더욱 많이 그려지기에 화면이 부드러워보이고,
		// 안좋은 컴퓨터는 같은 게임속도인 대신 같은 시간에 더욱 적게 그리기에 화면이 끊겨 보일수잇다.
	};
}



