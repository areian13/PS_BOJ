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
    Player(int id, int score) : id(id), score(score) {}
};

int main()
{
    FastIO;

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> scores(5, 0);
    vector<vector<int>> rank_count(5, vector<int>(5, 0));

    for (int i = 0; i < n; i++)
    {
        int a1, a2, a3, a4, s1, s2, s3, s4;
        cin >> a1 >> a2 >> a3 >> a4 >> s1 >> s2 >> s3 >> s4;
        rank_count[a1][1]++;
        rank_count[a2][2]++;
        rank_count[a3][3]++;
        rank_count[a4][4]++;
        scores[a1] += s1;
        scores[a2] += s2;
        scores[a3] += s3;
        scores[a4] += s4;
    }

    for (int d1 = -100; d1 <= 100; d1++)
    {
        for (int d2 = -100; d2 <= d1; d2++)
        {
            for (int d3 = -100; d3 <= d2; d3++)
            {
                int d4 = -(d1 + d2 + d3);
                if (d4 < -100 || d4 > d3) continue;

                vector<int> temp_scores = scores;

                for (int i = 1; i <= 4; i++)
                {
                    temp_scores[i] += rank_count[i][1] * d1;
                    temp_scores[i] += rank_count[i][2] * d2;
                    temp_scores[i] += rank_count[i][3] * d3;
                    temp_scores[i] += rank_count[i][4] * d4;
                }

                vector<Player> players;
                for (int i = 1; i <= 4; i++)
                    players.push_back(Player(i, temp_scores[i]));
                sort(players.begin(), players.end(),
                    [](const Player& a, const Player& b)
                    {
                        if (a.score != b.score) return a.score > b.score;
                        return a.id < b.id;
                    }
                );

                for (int i = 0; i < 4; i++)
                {
                    if (players[i].id == k && i + 1 == m)
                    {
                        cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << '\n';
}