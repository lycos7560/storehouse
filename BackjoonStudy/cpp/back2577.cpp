#include <iostream>
#include <string> // to_string

using namespace std;

int N = 1, temp;
string str = "";
int arr[10];

int main()
{
	for (int i = 0; i < 3; i++) {
		cin >> temp;
		N = N * temp;
	}

	// int => string 
	// 119 => "119"
	str = to_string(N); 

	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
}