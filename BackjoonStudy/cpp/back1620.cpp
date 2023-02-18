#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> uSortMap;

int N, M;
string strArr[100001];

int main()
{

	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> strArr[0];
		strArr[i] = strArr[0];
		uSortMap.insert({ strArr[0], i });
	}

	for (int i = 0; i < M; i++) {
		cin >> strArr[0];
		if (strArr[0][0] >= '0' && strArr[0][0] <= '9') {
			cout << strArr[atoi(strArr[0].c_str())] << "\n";
			// atoi(string.c_str())
			// atoi�� �ش��ϴ� ���ڿ��� ���ڸ� ���ڸ� ��ȯ�Ѵ� 
			// ���� �ش��ϴ� ���ڰ� ���ڰ� �ƴ϶�� 0�� ��ȯ
		}
		else {
			cout << uSortMap.find(strArr[0])->second << "\n";
		} 
	}

	return 0;
}