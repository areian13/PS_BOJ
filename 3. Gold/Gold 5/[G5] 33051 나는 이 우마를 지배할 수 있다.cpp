#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

struct Player
{
    int id;
    int score;
    Player() : id(-1), score(0) {}
    Player(int id, int score) : id(id), score(score) {}
};

int main()
{
    FastIO;

    int n, k, m;
    cin >> n >> k >> m;
    k--, m--;

    vector<int> scores(4, 0);
    vector<vector<int>> rankCount(4, vector<int>(4, 0));
    for (int i = 0; i < n; i++)
    {
        vector<int> ranks(4);
        for (int j = 0; j < 4; j++)
        {
            cin >> ranks[j];
            ranks[j]--;
            rankCount[ranks[j]][j]++;
        }
        for (int j = 0; j < 4; j++)
        {
            int score;
            cin >> score;

            scores[ranks[j]] += score;
        }
    }

    for (int d1 = -100; d1 <= 100; d1++)
    {
        for (int d2 = -100; d2 <= d1; d2++)
        {
            for (int d3 = -100; d3 <= d2; d3++)
            {
                int d4 = -(d1 + d2 + d3);
                if (d4 < -100 || d4 > d3) continue;

                vector<int> tempScores = scores;

                for (int i = 0; i < 4; i++)
                {
                    tempScores[i] += rankCount[i][0] * d1;
                    tempScores[i] += rankCount[i][1] * d2;
                    tempScores[i] += rankCount[i][2] * d3;
                    tempScores[i] += rankCount[i][3] * d4;
                }

                vector<Player> players(4);
                for (int i = 0; i < 4; i++)
                    players[i] = Player(i, tempScores[i]);
                sort(players.begin(), players.end(),
                    [](const Player& a, const Player& b)
                    {
                        if (a.score != b.score) return a.score > b.score;
                        return a.id < b.id;
                    }
                );

                if (players[m].id == k)
                {
                    cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';
}