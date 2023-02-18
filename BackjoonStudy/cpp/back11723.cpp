/*
#include <iostream>
#include <set>

using namespace std;

set<int> mySet;

int N, temp;

string str;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		if (str == "add") {
			// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) 
			// S에 x가 이미 있는 경우에는 연산을 무시한다.
			cin >> temp;
			mySet.insert(temp);
		}
		else if (str == "remove") {
			//remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) 
			// S에 x가 없는 경우에는 연산을 무시한다.
			cin >> temp;
			mySet.erase(temp);
		}
		else if (str == "check") {
			// check x: S에 x가 있으면 1을, 
			// 없으면 0을 출력한다. (1 ≤ x ≤ 20)
			cin >> temp;
			if (mySet.count(temp)) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (str == "toggle") {
			// toggle x : S에 x가 있으면 x를 제거하고, 
			// 없으면 x를 추가한다. (1 ≤ x ≤ 20)
			cin >> temp;
			if (mySet.count(temp)) mySet.erase(temp);
			else mySet.insert(temp);
		}
		else if (str == "all") {
			// all: S를 {1, 2, ..., 20} 으로 바꾼다.
			for (int i = 1; i <= 20; i++) mySet.insert(i);
		}
		else { 
			// empty: S를 공집합으로 바꾼다. 
			mySet.clear();
		}
	}

	return 0;
}
*/
/*
#include <iostream>
using namespace std;

bool arr[20];
int N, temp;

string str;

int main()
{
	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		if (str == "add") {
			// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) 
			// S에 x가 이미 있는 경우에는 연산을 무시한다.
			cin >> temp;
			arr[temp-1] = 1;
		}
		else if (str == "remove") {
			//remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) 
			// S에 x가 없는 경우에는 연산을 무시한다.
			cin >> temp;
			arr[temp-1] = 0;
		}
		else if (str == "check") {
			// check x: S에 x가 있으면 1을, 
			// 없으면 0을 출력한다. (1 ≤ x ≤ 20)
			cin >> temp;
			cout << arr[temp-1] << "\n";
		}
		else if (str == "toggle") {
			// toggle x : S에 x가 있으면 x를 제거하고, 
			// 없으면 x를 추가한다. (1 ≤ x ≤ 20)
			cin >> temp;
			if (arr[temp-1] == 1) arr[temp-1] = 0;
			else  arr[temp-1] = 1;
		}
		else if (str == "all") {
			// all: S를 {1, 2, ..., 20} 으로 바꾼다.
			for (int i = 0; i < 20; i++) arr[i] = 1;
		}
		else {
			// empty: S를 공집합으로 바꾼다. 
			fill(arr, arr + 20, 0);
		}
	}

	return 0;
}

*/

#include <iostream>

using namespace std;

int S = 0; // 비트마스킹
string str;
int N, temp;

int main() {

	ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
	// cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while(N-- > 0) {

		cin >> str;
		if (str == "add") {
			// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) 
			// S에 x가 이미 있는 경우에는 연산을 무시한다.
			cin >> temp;
			S = S | (1 << temp);
		}
		else if (str == "remove") {
			//remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) 
			// S에 x가 없는 경우에는 연산을 무시한다.
			cin >> temp;
			S = S & ~(1 << temp);
		}
		else if (str == "check") {
			// check x: S에 x가 있으면 1을, 
			// 없으면 0을 출력한다. (1 ≤ x ≤ 20)
			cin >> temp;
			if (S & (1 << temp)) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "toggle") {
			// toggle x : S에 x가 있으면 x를 제거하고, 
			// 없으면 x를 추가한다. (1 ≤ x ≤ 20)
			cin >> temp;
			if (S & (1 << temp)) {
				S = S & ~(1 << temp);
			}
			else {
				S = S | (1 << temp);
			}
		}
		else if (str == "all") {
			// all: S를 {1, 2, ..., 20} 으로 바꾼다.
			S = (1 << 21) - 1;
		}
		else {
			// empty: S를 공집합으로 바꾼다. 
			S = 0;
		}
	}

	return 0;
}