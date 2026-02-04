#include <iostream>
#include <map>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;

    friend Pos operator - (const Pos& a, const Pos& b) { return { a.r - b.r,a.c - b.c }; }
    friend auto operator <=> (const Pos& a, const Pos& b) = default;

    double Slope() { return c == 0 ? INF : 1. * r / c; }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    map<char, Pos> pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c != '.')
                pos[c] = { i,j };
        }
    }

    int result = 0;
    for (auto it = pos.begin(); it != prev(pos.end(), 2); it++)
    {
        for (auto jt = next(it); jt != prev(pos.end()); jt++)
        {
            for (auto kt = next(jt); kt != pos.end(); kt++)
            {
                Pos ij = it->second - jt->second;
                Pos jk = jt->second - kt->second;
                result += (ij.Slope() == jk.Slope());
            }
        }
    }
    cout << result << '\n';
}