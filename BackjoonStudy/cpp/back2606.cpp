#include <iostream>
#include <queue>

using namespace std;

// ��ǻ���� �� N, ����� K
int N, K, B, cnt = 0;

queue<int> myQueue;

pair<int, int> temp;

// ������ ��Ÿ����.
bool connect[101][101];

// ��ǻ���� ���� ����
bool computer[101];


int main()
{
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> temp.first >> temp.second;
		// ��������� ����
		connect[temp.first][temp.second] = true;
		connect[temp.second][temp.first] = true;
	}
	
	// 1�� ��ǻ�͸� ������Ű��
	computer[1] = true;
	myQueue.push(1); // ť�� �־��ش�.

	// BFS Ž�� ����
	while (!myQueue.empty()) {

		B = myQueue.front();
		myQueue.pop();

		for (int i = 1; i <= N; i++) {

			// ��ǻ�Ͱ� ������ ���� �ʾҴ�. => �Ѿ��.
			if (connect[B][i] == false && connect[i][B] == false) continue;
			else if (computer[i] == true) continue; 
			// �̹� ������ �Ǿ��ִ�. => �Ѿ��.

			// �ش� ��ǻ�͸� ������Ű��
			computer[i] = true;
			cnt++; // ������ ī��Ʈ�� �÷��ش�.
			myQueue.push(i); // ť�� �־��ش�.
		}
	}

	cout << cnt;

	return 0;
}