#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    vector<int> d(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1] + (s[i - 1] == 'D');
        b[i] = b[i - 1] + (s[i - 1] == 'B');
    }

    int result = n;
    for (int i = 0; i <= n; i++)
        result = min(result, d[i] + (b[n] - b[i]));
    cout << result << '\n';
}