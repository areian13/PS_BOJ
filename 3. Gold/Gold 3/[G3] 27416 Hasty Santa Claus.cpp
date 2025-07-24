#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Calendar
{
    int idx;

    int start;
    int end;

    int visitDate;
};
struct Visit
{
    int cnt;
    int k;
};

bool SortDate(Calendar& a, Calendar& b)
{
    if (a.end != b.end)
        return a.end < b.end;
    return a.start < b.start;
}
bool SortIndex(Calendar& a, Calendar& b)
{
    return a.idx < b.idx;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<Calendar> calendar(n);
    array<Visit, 32> canVisit;
    canVisit.fill({ 0,k });
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        calendar[i] = { i,a,b };
        for (int j = a; j <= b; j++)
            canVisit[j].cnt++;
    }
    sort(calendar.begin(), calendar.end(), SortDate);

    for (int i = 0; i < n; i++)
    {
        int visitDate = calendar[i].start;
        while (canVisit[visitDate].cnt == 0 || canVisit[visitDate].k == 0)
            visitDate++;

        calendar[i].visitDate = visitDate;
        canVisit[visitDate].cnt--;
        canVisit[visitDate].k--;
    }
    sort(calendar.begin(), calendar.end(), SortIndex);
    for (int i = 0; i < n; i++)
        cout << calendar[i].visitDate << '\n';
}
