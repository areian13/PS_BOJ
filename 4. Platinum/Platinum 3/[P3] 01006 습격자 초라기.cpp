#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Tile(int s, int w, vector<vector<int>>& v,
    vector<int>& out, vector<int>& in, vector<int>& both)
{
    int n = v[0].size();
    for (int i = s; i < n; i++)
    {
        both[i + 1] = min(in[i], out[i]) + 1;
        if (v[0][i] + v[1][i] <= w)
            both[i + 1] = min(both[i + 1], both[i] + 1);

        if (i > 0 && v[0][i - 1] + v[0][i] <= w && v[1][i - 1] + v[1][i] <= w)
            both[i + 1] = min(both[i + 1], both[i - 1] + 2);

        if (i + 1 < n)
        {
            out[i + 1] = in[i + 1] = both[i + 1] + 1;

            if (v[0][i] + v[0][i + 1] <= w)
                out[i + 1] = min(out[i + 1], in[i] + 1);

            if (v[1][i] + v[1][i + 1] <= w)
                in[i + 1] = min(in[i + 1], out[i] + 1);
        }
    }
}

int Onetagon(int w, vector<vector<int>>& v)
{
    int n = v[0].size();
    if (n == 1) 
        return (v[0][0] + v[1][0] <= w ? 1 : 2);

    vector<int> out(n), in(n), both(n + 1);
    out[0] = in[0] = 1, both[0] = 0;

    Tile(0, w, v, out, in, both);
    int result = both[n];

    int outv = v[0][0] + v[0][n - 1];
    int inv = v[1][0] + v[1][n - 1];
    if (outv <= w && inv <= w)
    {
        out[1] = in[1] = 1;
        both[1] = 0;

        Tile(1, w, v, out, in, both);
        result = min(result, both[n - 1] + 2);
    }
    if (outv <= w)
    {
        out[1] = 2;
        in[1] = (v[1][0] + v[1][1] <= w ? 1 : 2);
        both[1] = 1;

        Tile(1, w, v, out, in, both);
        result = min(result, in[n - 1] + 1);
    }
    if (inv <= w)
    {
        out[1] = (v[0][0] + v[0][1] <= w ? 1 : 2);
        in[1] = 2;
        both[1] = 1;

        Tile(1, w, v, out, in, both);
        result = min(result, out[n - 1] + 1);
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, w;
        cin >> n >> w;

        vector<vector<int>> v(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        }

        int result = Onetagon(w, v);
        cout << result << '\n';
    }
}