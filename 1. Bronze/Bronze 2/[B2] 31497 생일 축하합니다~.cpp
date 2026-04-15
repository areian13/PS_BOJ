#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "? " << s[i] << endl;

            bool flag;
            cin >> flag;

            if (flag)
            {
                cout << "! " << s[i] << endl;
                return 0;
            }
        }
    }
}