#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> line(n);
    line[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        int d;
        cin >> d;

        line[d + 1] = i;
    }

    for (int i = 0; i < n; i++)
        cout << line[i] << ' ';
    cout << '\n';
}