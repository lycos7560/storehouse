#include <iostream>
#include <queue>
#include <list>

using namespace std;

queue<pair<int, bool>> myQueue; // ������ Q
list <int> resList; // ����� �����ϴ� ����Ʈ

pair<int, bool> tempPair;

int N, temp , number, target, cnt;

int arr[10]; // [i] i�� �߿䵵�� ���� ������ ������ ���� 

int main()
{
	cin >> N;
	while (N-- > 0) {
		
		// �ʱ�ȭ
		for (int i = 1; i <= 9; i++) arr[i] = 0;
		while (!myQueue.empty()) myQueue.pop();
		cnt = 1;

		cin >> number >> target;

		for (int i = 0; i < number; i++) {

			cin >> temp;
			arr[temp]++;

			// ��ǥ�� ������ ��ŷ
			if (target == i) tempPair = make_pair(temp, true);
			else tempPair = make_pair(temp, false);

			myQueue.push(tempPair);
		}

		for (int i = 9; i >= 1; i--) {
			while (arr[i] != 0) { // ���� �߿䵵 �������� ���� ������ 0 �̵ɶ����� ����
				tempPair = myQueue.front();

				if (tempPair.first != i) {
					myQueue.pop();
					myQueue.push(tempPair);
				}
				else 
				{	// ���� ��ǥ���ϴ� ������ ��� (��ŷ�� ����)
					if (tempPair.second == true) {
						resList.push_back(cnt); // �μ�� ������ ����� ���� 
						myQueue.pop();
						arr[i]--;
					}
					else
					{
						arr[i]--;
						cnt++;
						myQueue.pop();
					}
				}
			}
		}
	}

	for (auto it = resList.begin(); it != resList.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}