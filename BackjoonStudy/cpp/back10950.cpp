#include <iostream>
#include <list>

using namespace std;

list <pair<int, int>> tempList;
list <pair<int, int>>::iterator it;

pair<int, int> temp;

int main()
{
	int N;
	cin >> N;
	while (N > 0) {
		cin >> temp.first >> temp.second;
		tempList.push_back(temp);
		N--;
	}

	for (it = tempList.begin(); it != tempList.end(); it++) 
		cout << it->first + it->second << "\n";

	return 0;
}