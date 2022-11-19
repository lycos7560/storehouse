#include <string>
#include <random>
#include <iostream>
#include "game.h"
#include <windows.h>

using namespace std;


// ��밡 �������� Ÿ���� �����մϴ�.
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


// ������ ���� �����մϴ�.
void Game::InitGame()
{	
	arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Scissors] = "���º�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Paper] = "�¸�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Scissors][(int)Game::RockPaperScissorsType::Rock] = "�й�";

	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Rock] = "���º�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Paper] = "�й�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Rock][(int)Game::RockPaperScissorsType::Scissors] = "�¸�";

	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Paper] = "���º�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Scissors] = "�й�";
	Game::arrJudge[(int)Game::RockPaperScissorsType::Paper][(int)Game::RockPaperScissorsType::Rock] = "�¸�";
}

// �÷��̾��� �г����� �����մϴ�.
void Game::CreatePlayerAndNickName(string nickName)
{
	player.SetnickName(nickName);
}

// �÷��̾ �����ɴϴ�.
Player Game::GetPlayerInfo()
{
	return player;
}

string Game::PlayerPrintHand()
{
	if (player.GetType() == (int)Game::RockPaperScissorsType::Rock)
	{
		return "�ָ�";
	}
	else if (player.GetType() == (int)Game::RockPaperScissorsType::Scissors)
	{
		return "����";
	}
	else if (player.GetType() == (int)Game::RockPaperScissorsType::Paper)
	{
		return "��";
	}
}

string Game::ComputerPrintHand()
{
	if ( computer.GetType() == (int)Game::RockPaperScissorsType::Rock)
	{
		return "�ָ�";
	}
	else if (computer.GetType() == (int)Game::RockPaperScissorsType::Scissors)
	{
		return "����";
	}
	else if (computer.GetType() == (int)Game::RockPaperScissorsType::Paper)
	{
		return "��";
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
			cout << "\n�߸��� �Է��Դϴ�. ���α׷��� �����մϴ�.\n";
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
	cout << "\n������ �����մϴ�.\n";
	cout << "------------------------------\n";
	Sleep(1500);
	system("cls");
	cout << "\n------------------------------";
	cout << "\n Ÿ���� �������ּ���!! \n";
	cout << "Rock = 0, Paper = 1, Scissors = 2\n";
	cout << "���� : ";
	int temp;
	cin >> temp;
	checkInput(temp);
	player.SetType(temp);
	computer.SetType(RandomPickHand());
	computer.SetnickName("�丮");
	system("cls");
	cout << "\n------------------------------\n";
	cout << player.GetnickName() << "���� " << PlayerPrintHand() << " ��(��) �����ϼ̽��ϴ�.\n";
	cout << "------------------------------\n";
	cout << "����� : " << computer.GetnickName() << "���� " << ComputerPrintHand() << "��(��) �����ϼ̽��ϴ�.\n";
	cout << "\n------------------------------\n";
	cout << "����� ����� " << arrJudge[player.GetType()][computer.GetType()] << "�Դϴ�.\n";
	system("pause");
		
}
