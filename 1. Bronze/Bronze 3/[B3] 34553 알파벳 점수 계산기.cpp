#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    int result = 1, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] < s[i]) cnt++;
        else cnt = 1;

        result += cnt;
    }
    cout << result << '\n';
}