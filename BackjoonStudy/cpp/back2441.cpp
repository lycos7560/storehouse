#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str = "";
		for (int j = 0; j < i; j++) str.push_back(' ');
		for (int j = N - i; j > 0; j--) str.push_back('*');
		cout << str << "\n";
	}

	return 0;
}