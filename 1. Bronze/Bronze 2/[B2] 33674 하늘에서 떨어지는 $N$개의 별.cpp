#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, d, k;
    cin >> n >> d >> k;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int result = 0;
    vector<int> cnt(n, 0);
    for (int day = 1; day <= d; day++)
    {
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] + s[i] > k)
            {
                result++;
                for (int j = 0; j < n; j++)
                    cnt[j] = s[j];
                break;
            }
            cnt[i] += s[i];
        }
    }
    cout << result << '\n';
}