#include <iostream>

using namespace std;

// A 올라가는 거리, B 미끄러지는 거리, V 목표 높이
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