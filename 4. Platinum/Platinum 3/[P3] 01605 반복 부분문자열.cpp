#include <iostream>
#include <string>
#include <array>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 100'003

int Mod(long long n)
{
    if (n >= 0)
        return n % MOD;
    return ((-n / MOD + 1) * MOD + n) % MOD;
}

int main()
{
    FastIO;

    int l;
    string s;
    cin >> l >> s;

    int result = 0;
    int start = 0, end = l - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        vector<vector<int>> idxHash(MOD);
        int hash = 0, power = 1;
        bool isFound = false;
        for (int i = 0; i < l - mid + 1; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < mid; j++)
                {
                    hash = Mod(hash + (long long)s[mid - 1 - j] * power);
                    if (j < mid - 1)
                        power = Mod(power * 2);
                }
            }
            else
                hash = Mod((hash - (long long)s[i - 1] * power) * 2 + s[i + mid - 1]);

            for (int idx : idxHash[hash])
            {
                for (int j = 0; j < mid; j++)
                {
                    if (s[idx + j] != s[i + j])
                        break;
                    if (j == mid - 1)
                        isFound = true;
                }

                if (isFound)
                    break;
            }

            if (isFound)
                break;
            else
                idxHash[hash].push_back(i);
        }

        if (isFound)
        {
            result = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << result << '\n';
}