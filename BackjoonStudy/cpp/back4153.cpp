#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

int arr[3];

string answer[2] = { "right", "wrong" };
list<string> myList;

int main()
{

	while (true)
	{	
		for (int i = 0; i < 3; i++) { cin >> arr[i]; } 
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) { break; } // 0 0 0이나오면 stp[
		sort(arr, arr + 3); // 오름차순으로 정렬 [2]번이 가장 긴변

		// 직각삼각형인지 확인하고 //결과를 리스트에 넣음
		if (pow(arr[2], 2) == (pow(arr[1], 2) + pow(arr[0], 2))) myList.push_back(answer[0]);
		else myList.push_back(answer[1]);
	}

	// 결과를 저장한 리스트를 순회하면서 출력
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}


	return 0;
}