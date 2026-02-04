#include <iostream>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long x;
    cin >> x;
    x++;

    set<long long> result;
    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
            result.insert(i), result.insert(x / i);
    }
    result.erase(prev(result.end()));

    for (long long i : result)
        cout << i << ' ';
    cout << '\n';
}