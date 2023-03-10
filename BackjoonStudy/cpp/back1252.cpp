//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//char binary1[100];
//char binary2[100];
//
//void SumBinary(char a[], char b[], int pos, int Round)
//{
//    if (pos < 0 && Round == 0) return;
//    int num = 0;
//    if (pos >= 0) num = a[pos] - '0' + b[pos] - '0';
//    SumBinary(a, b, pos - 1, (Round + num) / 2);
//    cout << (Round + num) % 2;
//}
//
//
//int main()
//{
//    ios_base::sync_with_stdio(false); // scanf와 동기화를 비활성화
//    // cin.tie(null); 코드는 cin과 cout의 묶음을 풀어줍니다.
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//    int first = 0;
//    cin >> binary1 >> binary2;
//    int len1 = strlen(binary1);
//    for (int i = 0; i < len1; i++)
//    {
//        if (binary1[i] != '0') break;
//        first++;
//    }
//
//    strcpy(binary1, binary1 + first);
//    len1 = strlen(binary1);
//
//    first = 0;
//    int len2 = strlen(binary2);
//    for (int i = 0; i < len2; i++)
//    {
//        if (binary2[i] != '0') break;
//        first++;
//    }
//
//    strcpy(binary2, binary2 + first);
//    len2 = strlen(binary2);
//
//    char temp[100] = { 0 };
//    if (len1 > len2)
//    {
//        for (int i = len2; i < len1; i++) temp[i - len2] = '0';
//        strcat(temp, binary2);
//        strcpy(binary2, temp);
//    }
//    else
//    {
//        if (len2 == 0) 
//        {
//            cout << 0;
//            return 0;
//        }
//        for (int i = len1; i < len2; i++) temp[i - len1] = '0';
//        strcat(temp, binary1);
//        strcpy(binary1, temp);
//    }
//
//    SumBinary(binary1, binary2, strlen(binary1) - 1, 0); 
//
//    return 0;
//}