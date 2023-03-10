#include <iostream>

using namespace std;

constexpr int Max = 1000001;

// ���Ͽ� root��� �迭
int uArr[Max];

int N, M, u, b, c;

//�θ� ã�� �Լ�
//��� ��ΰ� �θ� ����Ű�� ��
//��� �ð��� ���⵵
int Find(int x)
{
	if (uArr[x] == x) return x;
	else return uArr[x] = Find(uArr[x]);
}

//�� ��带 ���� ��Ű�� ��
//������ ���ؼ� �����Ű�� ���� �򰥸��� ����
//�������� �θ� or ū���� �θ�
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (x < y) uArr[y] = x;
		else uArr[x] = y;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); // scanf�� ����ȭ�� ��Ȱ��ȭ
	// cin.tie(null); �ڵ�� cin�� cout�� ������ Ǯ���ݴϴ�.
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// ���Ͽ� �迭 �ʱ�ȭ
	for (int i = 0; i <= N; i++) uArr[i] = i;
	
	for (int i = 0; i < M; i++) {

		cin >> u >> b >> c;

		if (u == 0) { // ������ ����
			Union(b, c);
		}
		else { // ����
			if (Find(b) != Find(c)) cout << "NO\n";
			else cout << "YES\n";			
		}	
	}

	return 0;
}