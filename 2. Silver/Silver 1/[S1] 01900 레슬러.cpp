#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Player
{
    int idx;
    int power;
    int ring;
    int win;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Player> players(n);
    for (int i = 0; i < n; i++)
    {
        int power;
        int ring;
        cin >> power >> ring;

        players[i] = { i,power,ring,0 };
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = players[i].power + players[j].power * players[i].ring;
            int b = players[j].power + players[i].power * players[j].ring;

            players[a > b ? i : j].win++;
        }
    }
    sort(players.begin(), players.end(),
        [](Player& a, Player& b)
        {
            return a.win > b.win;
        }
    );

    for (int i = 0; i < n; i++)
        cout << players[i].idx + 1 << '\n';;
}