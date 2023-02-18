#include <iostream>
#include <list>

using namespace std;

list <pair<int, int>> tempList;
list <pair<int, int>>::iterator it;

pair<int, int> temp;

int main()
{
	while (true) {

		// pair<int, int> 입력 값을 넣는다.
		cin >> temp.first >> temp.second;

		// 입력 마지막에는 0 0 이 들어오는 것을 체크하고
		// 리스트에는 넣지 않는다.
		if (temp.first == 0 && temp.second == 0) { break;}

		//리스트에 입력을 넣는다.
		tempList.push_back(temp);
	}
	
	// 리스트를 순회하면서 더한값을 출력한다.
	for (it = tempList.begin(); it != tempList.end(); it++) 
		cout << it->first + it->second << "\n";

	return 0;
}