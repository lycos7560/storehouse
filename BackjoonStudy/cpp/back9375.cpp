#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> myMap;

int T , N, result;

string tempO, tempT;

// 조합 n C r 을 계산하는 함수
int Combination(int n, int r)
{
	if (n == r || r == 0) return 1;
	else return Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	//cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> T;

	while (T--) {

		myMap.clear();

		cin >> N;

		while (N--) {

			cin >> tempO >> tempT;

			auto it = myMap.find(tempT);
			
			// 만약 map에 있다면 개수를 + 1
			// 없다면 개수를 1로 새로 넣어준다.
			if (it != myMap.end()) it->second++;
			else myMap.insert(make_pair(tempT, 1));
			
		}

		result = 1;

		for (auto it = myMap.begin(); it != myMap.end(); it++) {
			result *= Combination(it->second + 1, 1); // 아무것도 뽑지 않는다 하나 추가
		}

		cout << result - 1 << "\n"; // 모든 의상의 종류를 안뽑는다는 경우를 뺴준다.

	}

	return 0;
}