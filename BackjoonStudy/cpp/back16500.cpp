#include <iostream>

using namespace std;

string str[101];
int length[101];

int N, result = 0;

int main()
{
	cin >> str[0] >> N;

	for (int i = 1; i <= N; i++) cin >> str[i];
	for (int i = 0; i <= N; i++) length[i] = str[i].length();





	cout << result;

	return 0;
}