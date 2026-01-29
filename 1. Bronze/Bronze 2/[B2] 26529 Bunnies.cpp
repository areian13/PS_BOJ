#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 45;

int main()
{
    FastIO;

    vector<int> fib(MAX + 1, 1);
    for (int i = 2; i <= MAX; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << fib[n] << '\n';
    }
}