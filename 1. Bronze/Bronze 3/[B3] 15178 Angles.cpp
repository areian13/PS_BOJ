#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        string result = (a + b + c == 180 ? "Seems OK" : "Check");
        cout << a << ' ' << b << ' ' << c << ' ';
        cout << result << '\n';
    }
}