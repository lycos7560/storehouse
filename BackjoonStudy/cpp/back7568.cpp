#include <iostream>

using namespace std;

int weight[51], height[51], ranks[51];

int N, temp;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> height[i];
	}

	for (int i = 1; i <= N; i++) {

		// 순위는 N등 부터 시작
		temp = N;

		for (int j = 1; j <= N ; j++) {
			
			// 자기 자신과 비교할 경우에는 넘어간다.
			if (i == j) { continue; }

			// 비교 기준의 무게가 더 크거나 같을 경우 rank 상승
			// 비교 기준의 키가 더 크거나 같을 경우 rank 상승
			if (weight[i] >= weight[j]) temp--;
			else if (height[i] >= height[j]) temp--;
		}

		ranks[i] = temp;
	}

	for (int i = 1; i <= N; i++) {
		cout << ranks[i] << " ";
	}

	return 0;
}