#pragma once
#include <string>
using namespace std;

class Player
{
	
	public:
		Player() {
			type = 0;
			nickName = "";
		};
		// �÷��̾��� �г����� �����ϴ� �Լ�
		void SetnickName(string Name);

		// �÷��̾��� �г����� �������� �Լ�
		string GetnickName();

		void SetType(int type);
		int GetType();

	private:
		int type;
		string nickName;

};

