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
    int day = 0;
    bool canFreeze = true;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        if (p != 0)
        {
            day++;
            canFreeze = true;
        }
        else
        {
            if (canFreeze)
                canFreeze = false;
            else
            {
                day = 0;
                canFreeze = true;
            }
        }
        result = max(result, day);
    }
    cout << result << '\n';
}