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
    int cnt = 0;
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt = (pre < a ? cnt + 1 : 1);
        result = max(result, cnt);

        pre = a;
    }
    cout << result << '\n';
}