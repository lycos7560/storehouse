#include <iostream>
#include <cmath>

using namespace std;

string str, tempStr;

int result = 0;
bool check = false;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	// 한번이라도 - 가 나온다면 뒤의 수들은 전부 뺴준다.
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 45) { // '-' = 45
			result += atoi(tempStr.c_str()) * ( pow(-1, check));
			check = true;
			tempStr = "";
		}
		else if (str[i] == 43) { // '+' = 43
			result += atoi(tempStr.c_str()) * (pow(-1, check));
			tempStr = "";
		}
		else tempStr.push_back(str[i]);
	}

	// 마지막 숫자 해결
	result += atoi(tempStr.c_str()) * (pow(-1, check));

	cout << result;

	return 0;
}