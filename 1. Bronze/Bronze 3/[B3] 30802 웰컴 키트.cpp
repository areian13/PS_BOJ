#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 6> s;
    for (int i = 0; i < 6; i++)
        cin >> s[i];

    int t, p;
    cin >> t >> p;

    int tSet = 0;
    for (int i = 0; i < 6; i++)
        tSet += s[i] == 0 ? 0 : ((s[i] - 1) / t + 1);

    int pSet = n / p;
    int pInd = n % p;

    cout << tSet << '\n';
    cout << pSet << ' ' << pInd << '\n';
}