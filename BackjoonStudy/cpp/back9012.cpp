#include <iostream>
#include <list>

using namespace std;

list<string> myList;
string answer[2] = { "NO","YES" };
string temp;
int N, check;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		myList.push_back(temp);
	}

	for (auto it = myList.begin();  it != myList.end(); it++) {
		temp = *it;
		check = 1;
		N = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '(') { N++; }
			else { N--; }
			if (N < 0) { check = 0; } // 한번이라고 음수로 내려가면 안됨 => NO
		}

		if (N != 0) check = 0; // 순회가 끝나고 N이 양수면 (가 남아있다. => NO

		cout << answer[check] << "\n";
	}

	return 0;
}