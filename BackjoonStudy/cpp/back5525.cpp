#include <iostream>

using namespace std;

int N, S, result = 0;

string str;

int main()
{
	cin >> N >> S >>  str;

	for (int i = 0; i < str.length(); i++) {

		// 시작이 O 이라면 넘어간다.
		if (str[i] == 'O') continue;

		// i + 1과 i + 2의 값을 확인한다.(P1을 만족하는 지 확인)
		if (str[i + 1] == 'O' && str[i + 2] == 'I') {

			// cnt가 N의 값과 같아진다면 PN 이 하나 존재한다는 의미
			int cnt = 0;

			// 조건을 만족하면 반복
			while (str[i] == 'I' && str[i + 1] == 'O') {
				// 인덱스를 두칸 이동
				i += 2;

				cnt++;

				if (str[i] == 'I' && cnt == N) {
					cnt--; // 뒤에 'O' 하나 무시 ex) P1 => IOIO 확인함 -개 빼준다.
					result++;
				}
			}
		}
	}
	
	cout << result << "\n";

	return 0;
}