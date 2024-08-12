#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        bool zack = false, mack = false;

        for (int i = 0; i < 10; i++)
        {
            int num;
            cin >> num;

            cout << num << ' ';

            zack |= (num == 17);
            mack |= (num == 18);
        }
        cout << '\n';

        string result = "none";
        if (zack && mack)
            result = "both";
        else if (zack)
            result = "zack";
        else if (mack)
            result = "mack";

        cout << result << "\n\n";
    }
}