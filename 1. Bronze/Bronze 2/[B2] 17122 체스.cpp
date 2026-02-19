#include <iostream>
#include <string>

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
        int n;
        cin >> s >> n;
        s[0] -= 'A', s[1]--, n--;

        bool result = ((s[0] & 1) ^ (s[1] & 1)) == (((n / 8) & 1) ^ ((n % 8) & 1));
        cout << (result ? "YES" : "NO") << '\n';
    }
}