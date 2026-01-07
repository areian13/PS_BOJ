#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Japan(int d, int k, int r, int l)
{
    if (d >= 3) return false;
    if (l < 50) return false;

    int t = d == 2 ? 90 : 100;
    if (k * 3 < t && r * 3 < t)
        return true;
    return k <= 21 || r <= 21;
}

int main()
{
    FastIO;

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int d, k, r, l;
        cin >> d >> k >> r >> l;

        bool result = Japan(d, k, r, l);
        cout << (result ? "YES" : "NO") << '\n';
    }
}