#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        char alp;
        cin >> alp;

        if (alp == '#')
            break;

        string s;
        getline(cin.ignore(), s);

        int result = 0;
        for (char c : s)
            result += ((c | 32) == alp);
        cout << alp << ' ' << result << '\n';
    }
}