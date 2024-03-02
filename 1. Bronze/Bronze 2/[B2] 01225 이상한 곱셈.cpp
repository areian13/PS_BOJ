#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    long long aSum = 0;
    for (char c : a)
        aSum += (c - '0');

    long long bSum = 0;
    for (char c : b)
        bSum += (c - '0');

    long long result = aSum * bSum;
    cout << result << '\n';
}