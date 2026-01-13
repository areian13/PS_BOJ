#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> lights(n);
    for (int i = 0; i < n; i++)
        cin >> lights[i];

    for (int q = 0; q < m; q++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        b--;

        if (a == 1)
            lights[b] = c;
        else
        {
            for (int i = b; i < c; i++)
                lights[i] = (a == 2 ? !lights[i] : (a == 3 ? 0 : 1));
        }
    }

    for (int i = 0; i < n; i++)
        cout << lights[i] << ' ';
    cout << '\n';
}