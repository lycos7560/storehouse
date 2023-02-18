#include <iostream>
#include <list>

using namespace std;

int T, N, Zero, One;

long long int arrZero[41] = {1, 0, 1};
long long int arrOne[41] = {0, 1, 1};

list<int> myList;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		myList.push_back(N);
	}

	for (auto it = myList.begin(); it != myList.end(); it++) {
		for (int i = 3; i <= *it; i++) {
			if (arrZero[i] == 0) arrZero[i] = arrZero[i - 1] + arrZero[i - 2];
			if (arrOne[i] == 0) arrOne[i] = arrOne[i - 1] + arrOne[i - 2];
		}

		cout << arrZero[*it] << " " << arrOne[*it] << "\n";
	}

	return 0;
}