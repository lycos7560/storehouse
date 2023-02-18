#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> myMap;

int T , N, result;

string tempO, tempT;

// ���� n C r �� ����ϴ� �Լ�
int Combination(int n, int r)
{
	if (n == r || r == 0) return 1;
	else return Combination(n - 1, r - 1) + Combination(n - 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	//cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> T;

	while (T--) {

		myMap.clear();

		cin >> N;

		while (N--) {

			cin >> tempO >> tempT;

			auto it = myMap.find(tempT);
			
			// ���� map�� �ִٸ� ������ + 1
			// ���ٸ� ������ 1�� ���� �־��ش�.
			if (it != myMap.end()) it->second++;
			else myMap.insert(make_pair(tempT, 1));
			
		}

		result = 1;

		for (auto it = myMap.begin(); it != myMap.end(); it++) {
			result *= Combination(it->second + 1, 1); // �ƹ��͵� ���� �ʴ´� �ϳ� �߰�
		}

		cout << result - 1 << "\n"; // ��� �ǻ��� ������ �Ȼ̴´ٴ� ��츦 ���ش�.

	}

	return 0;
}