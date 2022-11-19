#include <string>
#include "player.h"


using namespace std;

// 플레이어의 닉네임을 설정하는 함수
void Player::SetnickName(string Name) { 
	this->nickName = Name; 
};

// 플레이어의 닉네임을 가져오는 함수
string Player::GetnickName() { 
	return nickName; 
};

void Player::SetType(int tempType)
{
	type = tempType;
};

int Player::GetType()
{
	return type;
}