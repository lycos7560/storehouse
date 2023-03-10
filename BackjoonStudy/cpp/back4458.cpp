#include <iostream>
#include <string>

using namespace std;

int N;
string str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, str);
		str[0] = toupper(str[0]);
		cout << str << "\n";
	}

	return 0;
}