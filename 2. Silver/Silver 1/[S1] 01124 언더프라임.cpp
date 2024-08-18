#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    vector<int> cntPrime(b + 1, 0);
    for (int i = 2; i <= b; i++)
    {
        if (cntPrime[i] != 0)
            continue;

        for (long long num = i; num <= b; num *= i)
        {
            for (int j = 1; num * j <= b; j++)
                cntPrime[num * j]++;
        }
    }

    int result = 0;
    for (int num = a; num <= b; num++)
        result += (cntPrime[cntPrime[num]] == 1);
    cout << result << '\n';
}