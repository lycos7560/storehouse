#include <iostream>
#include <deque>
#include <cstdlib>
#include <string>

using namespace std;

int T, N;

string P, arrStr;

bool isFront = false;

int main()
{

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	//cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> P;
		cin >> N >> arrStr;
		isFront = true;
		deque<int> myDeque;
		string tempStr;
		for (int i = 1; i < arrStr.length(); i++) {
			if (arrStr[i] == ',' || arrStr[i] == ']') {
				if (tempStr != "") {
					myDeque.push_back(atoi(tempStr.c_str()));
				}

				tempStr = "";
			}
			else {
				tempStr.push_back(arrStr[i]);
			}
		}

		for (int i = 0; i < P.length(); i++) {
			
			if (P[i] == 'R') isFront = !isFront;
			else {
				if (myDeque.empty()) {
					tempStr = "error\n";
					break;
				}

				if (isFront) myDeque.pop_front();
				else myDeque.pop_back();
			}
		}


		if (tempStr[0] == 'e') cout << tempStr;
		else {
			cout << "[";
			if (isFront) {
				while (!myDeque.empty()) {
					cout << myDeque.front();
					myDeque.pop_front();
					if (myDeque.empty()) continue;
					else cout << ",";
				}
			}
			else {
				while (!myDeque.empty()) {
					cout << myDeque.back();
					myDeque.pop_back();
					if (myDeque.empty()) continue;
					else cout << ",";
				}
			}

			cout << "]\n";
		}
	}

	return 0;
}