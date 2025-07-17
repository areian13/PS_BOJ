#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int u, unordered_map<int, int>& p)
{
    if (p.count(u) == 0)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, unordered_map<int, int>& p)
{
    u = Find(u, p);
    v = Find(v, p);
    if (u == v)
        return;
    p[u] = v;
}

int MaxColor(int u, int c, vector<vector<int>>& cards,
    unordered_map<int, int>& p)
{
    int n = cards.size();

    int result = 0;
    for (int i = u + 1; i < n; i++)
    {
        int a = Find(cards[i][0], p);
        int b = Find(cards[i][1], p);

        if (a != c && b != c)
        {
            Union(a, c, p);
            int cntA = MaxColor(i, a, cards, p);
            p.erase(a);

            Union(b, c, p);
            int cntB = MaxColor(i, b, cards, p);
            p.erase(b);

            if (cntA > cntB)
            {
                Union(a, c, p);
                result += cntA;
            }
            else
            {
                Union(b, c, p);
                result += cntB;
            }
        }
        else if (a != c)
        {
            Union(a, c, p);
            result++;
        }
        else if (b != c)
        {
            Union(b, c, p);
            result++;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> cards(n + 1, vector<int>(2));
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= n; i++)
            cin >> cards[i][j];
    }

    unordered_map<int, int> p(n);
    int result = MaxColor(0, -1, cards, p);
    cout << result << '\n';
}