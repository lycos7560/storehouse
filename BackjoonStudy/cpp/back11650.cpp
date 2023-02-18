#include <iostream>
#include <map>

using namespace std;

multimap<int, int> myMap;
multimap<int, int> myMap2;

int arr[3];

// multimap의 특성을 이용한 정렬

int main()
{
	cin >> arr[0];
	for (int i = 0; i < arr[0]; i++) {
		cin >> arr[1] >> arr[2];
		myMap.insert(make_pair(arr[2],arr[1]));
		// Y로 오름차순으로 정렬
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		myMap2.insert(make_pair(it->second, it->first));
		// Y로 정렬된 리스트를 X로 정렬
		// value 값은 들어온 순서대로
	}

	for (auto it = myMap2.begin(); it != myMap2.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}

	return 0;
}