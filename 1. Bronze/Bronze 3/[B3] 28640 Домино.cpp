#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetIdx(string& str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '|')
            return i;
    }
}

bool CanAssemble(string& a, string& b)
{
    int aIdx = GetIdx(a);
    int bIdx = GetIdx(b);

    array<array<int, 2>, 2> cnt;
    cnt[0] = { aIdx, (int)a.size() - aIdx - 1 };
    cnt[1] = { bIdx, (int)b.size() - bIdx - 1 };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (cnt[0][i] == cnt[1][j])
                return true;
        }
    }
    return false;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    string result = (CanAssemble(a, b) ? "Yes" : "No");
    cout << result << '\n';
}