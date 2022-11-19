#include <string>
#include <random>
#include <iostream>
#include "game.h"
#include <windows.h>

using namespace std;


// 상대가 랜덤으로 타입을 결정합니다.
int Game::RandomPickHand()
{
	int rangeMin = 0;
	int rangeMax = 2;
	random_device rd;     // Only used once to initialise (seed) engine
	mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
	uniform_int_distribution<int> uni(rangeMin, rangeMax); // Guaranteed unbiased
	int random_integer = uni(rng);

	return random_integer;
}


// 게임의 룰을 설정합니다.
void Game::InitGame()
{	
	arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Scissors] = "무승부";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Paper] = "승리";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Rock] = "패배";

	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Rock] = "무승부";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Paper] = "패배";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Scissors] = "승리";

	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Paper] = "무승부";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Scissors] = "패배";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Rock] = "승리";
}

// 플레이어의 닉네임을 설정합니다.
void Game::CreatePlayerAndNickName(string nickName)
{
	player.SetnickName(nickName);
}

// 플레이어를 가져옵니다.
Player Game::GetPlayerInfo()
{
	return player;
}

string Game::PlayerPrintHand()
{
	if (player.GetType() == (int)Game::RockPaperScissorsType::Rock)
	{
		return "주먹";
	}
	else if (player.GetType() == (int)Game::RockPaperScissorsType::Scissors)
	{
		return "가위";
	}
	else if (player.GetType() == (int)Game::RockPaperScissorsType::Paper)
	{
		return "보";
	}
}

string Game::ComputerPrintHand()
{
	if ( computer.GetType() == (int)Game::RockPaperScissorsType::Rock)
	{
		return "주먹";
	}
	else if (computer.GetType() == (int)Game::RockPaperScissorsType::Scissors)
	{
		return "가위";
	}
	else if (computer.GetType() == (int)Game::RockPaperScissorsType::Paper)
	{
		return "보";
	}

}

void Game::checkInput(int temp)
{
	switch (temp)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			cout << "\n잘못된 입력입니다. 프로그램을 종료합니다.\n";
			system("pause");
			exit(0);
			break;
	}


}


void Game::GameStart()
{
	Sleep(1500);
	system("cls");
	cout << "\n------------------------------";
	cout << "\n게임을 시작합니다.\n";
	cout << "------------------------------\n";
	Sleep(1500);
	system("cls");
	cout << "\n------------------------------";
	cout << "\n 타입을 결정해주세요!! \n";
	cout << "Rock = 0, Paper = 1, Scissors = 2\n";
	cout << "숫자 : ";
	int temp;
	cin >> temp;
	checkInput(temp);
	player.SetType(temp);
	computer.SetType(RandomPickHand());
	computer.SetnickName("토리");
	system("cls");
	cout << "\n------------------------------\n";
	cout << player.GetnickName() << "님은 " << PlayerPrintHand() << " 을(를) 선택하셨습니다.\n";
	cout << "------------------------------\n";
	cout << "상대인 : " << computer.GetnickName() << "님은 " << ComputerPrintHand() << "을(를) 선택하셨습니다.\n";
	cout << "\n------------------------------\n";
	cout << "결과는 당신의 " << arrJudge[player.GetType()][computer.GetType()] << "입니다.\n";
	system("pause");
		
}
