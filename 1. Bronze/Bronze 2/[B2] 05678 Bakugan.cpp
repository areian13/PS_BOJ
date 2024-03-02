#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> Bakugan(vector<int>& m, vector<int>& l)
{
    int r = m.size();

    int ms = 0;
    int ls = 0;
    bool canGetPoint = true;
    for (int i = 0; i < r; i++)
    {
        ms += m[i];
        ls += l[i];

        if (i < 2 || !canGetPoint)
            continue;

        if (m[i] == m[i - 1] && m[i - 1] == m[i - 2])
        {
            ms += 30;
            canGetPoint = false;
        }
        if (l[i] == l[i - 1] && l[i - 1] == l[i - 2])
        {
            ls += 30;
            canGetPoint = false;
        }
    }

    return { ms,ls };
}

int main()
{
    FastIO;

    while (true)
    {
        int r;
        cin >> r;

        if (r == 0)
            break;

        vector<int> m(r);
        for (int i = 0; i < r; i++)
            cin >> m[i];

        vector<int> l(r);
        for (int i = 0; i < r; i++)
            cin >> l[i];

        array<int, 2> score = Bakugan(m, l);
        char result = (score[0] == score[1] ? 'T' : (score[0] > score[1] ? 'M' : 'L'));
        cout << result << '\n';
    }
}