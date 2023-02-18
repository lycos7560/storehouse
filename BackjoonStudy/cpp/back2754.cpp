#include <iostream>

using namespace std;

string str;
float result;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> str;
	result = 0;
	if (str != "F") {

		switch (str[0]) {

			case 'A':
				result += 4;
				break;

			case 'B':
				result += 3;
				break;

			case 'C':
				result += 2;
				break;

			case 'D':
				result += 1;
				break;
		}

		switch (str[1]) {

			case '+':
				result += 0.3;
				break;

			case '0':
				result += 0;
				break;

			case '-':
				result -= 0.3;
				break;
		}
	}

	cout << fixed;
	cout.precision(1);
	cout << result;

}