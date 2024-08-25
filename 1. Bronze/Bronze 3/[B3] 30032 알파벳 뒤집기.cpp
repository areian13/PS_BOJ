#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char Flip(char c, int d)
{
    static array<unordered_map<char, char>, 2> flip;
    static bool isInited = false;

    if (!isInited)
    {
        flip[0]['d'] = 'q';
        flip[0]['b'] = 'p';
        flip[0]['q'] = 'd';
        flip[0]['p'] = 'b';
        flip[1]['d'] = 'b';
        flip[1]['b'] = 'd';
        flip[1]['q'] = 'p';
        flip[1]['p'] = 'q';
        isInited = true;
    }

    return flip[d - 1][c];
}

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    vector<vector<char>> map(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            map[i][j] = Flip(map[i][j], d);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << map[i][j];
        cout << '\n';
    }
}