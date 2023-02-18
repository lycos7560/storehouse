#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> uSortMap;

int N, M;
string strArr[100001];

int main()
{

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> strArr[0];
		strArr[i] = strArr[0];
		uSortMap.insert({ strArr[0], i });
	}

	for (int i = 0; i < M; i++) {
		cin >> strArr[0];
		if (strArr[0][0] >= '0' && strArr[0][0] <= '9') {
			cout << strArr[atoi(strArr[0].c_str())] << "\n";
			// atoi(string.c_str())
			// atoi는 해당하는 문자열이 숫자면 숫자를 반환한다 
			// 만약 해당하는 숫자가 숫자가 아니라면 0을 반환
		}
		else {
			cout << uSortMap.find(strArr[0])->second << "\n";
		} 
	}

	return 0;
}