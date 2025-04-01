#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int a, vector<int>& p)
{
    if (p[a] == a)
        return a;
    return p[a] = Find(p[a], p);
}

void Union(int a, int b, vector<int>& p)
{
    a = Find(a, p);
    b = Find(b, p);

    p[a] = b;
}

int main()
{
    FastIO;

    int g, p;
    cin >> g >> p;

    vector<int> plane(p + 1);
    for (int i = 1; i <= p; i++)
        cin >> plane[i];

    vector<int> root(g + 1);
    for (int i = 1; i <= g; i++)
        root[i] = i;

    int result = 0;
    for (int i = 1; i <= p; i++)
    {
        int r = Find(plane[i], root);

        if (r == 0)
            break;

        result++;
        Union(r, r - 1, root);
    }
    cout << result << '\n';
}