#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, float>> myVector;

int stagePerson[501];

bool compare(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (auto& it : stages) stagePerson[it]++;
    int MaxNumPeople = stages.size();
    for (int i = 1; i <= N; i++) {
        if (MaxNumPeople == 0) myVector.push_back(make_pair(i, 0));
        else 
        {
            myVector.push_back(make_pair(i, (float)stagePerson[i] / (float)MaxNumPeople));
            MaxNumPeople -= stagePerson[i];
        }
    }
    sort(myVector.begin(), myVector.end(), compare);
    for (auto& it : myVector) answer.push_back(it.first);
    return answer;
}