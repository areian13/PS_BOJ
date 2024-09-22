#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void GetPrimeFactors(int n, vector<int>& primeFactors)
{
    while (n != 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                primeFactors.push_back(i);
                n /= i;
                break;
            }
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> result;
    GetPrimeFactors(n, result);

    for (int pf : result)
        cout << pf << '\n';
}