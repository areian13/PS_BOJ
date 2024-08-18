#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int q;
    cin >> q;

    int cnt = 0;
    while (q--)
    {
        int n;
        cin >> n;

        cnt += (n == 2);
    }

    string result(cnt, '\n');
    cout << result;
}