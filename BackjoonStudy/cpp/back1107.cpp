#include <iostream>
#include <cmath>

using namespace std;

bool arr[10];

string str, strTemp;

int N, M, temp, cnt, target, result = INT32_MAX;

void dfs(string st, char ch)
{
	if (st.length() == str.length() + 1) return;
	st.push_back(ch);
	cnt = abs(target - atoi(st.c_str())) + st.length();
	result = min(cnt, result);

	for (int i = 0; i < 10; i++) {
		if (arr[i] == true) continue;
		dfs(st, i + '0');
	}
}

int main()
{
	cin >> str >> M;

	target = atoi(str.c_str());

	for (int i = 0; i < M; i++) {
		cin >> temp;
		arr[temp] = true;
	}
	
	for (int i = 0; i < 10; i++) {
		if (arr[i] == true) continue;
		dfs(strTemp, i + '0');
	}

	result = min(abs(target - 100), result);

	cout << result;

	return 0;
}