#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int n = s.size();
        vector<bool> used(n, false);
        int i = 0;
        string a, b;
        while (!used[i])
        {
            used[i] = true;
            a += s[i];
            b += s[(i + 1) % n];
            i = (i + 2) % n;
        }

        cout << a << '\n' << b << '\n';
    }
}