#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b;
    string c;
    cin >> a >> b >> c;

    for (int i = 0; i < ((c.back() - '0') & 1); i++)
        a ^= b;
    cout << a << '\n';
}