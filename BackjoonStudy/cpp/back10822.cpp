#include <iostream>
#include <cstdlib>

using namespace std;

int res;
string str, num;

int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            res += atoi(num.c_str());
            num = "";
            continue;
        }
        num.push_back(str[i]);
    }
    res += atoi(num.c_str());

    cout << res;

    return 0;
}