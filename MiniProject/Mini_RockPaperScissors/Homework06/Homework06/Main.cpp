#include <iostream>
#include <windows.h>
#include "game.h"

using namespace std;

int main()
{
	Game game;
	game.InitGame();


	cout << "------------------------------";
	cout << "\n!!!!!!!!가위바위보 게임!!!!!!!!\n";
	cout << "------------------------------\n";
	Sleep(2000);
	system("cls");

	// 사용자의 기본 세팅
	string temp;
	cout << "\n------------------------------";
	cout << "\n당신의 닉네임을 설정하세요\n";
	cout << "------------------------------\n";
	cout << "닉네임 :  ";
	cin >> temp;
	game.CreatePlayerAndNickName(temp);
	
	system("cls");
	cout << "\n------------------------------";
	cout << "\n안녕하세요!  ";
	cout << game.GetPlayerInfo().GetnickName() << " 님\n";
	cout << "------------------------------\n";
	
	game.GameStart();

	return 0;
}