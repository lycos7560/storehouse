#include <iostream>
#include <list>

using namespace std;

// T : �׽�Ʈ ���̽��� ��, H : ȣ���� �� ��(����), 
// W : �� ���� �� ��(�ʺ�), N : �� ��° �մ�
int T, H, W, N, temp, temp2;

list<int> myList;

int main()
{
	cin >> T;
	while (T-- > 0) {

		cin >> H >> W >> N;


		temp = N % H;
		// 21���� % 4�� = 1���� ��� 
		// 
		// �������� ���ٴ� ���� �ְ� ���̿� ���� ���� ����.

		if (temp == 0) { 
			temp = H; 
			temp2 = (N / H);
		}
		else { 
			// �������� �ִٸ� �ְ����� �Ѿ��ٴ� ���̹Ƿ� ȣ�� + 1
			temp2 = (N / H) + 1;
		}

		myList.push_back((temp * 100) + temp2); // ���� * 100 + ȣ��
	}
	
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}