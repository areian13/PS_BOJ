#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;

    friend istream& operator >> (istream& is, Pos& p)
    {
        char cc, cr;
        cin >> cc >> cr;
        p.c = cc - 'A', p.r = cr - '0' - 1;
        return is;
    }
    friend ostream& operator << (ostream& os, const Pos& p)
    {
        os << (char)(p.c + 'A') << ' ' << p.r + 1;
        return os;
    }
};

vector<int> dr = { -1,-1,1,1 };
vector<int> dc = { -1,1,1,-1 };

vector<Pos> Bishop(Pos& s, Pos& t)
{
    if (((s.r + s.c) & 1) != ((t.r + t.c) & 1))
        return {};

    int tr = s.r - t.r, tc = s.c - t.c;
    if (tr == 0 && tc == 0)
        return { s };
    if (abs(tr) == abs(tc))
        return { s,t };

    vector<vector<bool>> mat(8, vector<bool>(8, false));
    mat[s.r][s.c] = true;
    for (int i = 0; i < 4; i++)
    {
        auto [r, c] = s;
        while (true)
        {
            r += dr[i];
            c += dc[i];

            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                break;

            mat[r][c] = true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        auto [r, c] = t;
        while (true)
        {
            r += dr[i];
            c += dc[i];

            if (r < 0 || r >= 8 || c < 0 || c >= 8)
                break;
            if (mat[r][c])
                return { s,{r,c},t };
        }
    }
    return {};
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        Pos s, t;
        cin >> s >> t;

        vector<Pos> result = Bishop(s, t);
        if (result.empty())
            cout << "Impossible" << '\n';
        else
        {
            cout << result.size() - 1 << ' ';
            for (Pos& p : result)
                cout << p << ' ';
            cout << '\n';
        }
    }
}