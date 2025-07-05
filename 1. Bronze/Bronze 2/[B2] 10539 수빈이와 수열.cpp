#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int pre = 0;
    for (int i = 1; i <= n; i++)
    {
        int a = b[i - 1] * i - pre;
        cout << a << ' ';
        pre += a;
    }
}