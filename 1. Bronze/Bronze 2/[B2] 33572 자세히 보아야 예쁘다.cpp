#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    long long m;
    cin >> n >> m;

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum += a - 1;
    }

    bool result = (sum >= m);
    cout << (result ? "DIMI" : "OUT") << '\n';
}