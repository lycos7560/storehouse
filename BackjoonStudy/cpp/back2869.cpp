#include <iostream>

using namespace std;

// A �ö󰡴� �Ÿ�, B �̲������� �Ÿ�, V ��ǥ ����
int A, B, V, result = 1;

int main()
{
	cin >> A >> B >> V;

	V -= A;

	if (V % (A - B) == 0) { result += V / (A - B); }
	else {
		result += V / (A - B);
		result++;
	}

	cout << result;

	return 0;
}