#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> num(n);
    vector<int> incDP(n, 1), decDP(n, 0);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[j] < num[i])
                incDP[i] = max(incDP[i], incDP[j] + 1);
            if (num[n - j - 1] < num[n - i - 1])
                decDP[n - i - 1] = max(decDP[n - i - 1], decDP[n - j - 1] + 1);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, incDP[i] + decDP[i]);
    cout << result << '\n';
}