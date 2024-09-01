#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Base
{
    int cntItem;
    priority_queue<int, vector<int>, greater<int>> floor;
};

bool CanMissionClear(long long p, vector<Base>& bases)
{
    for (Base& base : bases)
    {
        while (!base.floor.empty())
        {
            while (base.cntItem > 0 && p < base.floor.top())
            {
                p *= 2;
                base.cntItem--;
            }

            if (base.cntItem == 0 && p < base.floor.top())
                return false;

            p += base.floor.top();
            base.floor.pop();
        }

        p <<= base.cntItem;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    long long p;
    cin >> n >> m >> p;

    vector<Base> bases(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int s;
            cin >> s;

            if (s == -1)
                bases[i].cntItem++;
            else
                bases[i].floor.push(s);
        }
    }

    bool result = CanMissionClear(p, bases);
    cout << result << '\n';
}