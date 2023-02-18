#include <iostream>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	for (int i = 1; i <= 9; i++) 
		cout << N << " " << "*" << " " << i << " = " << i * N << "\n";

	return 0;
}