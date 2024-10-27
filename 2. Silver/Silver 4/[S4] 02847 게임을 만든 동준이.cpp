#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    int result = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (scores[i] < scores[i + 1])
            continue;

        int desc = scores[i] - scores[i + 1] + 1;
        result += desc;
        scores[i] -= desc;
    }

    cout << result << '\n';
}