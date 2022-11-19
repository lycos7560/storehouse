#pragma once
#include <string>
#include "Player.h"

using namespace std;


class Game
{
	public :
		Game() {}; // 생성자

		// 여기서 가위바위보를 정의해 줍니다.
		enum class RockPaperScissorsType {
			Rock = 0, Paper = 1, Scissors = 2
		};

		
		// 랜덤으로 가위바위보 선택 하기 
		int RandomPickHand();

		// 게임의 룰을 설정합니다.
		void InitGame();

		// 플레이어의 닉네임을 설정합니다.
		void CreatePlayerAndNickName(string nickName);

		// 플레이어의 정보를 가져옵니다.
		Player GetPlayerInfo();

		void GameStart();

		string PlayerPrintHand();
		string ComputerPrintHand();
		void checkInput(int temp);

	private :
		// 가위바위보 룰 셋팅
		string arrJudge[3][3];
		Player player;
		RockPaperScissorsType playerType;
		Player computer;
		RockPaperScissorsType computerType;

};

