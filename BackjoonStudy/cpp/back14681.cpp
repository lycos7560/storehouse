#include <iostream>

using namespace std;

int x, y;

int main()
{
	cin >> x >> y;
	if (x > 0 && y > 0) cout << 1;
	else if (x < 0 && y > 0) cout << 2;
	else if (x > 0 && y < 0) cout << 4;
	else cout << 3;

	return 0;
}