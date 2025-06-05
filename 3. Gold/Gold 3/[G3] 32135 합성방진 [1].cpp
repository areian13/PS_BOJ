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
    int h = (n + 1) / 2;
    for (int i = 0; i < h; i++)
        a[i] = i * 2 + 1;
    for (int i = 0; i < n / 2; i++)
        a[h + i] = (i + 1) * 2;

    swap(a[3], a[h - 1]);
    swap(a[h + 3], a[n - 1]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[(i + j) % n] << ' ';
        cout << '\n';
    }
}