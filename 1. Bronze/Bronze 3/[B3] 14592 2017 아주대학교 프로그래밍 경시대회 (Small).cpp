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

    vector<vector<int>> s(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> s[i][0] >> s[i][1] >> s[i][2];

    int result = max_element(s.begin(), s.end(),
        [](const auto& a, const auto& b)
        {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] > b[1];
            return a[2] > b[2];
        }
    ) - s.begin();
    cout << result + 1 << '\n';
}