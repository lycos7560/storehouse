#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < (2 * N) - 1; i++)
		str.push_back(' ');
	for (int i = 0; i < N; i++) {
		str[(str.length() / 2) + i] = '*';
		str[(str.length() / 2) - i] = '*';
		string temp = str.substr(0, (str.length() / 2) + i + 1);
		cout << temp << "\n";
	}

	return 0;
}