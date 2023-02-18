#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

int N, M;

string strOne, strTwo;

unordered_map<string, string> uMap;

list<string> myList;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	// unordered_map에 사이트와 비밀번호를 저장
	for (int i = 0; i < N; i++) {
		cin >> strOne >> strTwo;
		uMap.insert(make_pair(strOne, strTwo));
	}

	// 비밀번호가 필요한 사이트의 리스트를 저장
	for (int i = 0; i < M; i++) {
		cin >> strOne;
		myList.push_back(strOne);
	}

	// 사이트를 key로 값(비밀번호)을 검색
	for (auto it = myList.begin(); it != myList.end(); it++) {
		strOne = *it;
		cout << uMap.find(strOne)->second << "\n";
	}

	return 0;
}