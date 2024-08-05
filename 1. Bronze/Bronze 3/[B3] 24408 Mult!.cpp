#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    bool isStart = true;
    int mod;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (isStart)
        {
            mod = num;
            isStart = false;
            continue;
        }

        if (num % mod == 0)
        {
            cout << num << '\n';
            isStart = true;
        }
    }
}