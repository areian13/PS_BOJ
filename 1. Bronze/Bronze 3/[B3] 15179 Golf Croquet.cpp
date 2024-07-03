#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b, record;
    int s;
    getline(cin, a);
    getline(cin, b);
    cin >> s >> record;

    array<int, 2> score = { 0,0 };
    bool hasWinner = false;
    for (int i = 0; i < s; i++)
    {
        int team = i % 2;
        int otherTeam = (i + 1) % 2;
        switch (record[i])
        {
        case 'H':
            score[team]++;
            break;

        case 'D':
            score[team] += 2;
            break;

        case 'O':
            score[otherTeam]++;
            break;
        }
        if (score[0] >= 7 || score[1] >= 7)
        {
            hasWinner = true;
            break;
        }
    }

    printf("%s %d %s %d. ", a.c_str(), min(score[0], 7), b.c_str(), min(score[1], 7));
    string winner = (score[0] > score[1] ? a : b);
    if (hasWinner)
        printf("%s has won.\n", winner.c_str());
    else if (score[0] != score[1])
        printf("%s is winning.\n", winner.c_str());
    else
        printf("All square.\n");
}