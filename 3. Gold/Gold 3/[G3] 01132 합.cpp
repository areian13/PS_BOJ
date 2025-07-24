#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct AlpInfo
{
    long long num;
    bool cantZero;
};

bool CompAlp(AlpInfo& a, AlpInfo& b)
{
    return a.num < b.num;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<AlpInfo, 10> alp = { {0, false}, };
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        for (long long j = 0; j < str.size(); j++)
            alp[str[j] - 'A'].num += pow(10, str.size() - j - 1);
        alp[str[0] - 'A'].cantZero = true;
    }
    sort(alp.begin(), alp.end(), CompAlp);

    for (long long i = 0; i < 10; i++)
    {
        if (!alp[i].cantZero)
        {
            for (int j = i; j > 0; j--)
                alp[j] = alp[j - 1];
            break;
        }
    }

    long long result = 0;
    for (long long i = 9; i >= 0; i--)
        result += i * alp[i].num;
    cout << result << '\n';
}