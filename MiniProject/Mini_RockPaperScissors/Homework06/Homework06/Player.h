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
		// 플레이어의 닉네임을 설정하는 함수
		void SetnickName(string Name);

		// 플레이어의 닉네임을 가져오는 함수
		string GetnickName();

		void SetType(int type);
		int GetType();

	private:
		int type;
		string nickName;

};

