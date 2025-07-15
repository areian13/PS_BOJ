#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, h;
    cin >> n >> h;

    vector<pair<int, int>> cmds(n);
    for (auto& cmd : cmds)
        cin >> cmd.first >> cmd.second;

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int t;
        cin >> t;


    }

}