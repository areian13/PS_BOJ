#include <iostream>
#include <unordered_map>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBin(string& s)
{
    for (char c : s)
    {
        if (c != '0' && c != '1')
            return false;
    }
    return true;
}

int CalcForm(int p, vector<vector<bool>>& bin, vector<vector<int>>& beOpId, vector<int>& op)
{
    int n = bin.size() - 1;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (op[i] == 1)
            bin[i][p] = bin[beOpId[i][0]][p] & bin[beOpId[i][1]][p];
        else if (op[i] == 2)
            bin[i][p] = bin[beOpId[i][0]][p] | bin[beOpId[i][1]][p];
        else if (op[i] == 3)
            bin[i][p] = bin[beOpId[i][0]][p] ^ bin[beOpId[i][1]][p];
        result += bin[i][p];
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> bin(n + 1, vector<bool>(m, 0));
    vector<vector<int>> beOpId(n + 1, vector<int>(2));
    unordered_map<string, int> id;
    id["?"] = n;

    vector<int> op(n + 1);
    op[id["?"]] = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        id[s] = i;

        cin >> s >> s;

        if (IsBin(s))
        {
            op[i] = 0;
            for (int j = 0; j < m; j++)
                bin[i][j] = s[j] - '0';
        }
        else
        {
            beOpId[i][0] = id[s];

            cin >> s;
            if (s == "AND")
                op[i] = 1;
            else if (s == "OR")
                op[i] = 2;
            else
                op[i] = 3;

            cin >> s;
            beOpId[i][1] = id[s];
        }
    }

    vector<vector<bool>> result(2, vector<bool>(m));
    for (int i = 0; i < m; i++)
    {
        bin[id["?"]][i] = 0;
        int a = CalcForm(i, bin, beOpId, op);
        bin[id["?"]][i] = 1;
        int b = CalcForm(i, bin, beOpId, op);

        result[0][i] = (a > b);
        result[1][i] = (a < b);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
            cout << result[i][j];
        cout << '\n';
    }
}