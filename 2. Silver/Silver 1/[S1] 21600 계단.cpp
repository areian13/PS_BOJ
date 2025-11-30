#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 1, pre = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pre = min(pre + 1, a);
        result = max(result, pre);
    }
    cout << result << '\n';
}