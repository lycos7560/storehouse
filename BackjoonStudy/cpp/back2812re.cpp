#include <iostream>
#include <string>

using namespace std;

int n, k;
char c;
string number = "";

void initalization()
{
	cin >> n >> k;

	int temp = n;
	while (temp > 0)
	{
		cin >> c;
		number.push_back(c);
		temp--;
	}
}

void test(int pivot, int k)
{
	if (k <= 0) { return; }
	
	int maxnumberidx = 0;
	int numbercheck = -1;
	cout << "���� pivot : " << pivot << " ���� ���� ���� k : " << k << "\n";
	for (int i = pivot; i <= k + pivot; i++)
	{
		if (numbercheck < number[i] - '0')
		{
			numbercheck = number[i] - '0';
			maxnumberidx = i;
		}
	}
	
	cout << "����ū �� : " << numbercheck << " �ε��� ��ȣ : " << maxnumberidx << "\n";

	if (k == number.length() - 1)
	{
		if (k == 1)
		{
			numbercheck = 10;
			cout << "numbercheck : " << numbercheck << " \n";
			cout << "pivot : " << pivot << " number.length() : " << number.length() << "\n";
			for (int i = pivot; i <= number.length() - 1; i++)
			{
				cout << numbercheck << " �� " << number[i] - '0' << "\n";
				if (numbercheck > number[i] - '0')
				{
					cout << " ���� number[i] - '0' :  " << number[i] - '0' << "\n";
					numbercheck = number[i] - '0';
					maxnumberidx = i;

				}

			}


			cout << "-------------------------------------------------" << "\n";
			cout << "���� �� ��� : " << number << " maxnumberidx : " << maxnumberidx << "\n";
			number.erase(number.begin() + maxnumberidx, number.begin() + maxnumberidx + 1);
			cout << "���� �� ��� : " << number << "\n";
			cout << "-------------------------------------------------" << "\n";
			return;
		}
	}

	cout << "-------------------------------------------------" << "\n";
	cout << "���� �� ��� : " << number << "\n";
	number.erase(number.begin() + pivot, number.begin() + maxnumberidx);
	cout << "���� �� ��� : " << number << "\n";
	cout << "-------------------------------------------------" << "\n";
	test(pivot + 1, k - (maxnumberidx - pivot) );
}

int main()
{
	initalization();
	
	test(0, k);
	//cout << "n : " << n << " k : " << k << "  number : " << number << "\n";
}