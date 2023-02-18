#include <iostream>
#include <list>
#include <cmath>

using namespace std;

// ��Ϲ����� ȸ�� Ƚ��
int N, tempOne, tempTwo;

list<pair<int, int>> rotationList;
list<pair<int, int>>::iterator iter;

// ��� ������ ���
string cogWheel[4];

// ȸ���� ���üũ�� �ʿ�
bool check[3];

bool debug = false;

// ���
int score = 0;

// ����׿� �Լ�
void DebugPrint()
{
	cout << "\n" << "��Ϲ����� ����\n";
	for (int i = 0; i < 4; i++) {
		cout << cogWheel[i] << "\n";
	}
}

// ������ �Է��� �޴� �Լ�
void GetInput()
{
	for (int i = 0; i < 4; i++) {
		cin >> cogWheel[i];
	}
	cin >> N;

	// ��Ϲ����� ȸ���� ��ŭ �Է��� �޽��ϴ�.
	while (N > 0) {
		cin >> tempOne >> tempTwo;
		rotationList.push_back(make_pair(tempOne, tempTwo));
		N--;
	}
}

// ��ϸ� ȸ���ϴ� �Լ�
void CogwheelRotation(int number, int dir)
{
	string tempString;

	// ��ϸ� �ð� �������� ȸ��
	if (dir == 1) {
		tempString.push_back(cogWheel[number - 1][7]);
		for (int i = 0; i < 7; i++) {
			tempString.push_back(cogWheel[number - 1][i]);
		}
		if (debug) { cout << number << "�� ��� " << "�ð� ���� ȸ�� : " << cogWheel[number - 1] << " -> "; }
		cogWheel[number - 1] = tempString;
		if (debug) { cout << tempString << "\n"; }
	}
	else { 	// ��ϸ� �ݽð� �������� ȸ��
		for (int i = 1; i < 8; i++) {
			tempString.push_back(cogWheel[number - 1][i]);
		}

		tempString.push_back(cogWheel[number - 1][0]);
		if (debug) { cout << number << "�� ��� " << "�ݽð� ���� ȸ��: " << cogWheel[number - 1] << " -> "; }
		cogWheel[number - 1] = tempString;
		if (debug) { cout << tempString << "\n"; }
	}
}

// ȸ���� ��ϸ� üũ
void RotationCheck(int number, int dir)
{

	for (int i = 0; i < 3; i++) {
		cogWheel[i + 1][6] != cogWheel[i][2] ? check[i] = true : check[i] = false;
	}
	if (debug) { cout << "\n" << "������ ��Ϲ��� ȸ��" << "\n"; }

	CogwheelRotation(number, dir);

	if (debug) { DebugPrint(); }
	if (debug) { cout << "\n" << "��ȣ�ۿ� ����" << "\n"; }

	switch (number)
	{
		case 1: // 2������ 4��
			for (int i = 0; i < 3; i++) {
				if (check[i]) { CogwheelRotation(i + 2, dir * pow(-1, i + 1)); }
				else { break; }
			}
			break;

		case 2: //3������ 4��
			for (int i = 1; i < 3; i++) {
				if (check[i]) {
					CogwheelRotation(i + 2, dir * pow(-1, i)); }
				else { break; }
			}

			// 1��
			if (check[0]) { CogwheelRotation(1, -dir); }
			break;

		case 3: // 2������ 1��
			for (int i = 1; i >= 0; i--) {
				if (check[i]) {
					CogwheelRotation(i + 1, dir * pow(-1, i));
				}
				else { break; }
			}

			// 4��
			if (check[2]) { CogwheelRotation(4, -dir); }
			break;

		case 4: // 3������ 1��
			for (int i = 2; i >= 0; i--) {
				if (check[i]) {
					CogwheelRotation(i + 1, dir * pow(-1, i + 1));
				}
				else { break; }
			}
			break;
	}
}

// ������ ����ϴ� �Լ�
void ScoreCalculation()
{
	for (int i = 0; i < 4; i++) {
		if (cogWheel[i][0] == '1') { score += pow(2, i); }
	}
}

int main()
{
	GetInput();

	for (iter = rotationList.begin(); iter != rotationList.end(); iter++) {
		RotationCheck(iter->first, iter->second);
		if (debug) { 
			DebugPrint(); 
		}
	}

	// ���� ���
	ScoreCalculation();

	if (debug) { 
		DebugPrint(); 
		cout << "\n�� : ";
	}

	cout << score;

	return 0;
}