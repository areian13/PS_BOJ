#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int cnt = 0;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        for (char c : s)
        {
            c |= 32;
            cnt += (c == 't' ? +1 : (c == 's' ? -1 : 0));
        }
    }

    if (cnt > 0)
        cout << "English" << '\n';
    else
        cout << "French" << '\n';
}