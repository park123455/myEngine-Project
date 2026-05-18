#include "Input.h"


namespace k
{
	std::vector<Input::Key> Input::keyBoard = {}; // 초기화를 여기서 하네??

	// 키보드 알파벳 수만큼의 아스키 코드 배열.
	int ASCII[(UINT)keyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initialize()
	{
		CreateKeys();
	}

	void Input::Update()
	{
		UpdateKeys();
	}

	void Input::CreateKeys()
	{
		// size_t는 unsigned __int64의 줄임말이다. 
		for (size_t i = 0; i < (UINT)keyCode::End; i++)
		{
			// 기본 초기화
			Key key = {};
			key.bPressed = false;
			key.state = KeyState::None;
			key.keyCode = (keyCode)i;

			keyBoard.push_back(key);
		}
	}
	void Input::UpdateKeys()
	{
		// (1초 / 프레임)초 마다 검사
		// 60프레임이면 약 0.0166초마다 keyBoard배열안의 모든 데이터 상태를 갱신하는거다. 
		for (size_t i = 0; i < keyBoard.size(); i++)
		{
			// keyBoard[i]가 눌렷다면 
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (keyBoard[i].bPressed == true) // 눌린 키를 검사햇더니 이전 프레임에 눌려잇엇다면
				{
					keyBoard[i].state = KeyState::Pressed; // 현재 눌려진 상태
				}
				else // 이번에 처음 눌린거라면
				{
					keyBoard[i].state = KeyState::Down; // 안눌렷던 키가 눌려진(내려간) 상태.
				}

				keyBoard[i].bPressed = true;
			}
			else // keyBoard[i]가 안 눌렷다면.
			{
				if (keyBoard[i].bPressed == true) // 키를 검사햇더니 이전 프레임에 눌려잇엇다면
				{
					keyBoard[i].state = KeyState::Up; // 눌러졋던 키가 때진(올라간) 상태이다.
				}
				else // 이번에 처음 눌린거라면
				{
					keyBoard[i].state = KeyState::None; // 
				}

				keyBoard[i].bPressed = false;
			}
		}
	}

}