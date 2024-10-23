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
        int idx;
        string s;
        cin >> idx >> s;
        idx--;

        s.erase(s.begin() + idx);
        cout << s << '\n';
    }
}