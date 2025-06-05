#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 5> s = { 0, }, n = { 0, };
    for (int i = 1; i <= 4; i++)
        cin >> s[i];
    for (int i = 1; i <= 4; i++)
        cin >> n[i];

    int qc;
    cin >> qc;

    for (int qn = 1; qn <= qc; qn++)
    {
        int q, k;
        cin >> q >> k;
        q--;

        if (q == 0)
        {
            bool canI = true;
            for (int i = 1; i <= 4; i++)
                canI &= (n[i] * k <= s[i]);

            if (canI)
            {
                s[0] += k;
                for (int i = 1; i <= 4; i++)
                    s[i] -= n[i] * k;
                cout << s[0] << '\n';
            }
            else
                cout << "Hello, siumii" << '\n';
        }
        else
        {
            s[q] += k;
            cout << s[q] << '\n';
        }
    }
}