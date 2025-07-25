#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int n, vector<int>& p)
{
    if (p[n] < 0)
        return n;
    return p[n] = Find(p[n], p);
}

void Union(int a, int b, vector<int>& p)
{
    a = Find(a, p), b = Find(b, p);

    if (a == b)
        return;
    if (p[a] > p[b])
        swap(a, b);
    p[a] += p[b], p[b] = a;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (Find(a, p) == Find(b, p))
        {
            cout << i + 1 << '\n';
            return 0;
        }
        else
            Union(a, b, p);
    }
    cout << 0 << '\n';
}