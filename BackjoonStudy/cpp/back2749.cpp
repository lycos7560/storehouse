#include <iostream>
#include <string>

using namespace std;

constexpr auto MN = 1000000;

string N = "";

int arr[3];

int ModFibonacci(string N)
{	
	// unsigned long long의 범위 0 ~ 18,446,744,073,709,551,615
	// N의 최대 1,000,000,000,000,000,000
	unsigned long long tempN = stoull(N);
	tempN = tempN % 1500000; // 피사노의 주기

	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 0;

	if (tempN == 0) { return arr[0]; }
	else if (tempN == 1) { return arr[1]; }

	for (unsigned long long i = 2; i <= tempN; i++) {
		arr[2] = (arr[1] % MN + arr[0] % MN) % MN; //
		arr[0] = arr[1];
		arr[1] = arr[2];
	}

	return arr[2];
}

int main()
{

	cin >> N;
	cout << ModFibonacci(N);
	return 0;

}
