#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100'000;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<bool> can(MAX * n + 1, false);
    for (int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += s[j];
        }
        can[sum] = true;
    }

    for (int i = 1; i <= MAX * n + 1; i++)
    {
        if (!can[i])
        {
            cout << i << '\n';
            break;
        }
    }
}