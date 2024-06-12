#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountGCD(int a, int b)
{
    static int result = 0;
    if (a == b)
        return result;
    result++;
    return CountGCD(max(a, b) - min(a, b), min(a, b));
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = CountGCD(a, b);
    cout << result << '\n';
}