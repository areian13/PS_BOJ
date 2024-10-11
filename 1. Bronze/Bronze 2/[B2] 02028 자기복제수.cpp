#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsSelfReplica(int n)
{
    int d = log10(n) + 1;
    int p10 = pow(10, d);

    return n * n % p10 == n;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        string result = (IsSelfReplica(n) ? "YES" : "NO");
        cout << result << '\n';
    }
}