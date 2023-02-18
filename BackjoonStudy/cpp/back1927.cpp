#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> myPQ;

int N, temp;

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N-- > 0) {
		cin >> temp;

		if (temp == 0 && myPQ.empty()) { 
			cout << 0 << "\n";
			continue;
		}
		else if (temp == 0 && !myPQ.empty()) {
			cout << myPQ.top() << "\n";
			myPQ.pop();
			continue;
		}

		myPQ.push(temp);
	}

	return 0;
}