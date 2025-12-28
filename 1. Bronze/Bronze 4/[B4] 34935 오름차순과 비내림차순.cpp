#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool result = true;
    for (int i = 0; i < n - 1; i++)
        result &= (a[i] != a[i + 1]);
    cout << result << '\n';
}