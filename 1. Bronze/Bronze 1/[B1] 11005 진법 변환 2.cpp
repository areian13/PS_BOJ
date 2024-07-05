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

string DecToBase(int n, int b)
{
    string result = "";
    do
    {
        result += itoc(n % b);
        n /= b;
    } while (n > 0);

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    FastIO;

    int n, b;
    cin >> n >> b;

    string result = DecToBase(n, b);
    cout << result << '\n';
}