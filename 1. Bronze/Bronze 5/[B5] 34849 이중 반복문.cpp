#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    if (n * n <= 1e8)
        cout << "Accepted" << '\n';
    else
        cout << "Time limit exceeded" << '\n';
}