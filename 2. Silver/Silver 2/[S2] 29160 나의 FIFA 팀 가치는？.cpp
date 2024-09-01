#include <iostream>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 11

int main()
{
    FastIO;

    int n, k;
    cin>>n >> k;

    array<priority_queue<int>, MAX + 1> players;
    for (int i = 0; i < n; i++)
    {
        int p, w;
        cin>>p >> w;

        players[p].push(w);
    }

    for (int i = 1; i <= MAX; i++)
    {
        int t = k;
        while (!players[i].empty() && t > 0)
        {
            int value = players[i].top();
            if (value > 0)
                players[i].push(value - 1);
            players[i].pop();
            t--;
        }
    }

    long long result = 0;
    for (int i = 1; i <= MAX; i++)
        result += (!players[i].empty() ? players[i].top() : 0);
    cout << result << '\n';
}