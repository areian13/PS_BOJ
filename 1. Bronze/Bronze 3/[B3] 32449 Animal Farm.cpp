#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> inf(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        string s;
        int k;
        cin >> s >> k;

        int idx = (s == "pig" ? 0 : i);
        inf[idx] = max(inf[idx], k);
    }

    long long result = inf[0];
    for (int k : inf)
    {
        if (k < inf[0])
            result += k;
    }
    cout << result << '\n';
}