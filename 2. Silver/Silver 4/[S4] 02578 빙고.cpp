#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBingo(vector<vector<bool>>& bingo)
{
    int cnt = 0;
    bool flag;
    for (int i = 0; i < 5; i++)
    {
        flag = true;
        for (int j = 0; j < 5; j++)
            flag &= bingo[i][j];
        cnt += flag;
    }
    for (int j = 0; j < 5; j++)
    {
        flag = true;
        for (int i = 0; i < 5; i++)
            flag &= bingo[i][j];
        cnt += flag;
    }
    flag = true;
    for (int i = 0; i < 5; i++)
        flag &= bingo[i][i];
    cnt += flag;
    flag = true;
    for (int i = 0; i < 5; i++)
        flag &= bingo[i][4 - i];
    cnt += flag;
    return cnt;
}

int main()
{
    FastIO;

    vector<pair<int, int>> idx(25);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int v;
            cin >> v;
            idx[v - 1] = { i,j };
        }
    }

    vector<vector<bool>> bingo(5, vector<bool>(5, false));
    for (int t = 1; t <= 25; t++)
    {
        int v;
        cin >> v;

        auto [i, j] = idx[v - 1];
        bingo[i][j] = true;
        if (CountBingo(bingo) >= 3)
        {
            cout << t << '\n';
            break;
        }
    }
}