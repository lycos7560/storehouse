#include <iostream>

using namespace std;

string str = "";

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) { 
		str.push_back(' '); 
	}

	for (int i = N - 1; i >= 0; i--) {
		str[i] = '*';
		cout << str << "\n";
	}
}