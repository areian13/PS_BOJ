#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s(n + 1);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    if (s[1] - s[0] == s[2] - s[1])
        s[n] = s[n - 1] + (s[1] - s[0]);
    else
        s[n] = s[n - 1] * (s[1] / s[0]);

    int result = s[n];
    cout << result << '\n';
}