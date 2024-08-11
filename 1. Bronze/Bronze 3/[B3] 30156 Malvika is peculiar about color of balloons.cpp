#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;

        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++)
            result += (s[i] == 'a');
        result = min(result, n - result);
        cout << result << '\n';
    }
}