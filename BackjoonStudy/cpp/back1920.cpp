#include <iostream>
#include <set>
#include <list>

using namespace std;

set<int> mySet;
list<int> myList;
int N, temp;

int main()
{
	cin >> N;
	while (N-- > 0) {
		cin >> temp;
		mySet.insert(temp);
	}

	cin >> N;

	while (N-- > 0) {
		cin >> temp;
		myList.push_back(temp);
	}

	for (auto it = myList.begin(); it != myList.end(); it++) {
		if (mySet.find(*it) != mySet.end()) { cout << "1\n"; }
		else { cout << "0\n"; }
	}

	return 0;
}