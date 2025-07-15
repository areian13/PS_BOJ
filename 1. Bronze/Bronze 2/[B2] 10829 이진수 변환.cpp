#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Bin(long long n)
{
    string result = "";
    do
    {
        result += (n & 1) + '0';
        n >>= 1;
    } while (n > 0);

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    long long n;
    cin >> n;

    string result = Bin(n);
    cout << result << '\n';
}