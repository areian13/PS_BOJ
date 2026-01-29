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

    int x, y;
    cin >> x >> y;

    int cntY = 0;
    for (int i = 0; i < n; i++)
        cntY += (a[i] >= y);

    cout << n * x / 100 << ' ' << cntY << '\n';
}