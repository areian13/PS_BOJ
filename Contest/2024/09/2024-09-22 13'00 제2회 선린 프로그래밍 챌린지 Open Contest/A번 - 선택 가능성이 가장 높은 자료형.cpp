#include <iostream>
#include <string>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string BestType(long long n)
{
    if (SHRT_MIN <= n && n <= SHRT_MAX)
        return "short";
    if (INT_MIN <= n && n <= INT_MAX)
        return "int";
    return "long long";
}

int main()
{
    FastIO;

    long long n;
    cin >> n;

    string result = BestType(n);
    cout << result << '\n';
}