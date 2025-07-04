#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k, m;
    cin >> k >> m;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
        a[i] = i + 1;

    for (int i = 0; i < m; i++)
    {
        int r;
        cin >> r;

        vector<bool> live(a.size(), true);
        for (int i = r - 1; i < a.size(); i += r)
            live[i] = false;
        
        vector<int> temp;
        for (int i = 0; i < a.size(); i++)
        {
            if (live[i])
                temp.push_back(a[i]);
        }
        a = temp;
    }

    for (auto i : a)
        cout << i << '\n';
}