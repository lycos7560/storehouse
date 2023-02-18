#include <iostream>

using namespace std;

string str = "*";

int main()
{
	int N = 0;
	cin >> N;
	while (N-- > 0) {
		cout << str << "\n";
		str.push_back('*');
	}

	return 0;
}