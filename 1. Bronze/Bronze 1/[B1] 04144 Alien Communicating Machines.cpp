#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ACM(long long p, int q)
{
    string result = "";
    do
    {
        result += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[p % q];
        p /= q;
    } while (p > 0);
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int x, y;
        string z;
        cin >> x >> y >> z;

        long long p = stoll(z, 0, x);
        string result = ACM(p, y);
        cout << result << '\n';
    }
}