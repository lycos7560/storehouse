#include <iostream>
#include <set>
#include <list>

using namespace std;

int T, N;

pair<char,int> temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	while (T-- > 0) {

		cin >> N;

		multiset<int> myMSet;

		while (N-- > 0) {

			cin >> temp.first >> temp.second;

			if (temp.first == 'I') myMSet.insert(temp.second);
			else if (temp.second == -1) {
				if (myMSet.empty()) continue; // 비어있다면 연산 무시
				else myMSet.erase(myMSet.begin());
			}
			else {
				if (myMSet.empty()) continue; // 비어있다면 연산 무시
				else myMSet.erase(--myMSet.end());
			}
		}

		if (!myMSet.empty()) cout << *--myMSet.end() << " " << *myMSet.begin() << "\n";
		else cout << "EMPTY" << "\n";
	}

	return 0;
}