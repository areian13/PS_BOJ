#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char itoc(int n)
{
    if (0 <= n && n <= 9)
        return n + '0';
    return n - 10 + 'A';
}

string Convert10ToBase(int n, int b)
{
    string result = "";
    while (n > 0)
    {
        result += itoc(n % b);
        n /= b;
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    FastIO;

    int n, b;
    cin >> n >> b;

    string result = Convert10ToBase(n, b);
    cout << result << '\n';
}