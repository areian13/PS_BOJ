#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;

        result += a[b - 1];
    }
    cout << result << '\n';
}