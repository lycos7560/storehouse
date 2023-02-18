#include <iostream>
#include <list>

using namespace std;

int N, temp;
int arr[12];
list<int> myList;

int main()
{
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 0; i < N; i++) {

		cin >> temp;

		for (int j = 4; j <= temp; j++) {

			if (arr[j] != 0) continue;

			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}

		myList.push_back(arr[temp]);

	}

	for (auto it = myList.begin(); it != myList.end(); it++) cout << *it << "\n";

	return 0;
}