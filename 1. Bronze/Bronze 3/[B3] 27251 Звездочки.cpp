#include <iostream>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k = min(i * i, 100);

        string result(k, '*');
        if (i * i > 100)
            result += "...";
        cout << result << '\n';
    }
}