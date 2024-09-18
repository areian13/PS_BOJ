#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(int num, vector<int>& cd)
{
    int start = 0;
    int end = cd.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (cd[mid] < num)
            start = mid + 1;
        else if (cd[mid] > num)
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<int> cds(n);
        for (int i = 0; i < n; i++)
            cin >> cds[i];

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            int cd;
            cin >> cd;

            result += IsIn(cd, cds);
        }
        cout << result << '\n';
    }
}