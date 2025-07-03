#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string a, b;
        cin >> a >> b;

        if (a == "#" && b == "#")
            break;

        int n;
        cin >> n;

        array<int, 2> result = { 0,0 };
        for (int i = 0; i < n; i++)
        {
            char s, c;
            cin >> s >> c;

            result[s != c]++;
        }

        cout << a << ' ' << result[0] << ' ';
        cout << b << ' ' << result[1] << '\n';
    }
}