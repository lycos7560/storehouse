#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

string arr[1000000];

unordered_set<string> uSet;

set<string> mySet;

string str;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N + M; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) uSet.insert(arr[i]);

	for (int i = N; i < N + M; i++) if (uSet.count(arr[i])) mySet.insert(arr[i]);

	cout << mySet.size() << "\n";

	for (auto it = mySet.begin(); it != mySet.end(); it++) cout << *it << "\n";

	return 0;
}