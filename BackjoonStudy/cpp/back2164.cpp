#include <iostream>
#include <queue>

using namespace std;

int N;

queue<int> myQ;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		myQ.push(i);
	}

	// ť�� ����� 1���� ũ�ٸ� �ݺ�
	while (myQ.size() > 1) { 
		myQ.pop(); // ���� �� ī�带 ������. 

		// �� ���� ī�带 �ٽ� ť�� �ִ´�.
		N = myQ.front(); 
		myQ.pop();
		myQ.push(N);
	}

	// ī�尡 ���� ������ �� ���� ����Ѵ�. 
	cout << myQ.front();
	return 0;
}