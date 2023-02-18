#include <iostream>
#include <map>

using namespace std;

map<string, int> myMap;

multimap<int, string> mMap;

string str;

int n;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// map에 넣어서 중복된 단어를 제거하고
	// 알파벳 순으로 정렬 합니다. (map의 성질)
	// key = string, value = int 
	for (int i = 0; i < n; i++) {
		cin >> str;
		myMap.insert(make_pair(str, str.length()));
	}

	// multimap에 넣어 숫자가 같으면 들어온 순서대로 입력됩니다.
	// key = int (multimap은 중복 허용), value = string
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		mMap.insert(make_pair(it->second, it->first));
	}

	for (auto it = mMap.begin(); it != mMap.end(); it++) {
		cout << it->second << "\n";
	}
	return 0;
}