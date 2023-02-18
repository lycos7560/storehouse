#include <iostream>
#include <map>

using namespace std;

int arrN[1000001];
int number[1000000];

map<int, int> myMap;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> arrN[0];

	for (int i = 1; i <= arrN[0]; i++) cin >> arrN[i];

	// map으로 오름차순 정렬 
	for (int i = 1; i <= arrN[0]; i++) 
		myMap.insert(make_pair(arrN[i], 0)); 

	int cnt = 0;
	for (auto it = myMap.begin(); it != myMap.end(); it++) 
		it->second = cnt++;

	for (int i = 1; i <= arrN[0]; i++) 
		cout << myMap.find(arrN[i])->second << " ";

	return 0;
}
