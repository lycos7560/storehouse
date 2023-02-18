#include <iostream>
#include <map>

using namespace std;

string name[100000];

multimap<int, int> myMap;

int N, temp, temp2 = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp >> name[i];
		// string[등록순서] 배열에 이름을 저장해둔다.
		myMap.insert(make_pair(temp, i));
		// 멀티맵에 (나이, 등록순서) 저장한다.
		// 나이가 같다면 등록순서에 따라서 정렬된다. (오름차순)
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		// 이름배열[등록순] = 정보가 나온다.
		cout << it->first << " " << name[it->second] << "\n";
	}

	return 0;
}
