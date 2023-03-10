#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	string str, temp;
	int age, height;
	while (true) {
		cin >> str >> age >> height;
		if (str == "#") break;
		else {
			if (age > 17 || height >= 80) temp = "Senior";
			else temp = "Junior";				
		}
		cout << str << " " << temp << "\n";
	}

	return 0;
}