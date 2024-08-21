#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ParticipantType(array<int, 9>& score, array<int, 9>& maxScore)
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        if (score[i] > maxScore[i])
            return "hacker";
        sum += score[i];
    }

    if (sum >= 100)
        return "draw";
    return "none";
}

int main()
{
    FastIO;

    array<int, 9> maxScore = { 100,100,200,200,300,300,400,400,500 };

    array<int, 9> score;
    for (int i = 0; i < 9; i++)
        cin >> score[i];

    string result = ParticipantType(score, maxScore);
    cout << result << '\n';
}