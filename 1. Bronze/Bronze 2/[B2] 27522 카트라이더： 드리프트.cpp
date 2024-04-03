#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 8

struct Grade
{
    string time;
    char team;

    bool operator<(Grade c)
    {
        return time < c.time;
    }
};

string Winner(array<Grade, MAX>& grade)
{
    sort(grade.begin(), grade.end());

    array<int, 2> score = { 0,0 };
    for (int i = 0; i < MAX; i++)
        score[grade[i].team == 'B'] += (10 - i * 2);

    if (score[0] != score[1])
        return (score[0] > score[1] ? "Red" : "Blue");
    return (grade[0].team == 'R' ? "Red" : "Blue");
}

int main()
{
    FastIO;

    array<Grade, MAX> grade;
    for (int i = 0; i < MAX; i++)
        cin >> grade[i].time >> grade[i].team;

    string result = Winner(grade);
    cout << result << '\n';
}