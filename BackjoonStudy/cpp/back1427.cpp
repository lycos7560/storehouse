#include <iostream>

using namespace std;

string str;

int arr[10];

int main()
{
	cin >> str;

	for (int i = 0; i < str.length(); i++)  arr[str[i] - '0']++;

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++)  cout << i;
	}

	return 0;
}