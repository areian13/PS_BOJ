#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string NumComma(long long num, int n)
{
    string result = "";
    int cnt = 0;
    do
    {
        result += num % 10 + '0';
        num /= 10;
        cnt = (cnt + 1) % n;

        if (cnt == 0)
            result += ',';
    } while (num > 0);
    if (result.back() == ',')
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long x, k, h;
        cin >> x >> k >> h;

        long long result = h * x * 2 + (k - h) * x + max(k - h - 140, 0LL) * x * 0.5;
        cout << NumComma(result, 3) << '\n';
    }
}