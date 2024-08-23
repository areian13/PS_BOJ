#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    bool t = 0;
    while (a < 5 && b < 5)
    {
        if (t == 0)
            b += a;
        else
            a += b;
        t = !t;
    }

    string result = (a < 5 ? "yt" : "yj");
    cout << result << '\n';
}