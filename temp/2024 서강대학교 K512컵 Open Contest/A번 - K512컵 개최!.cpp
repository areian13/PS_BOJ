#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long BiggestNumber(vector<long long>& a, vector<long long>& b)
{
    long long result = 0;
    for (long long x : a)
        result += x;

    for (long long x : b)
    {
        if (x != 0)
            result *= x;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    long long result = BiggestNumber(a, b);
    cout << result << '\n';
}