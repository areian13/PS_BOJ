#include <iostream>
#include <vector>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int w, p;
    cin >> w >> p;

    vector<int> l(p + 2);
    l[0] = 0, l[p + 1] = w;
    for (int i = 1; i < p + 1; i++)
        cin >> l[i];
    p += 2;

    set<int> s;
    for (int i = 0; i < p - 1; i++)
    {
        for (int j = i + 1; j < p; j++)
            s.insert(l[j] - l[i]);
    }

    for (auto& i : s)
        cout << i << ' ';
}