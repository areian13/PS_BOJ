#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    string result = "";
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;

        int p = s.find('X');
        if (p == -1) p = s.find('x');

        result += ('0' <= t[p] && t[p] <= '9' ? t[p] : t[p] & ~32);
    }
    cout << result << '\n';
}