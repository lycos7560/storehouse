#include <iostream>

using namespace std;

int n[3];

int main()
{
	cin >> n[0] >> n[1] >> n[2];
	cout << (n[0] + 1) * (n[1] + 1) / (n[2] + 1) - 1;
	return 0;
}