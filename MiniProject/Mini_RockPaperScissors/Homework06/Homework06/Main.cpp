#include <iostream>
#include <windows.h>
#include "game.h"

using namespace std;

int main()
{
	Game game;
	game.InitGame();


	cout << "------------------------------";
	cout << "\n!!!!!!!!���������� ����!!!!!!!!\n";
	cout << "------------------------------\n";
	Sleep(2000);
	system("cls");

	// ������� �⺻ ����
	string temp;
	cout << "\n------------------------------";
	cout << "\n����� �г����� �����ϼ���\n";
	cout << "------------------------------\n";
	cout << "�г��� :  ";
	cin >> temp;
	game.CreatePlayerAndNickName(temp);
	
	system("cls");
	cout << "\n------------------------------";
	cout << "\n�ȳ��ϼ���!  ";
	cout << game.GetPlayerInfo().GetnickName() << " ��\n";
	cout << "------------------------------\n";
	
	game.GameStart();

	return 0;
}