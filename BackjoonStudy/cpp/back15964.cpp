#include <iostream>

using namespace std;

int N, A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N-- > 0) {
		cin >> A >> B;
		cout << A + B << "\n";
	}

	return 0;
}