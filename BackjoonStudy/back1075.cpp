#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, f, result;
	cin >> n >> f;

	result = int32_max;
	for (int i = 99; i >= 0; i--) {
		if ((((n / 100) * 100) + i) % f == 0) result = i;
	}
	string str;
	str = to_string(result);
	if (str.length() == 1) str.insert(0, "0");
	cout << str;

	return 0;
}