#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = (n != m ? (min(n, m) - 1) * (min(n, m) - 1) : (n - 2) * (n - 2) + 1);
    cout << result << '\n';
}