#include <iostream>

using namespace std;

int N;

char map[64][64];

string result;

void DivisionalConquest(int x, int y, int w)
{
	bool check = true;
	for (int i = 0; i < w ; i++) {
		for (int j = 0; j < w; j++) {
			if (map[x][y] != map[x + i][y + j]) check = false;
		}
		if (!check) break;
	}

	if (check) {
		result.push_back(map[x][y]);
		return;
	}
	else if (w == 1) {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < w; j++) {
				result.push_back(map[x + i][y + j]);
			}
		}

		return;
	}

	result.push_back('(');
	DivisionalConquest(x , y, w / 2);
	DivisionalConquest(x , y + w / 2, w / 2);
	DivisionalConquest(x + w / 2, y, w / 2);
	DivisionalConquest(x + w / 2, y + w / 2, w / 2);
	result.push_back(')');


}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
		}
	}

	DivisionalConquest(0, 0, N);

	cout << result;

	return 0;
}