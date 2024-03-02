#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> card(n);
    for (int i = 0; i < n; i++)
        cin >> card[i];

    int result = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int sum = card[i] + card[j] + card[k];
                if (sum <= m)
                    result = max(result, sum);
            }
        }
    }
    cout << result << '\n';
}