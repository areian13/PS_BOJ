#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    long long sum = 0;
    long long result = 0;
    while (sum <= n)
    {
        result++;
        sum += result * result;
    }
    result--;
    cout << result << '\n';
}