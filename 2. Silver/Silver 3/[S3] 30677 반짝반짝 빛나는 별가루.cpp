#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, c, r;
    cin>> n >> k >> c >> r;

    vector<int> base(k);
    for (int i = 0; i < k; i++)
        cin>>base[i];

    vector<int> s(k);
    for (int i = 0; i < k; i++)
        cin>>s[i];

    vector<int> p(k);
    for (int i = 0; i < k; i++)
        cin>>p[i];

    vector<int> skill(k, 0);

    long long result = 0;
    int combo = 0;
    int fatigue = 0;
    while (n--)
    {
        int l;
        cin>> l;

        if (l == 0)
        {
            fatigue = max(fatigue - r, 0);
            combo = 0;
            continue;
        }

        l--;
        result += base[l]
            * (1 + (long long)combo * c / 100.0)
            * (1 + (long long)skill[l] * s[l] / 100.0);

        combo++;
        skill[l]++;
        fatigue += p[l];

        if (fatigue > 100)
        {
            result = -1;
            break;
        }
    }
    cout << result << '\n';
}