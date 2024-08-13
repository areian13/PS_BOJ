#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < 3; i++)
    {
        int pref;
        cin >> pref;

        result += min(n, pref);
    }
    cout << result << '\n';
}