#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int tc;
        cin >> tc;

        if (tc == 0)
            break;

        while (tc--)
        {
            int cnt = 0;
            char result;
            for (int i = 0; i < 5; i++)
            {
                int num;
                cin >> num;

                if (num <= 127)
                {
                    cnt++;
                    result = 'A' + i;
                }
            }

            if (cnt != 1)
                result = '*';

            cout << result << '\n';
        }
    }
}