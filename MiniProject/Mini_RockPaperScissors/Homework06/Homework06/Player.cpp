#include <string>
#include "player.h"


using namespace std;

// �÷��̾��� �г����� �����ϴ� �Լ�
void Player::SetnickName(string Name) { 
	this->nickName = Name; 
};

// �÷��̾��� �г����� �������� �Լ�
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