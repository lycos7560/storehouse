#pragma once
#include <string>
#include "Player.h"

using namespace std;


class Game
{
	public :
		Game() {}; // ������

		// ���⼭ ������������ ������ �ݴϴ�.
		enum class RockPaperScissorsType {
			Rock = 0, Paper = 1, Scissors = 2
		};

		
		// �������� ���������� ���� �ϱ� 
		int RandomPickHand();

		// ������ ���� �����մϴ�.
		void InitGame();

		// �÷��̾��� �г����� �����մϴ�.
		void CreatePlayerAndNickName(string nickName);

		// �÷��̾��� ������ �����ɴϴ�.
		Player GetPlayerInfo();

		void GameStart();

		string PlayerPrintHand();
		string ComputerPrintHand();
		void checkInput(int temp);

	private :
		// ���������� �� ����
		string arrJudge[3][3];
		Player player;
		RockPaperScissorsType playerType;
		Player computer;
		RockPaperScissorsType computerType;

};

