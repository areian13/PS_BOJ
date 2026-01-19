#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string DecCon(int m, int n)
{
    string result = "";
    do
    {
        result += "0123456789ABCDEF"[m % n];
        m /= n;
    } while (m > 0);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    string result = DecCon(m, n);
    cout << result << '\n';
}