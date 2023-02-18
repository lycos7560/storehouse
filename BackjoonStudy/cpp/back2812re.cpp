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
	cout << "시작 pivot : " << pivot << " 남은 지울 숫자 k : " << k << "\n";
	for (int i = pivot; i <= k + pivot; i++)
	{
		if (numbercheck < number[i] - '0')
		{
			numbercheck = number[i] - '0';
			maxnumberidx = i;
		}
	}
	
	cout << "가장큰 수 : " << numbercheck << " 인덱스 번호 : " << maxnumberidx << "\n";

	if (k == number.length() - 1)
	{
		if (k == 1)
		{
			numbercheck = 10;
			cout << "numbercheck : " << numbercheck << " \n";
			cout << "pivot : " << pivot << " number.length() : " << number.length() << "\n";
			for (int i = pivot; i <= number.length() - 1; i++)
			{
				cout << numbercheck << " 비교 " << number[i] - '0' << "\n";
				if (numbercheck > number[i] - '0')
				{
					cout << " 점검 number[i] - '0' :  " << number[i] - '0' << "\n";
					numbercheck = number[i] - '0';
					maxnumberidx = i;

				}

			}


			cout << "-------------------------------------------------" << "\n";
			cout << "삭제 전 결과 : " << number << " maxnumberidx : " << maxnumberidx << "\n";
			number.erase(number.begin() + maxnumberidx, number.begin() + maxnumberidx + 1);
			cout << "삭제 후 결과 : " << number << "\n";
			cout << "-------------------------------------------------" << "\n";
			return;
		}
	}

	cout << "-------------------------------------------------" << "\n";
	cout << "삭제 전 결과 : " << number << "\n";
	number.erase(number.begin() + pivot, number.begin() + maxnumberidx);
	cout << "삭제 후 결과 : " << number << "\n";
	cout << "-------------------------------------------------" << "\n";
	test(pivot + 1, k - (maxnumberidx - pivot) );
}

int main()
{
	initalization();
	
	test(0, k);
	//cout << "n : " << n << " k : " << k << "  number : " << number << "\n";
}