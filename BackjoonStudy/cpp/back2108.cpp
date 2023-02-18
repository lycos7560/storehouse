#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int N, tempI, tempK, temp, tempJ;
int arr[500001];
int number[8001];
long long int sumAll;
list<float> myList; // ����� ������ ����Ʈ
list<float> myList2; 

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);
	sumAll = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; // N��ŭ �Է��� ����
		if (arr[i] > 0) number[arr[i] + 4000]++; // ����� ���
		else number[arr[i] * -1]++;
	}
		
	for (int i = 0; i < N; i++)  // ������ ����
		sumAll = sumAll + arr[i];

	// 1. ������ : N���� ������ ���� N���� ���� ��
	float tempN = sumAll;
	myList.push_back(floor((tempN / N) + 0.5));

	// 2. �߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
	sort(arr, arr + N); // �������� ����

	myList.push_back(arr[(0 + (N))/2]);

	// 3. �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
	tempK = 0, tempI = -9999, tempJ = 0;
	int first = 0, second = 0;
	for (int i = 0; i < 8001; i++) {
		if (i <= 4000) {
			if (number[i] > tempI ) {
				tempI = number[i];
				tempK = i * -1;
				myList2.clear();
				myList2.push_back(tempK);
			}
			else if (number[i] == tempI) {
				tempK = i * -1;
				myList2.push_back(tempK);
			}
		}
		else {
				if (number[i] > tempI) {
					tempI = number[i];
					tempN = i - 4000;
					myList2.clear();
					myList2.push_back(tempN);
				}
				else if (number[i] == tempI) {
					tempK = i - 4000;
					myList2.push_back(tempK);
				}
		}
	}

	myList2.sort();

	int size = myList2.size();
	int cnt = 0;

	if (size >= 2) cnt = 2;
	else cnt = 1;

	for (auto it = myList2.begin(); it != myList2.end(); it++) {
		cnt--;
		if (cnt == 0) {
			myList.push_back(*it);
			break;
		}
	}

	// 4. ���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
	temp = arr[0] - arr[N-1];
	temp = abs(temp);
	myList.push_back(temp);


	// ����� ����մϴ�.
	for (auto it = myList.begin(); it != myList.end(); it++) {
		cout << *it << "\n";
	}

	return 0;
}