#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(vector<int>& virus, vector<int>& code)
{
    int k = virus.size();
    int n = code.size();

    vector<int> fail(k, 0);
    for (int i = 1, j = 0; i < k; i++)
    {
        while (j > 0 && virus[i] != virus[j])
            j = fail[j - 1];
        if (virus[i] == virus[j])
            fail[i] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && code[i] != virus[j])
            j = fail[j - 1];

        if (code[i] == virus[j])
        {
            if (j == k - 1)
                return true;
            else
                j++;
        }
    }
    return false;
}

bool HasVirus(vector<vector<int>>& codes, int k)
{
    int n = codes.size();
    int m = codes[0].size();

    if (m < k)
        return false;

    sort(codes.begin(), codes.end(),
        [](const vector<int>& a, const vector<int>& b)
        { return a.size() < b.size(); }
    );

    for (int i = 0; i < m - k + 1; i++)
    {
        vector<int> virus(k);
        vector<int> revVirus(k);
        for (int j = 0; j < k; j++)
        {
            virus[j] = codes[0][i + j];
            revVirus[k - 1 - j] = virus[j];
        }

        bool hasAll = true;
        for (int j = 1; j < n; j++)
        {
            if (!IsIn(virus, codes[j]) && !IsIn(revVirus, codes[j]))
            {
                hasAll = false;
                break;
            }
        }

        if (hasAll)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> codes(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        codes[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> codes[i][j];
    }

    string result = (HasVirus(codes, k) ? "YES" : "NO");
    cout << result << '\n';
}