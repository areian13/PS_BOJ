#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a = "SciComLove";

    int n;
    cin >> n;

    if (n % 2 == 1)
        reverse(a.begin(), a.end());

    cout << a << '\n';
}