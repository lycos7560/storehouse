#include <iostream>
#include <list>

using namespace std;

list<int> intList;

int N, X, temp;

int main()
{

	cin >> N >> X;
	
	while (N-- > 0) {
		cin >> temp;
		if (X > temp) {
			// X 보다 입력받은 값이 작다면
			// 리스트에 넣는다.
			intList.push_back(temp);
		}
	}

	// 리스트를 순회하며 결과를 출력한다.
	for (auto it = intList.begin(); it != intList.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}