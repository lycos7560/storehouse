#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

struct RoundResult
{
    int score;
    int bonus;
    int option;
    int Sum;
    RoundResult() {
        score = 0;
        bonus = 1;
        option = 1;
        Sum = 0;
    }
} RoundResult[3];

int solution(string dartResult) {
    int answer = 0;
    int pivot = 0;
    string str = "";
    for (int i = 0; i < 3; i++) {
        for (pivot < dartResult.length();;) {
            if (dartResult[pivot] >= 48 && dartResult[pivot] <= 57) { // 0 ~ 9
                str.push_back(dartResult[pivot]);
                pivot++;
            }
            else {
                RoundResult[i].score = atoi(str.c_str());
                str = "";
                break;
            }
        }

        switch (dartResult[pivot]) {
            case 'S':
                RoundResult[i].bonus = 1;
                pivot++;
                break;
            case 'D':
                RoundResult[i].bonus = 2;
                pivot++;
                break;
            case 'T':
                RoundResult[i].bonus = 3;
                pivot++;
                break;
        }

        switch (dartResult[pivot]) {
            case '*':
                RoundResult[i].option = 2;
                pivot++;
                break;
            case '#':
                RoundResult[i].option = -1;
                pivot++;
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < 3; i++) {
        RoundResult[i].Sum = pow(RoundResult[i].score, RoundResult[i].bonus) * RoundResult[i].option;
        if (RoundResult[i].option == 2 && i - 1 >= 0)RoundResult[i - 1].Sum *= RoundResult[i].option;    
    }

    for (int i = 0; i < 3; i++) answer += RoundResult[i].Sum;
    
    return answer;
}
