#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, QC;
    cin >> n >> QC;

    vector<int> result(n, 0), start(n);
    for (int qc = 1; qc <= QC; qc++)
    {
        int c, h, m;
        string s;
        cin >> c >> s >> h >> m;
        c--;

        int mm = h * 60 + m;
        if (s == "START")
            start[c] = mm;
        else
            result[c] += mm - start[c];
    }

    for (int i = 0; i < n; i++)
        cout << result[i] / 60 << ' ' << result[i] % 60 << '\n';
}