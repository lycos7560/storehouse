#include <iostream>

using namespace std;

// 0 = H, 1 = I, 2 = A, 3 = R, 4 = C
int arr[5];

int main()
{
	int N = 0;
	char tempC;

	cin >> N;
	
	while (N-- > 0) {
		cin >> tempC;
		switch (tempC)
		{
			case 'H':
				arr[0]++;
				break;
			case 'I':
				arr[1]++;
				break;
			case 'A':
				arr[2]++;
				break;
			case 'R':
				arr[3]++;
				break;
			case 'C':
				arr[4]++;
				break;
		}
	}

	int temp = INT32_MAX;
	for (int i = 0; i < 5; i++) {
		if (temp > arr[i]) {
			temp = arr[i];
		}
	}

	cout << temp;
	return 0;
} 
