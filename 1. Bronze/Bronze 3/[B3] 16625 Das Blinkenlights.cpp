#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p, q, s;
    cin >> p >> q >> s;

    bool sameTime = false;
    for (int i = 1; i <= s; i++)
        sameTime |= (i % p == 0 && i % q == 0);

    string result = (sameTime ? "yes" : "no");
    cout << result << '\n';
}