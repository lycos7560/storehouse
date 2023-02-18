/*
#include <iostream>
#include <set>

using namespace std;

set<int> mySet;

int N, temp;

string str;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		if (str == "add") {
			// add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) 
			// S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			mySet.insert(temp);
		}
		else if (str == "remove") {
			//remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) 
			// S�� x�� ���� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			mySet.erase(temp);
		}
		else if (str == "check") {
			// check x: S�� x�� ������ 1��, 
			// ������ 0�� ����Ѵ�. (1 �� x �� 20)
			cin >> temp;
			if (mySet.count(temp)) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (str == "toggle") {
			// toggle x : S�� x�� ������ x�� �����ϰ�, 
			// ������ x�� �߰��Ѵ�. (1 �� x �� 20)
			cin >> temp;
			if (mySet.count(temp)) mySet.erase(temp);
			else mySet.insert(temp);
		}
		else if (str == "all") {
			// all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
			for (int i = 1; i <= 20; i++) mySet.insert(i);
		}
		else { 
			// empty: S�� ���������� �ٲ۴�. 
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
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N-- > 0) {
		cin >> str;
		if (str == "add") {
			// add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) 
			// S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			arr[temp-1] = 1;
		}
		else if (str == "remove") {
			//remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) 
			// S�� x�� ���� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			arr[temp-1] = 0;
		}
		else if (str == "check") {
			// check x: S�� x�� ������ 1��, 
			// ������ 0�� ����Ѵ�. (1 �� x �� 20)
			cin >> temp;
			cout << arr[temp-1] << "\n";
		}
		else if (str == "toggle") {
			// toggle x : S�� x�� ������ x�� �����ϰ�, 
			// ������ x�� �߰��Ѵ�. (1 �� x �� 20)
			cin >> temp;
			if (arr[temp-1] == 1) arr[temp-1] = 0;
			else  arr[temp-1] = 1;
		}
		else if (str == "all") {
			// all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
			for (int i = 0; i < 20; i++) arr[i] = 1;
		}
		else {
			// empty: S�� ���������� �ٲ۴�. 
			fill(arr, arr + 20, 0);
		}
	}

	return 0;
}

*/

#include <iostream>

using namespace std;

int S = 0; // ��Ʈ����ŷ
string str;
int N, temp;

int main() {

	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while(N-- > 0) {

		cin >> str;
		if (str == "add") {
			// add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) 
			// S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			S = S | (1 << temp);
		}
		else if (str == "remove") {
			//remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) 
			// S�� x�� ���� ��쿡�� ������ �����Ѵ�.
			cin >> temp;
			S = S & ~(1 << temp);
		}
		else if (str == "check") {
			// check x: S�� x�� ������ 1��, 
			// ������ 0�� ����Ѵ�. (1 �� x �� 20)
			cin >> temp;
			if (S & (1 << temp)) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "toggle") {
			// toggle x : S�� x�� ������ x�� �����ϰ�, 
			// ������ x�� �߰��Ѵ�. (1 �� x �� 20)
			cin >> temp;
			if (S & (1 << temp)) {
				S = S & ~(1 << temp);
			}
			else {
				S = S | (1 << temp);
			}
		}
		else if (str == "all") {
			// all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
			S = (1 << 21) - 1;
		}
		else {
			// empty: S�� ���������� �ٲ۴�. 
			S = 0;
		}
	}

	return 0;
}