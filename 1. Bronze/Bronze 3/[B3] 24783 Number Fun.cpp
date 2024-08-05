#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanOper(int a, int b, int c)
{
    for (int i = 0; i < 2; i++)
    {
        if (a + b == c)
            return true;
        if (a - b == c)
            return true;
        if (a * b == c)
            return true;
        if (a % b == 0 && a / b == c)
            return true;
        swap(a, b);
    }
    return false;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        string result = CanOper(a, b, c) ? "Possible" : "Impossible";
        cout << result << '\n';
    }
}