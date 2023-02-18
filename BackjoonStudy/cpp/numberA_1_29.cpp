#include <iostream>

using namespace std;

int T, S;

int main()
{
	cin >> T >> S;

	if (S == 1 && (T < 12 && T > 16)) cout << 280;
	else if(S == 0 && (12 <= T &&  T <= 16)) cout << 320;
	else cout << 280;
	
	return 0;
}