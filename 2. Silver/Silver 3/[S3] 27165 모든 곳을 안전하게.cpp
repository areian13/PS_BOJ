#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

pair<int, int> SafeMove(int x, vector<int>& horse)
{
    int n = horse.size();

    int k = 0;
    for (int i = 0; i < n; i++)
        k += (horse[i] == 1);

    if (k == 0)
    {
        for (int i = 0; i + x < n; i++)
        {
            if (horse[i] > 2 && horse[i + x] >= 2)
                return { i, i + x };
        }
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (horse[i] != 1)
                continue;

            if (i + x < n && horse[i + x] != 0)
                return { i, i + x };
            if (i - x >= 0 && horse[i - x] > 2)
                return { i - x, i };
        }
    }
    if (k == 2)
    {
        for (int i = 0; i + x < n; i++)
        {
            if (horse[i] == 1 && horse[i + x] == 1)
                return{ i,i + x };
        }
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;
    n++;

    vector<int> horse(n);
    int cntOne = 0;
    for (int i = 0; i < n; i++)
        cin >> horse[i];

    int x;
    cin >> x;

    pair<int, int> result = SafeMove(x, horse);
    if (result == make_pair(-1, -1))
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        cout << result.first << ' ' << result.second << '\n';
    }
}