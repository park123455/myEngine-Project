#pragma once
#include "CommonInclude.h"

namespace k
{
	enum class KeyState // 키보드 버튼 1개의 상태
	{
		Down,
		Pressed,
		Up,
		None,
	};
	enum class keyCode // 키보드 버튼 1개의 식별
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		End,
	};



	class Input
	{
	public:
		struct Key // 키보드 버튼 1개 객체
		{
			keyCode keyCode;
			KeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();


		// 키보드 버튼 하나에 저장된 현재 키상태를 가져온다.
		// 참고로 UINT 는 언사인드 int를 말한다. 즉 음수를 포함하지 않는 정수 자료형. 줄임말임.
		static bool GetKeyDown(keyCode code)
		{ 
			return keyBoard[(UINT)code].state == KeyState::Down; 
		}
		static bool GetKeyUp(keyCode code)
		{ 
			return keyBoard[(UINT)code].state == KeyState::Up; 
		}
		static bool GetKey(keyCode code)
		{ 
			return keyBoard[(UINT)code].state == KeyState::Pressed; 
		}

	private:
		static std::vector<Key> keyBoard;
	};
}



