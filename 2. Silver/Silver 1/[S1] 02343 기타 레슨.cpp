#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBluray(int limit, vector<int>& lectures)
{
    int cnt = 1;
    int sum = 0;

    for (int lecture : lectures)
    {
        if (sum + lecture <= limit)
            sum += lecture;
        else if (sum + lecture > limit)
        {
            cnt++;
            sum = lecture;
        }
    }
    return cnt;
}

int MinBluraySize(int m, vector<int>& lectures)
{
    int start = *max_element(lectures.begin(), lectures.end());
    int end = accumulate(lectures.begin(), lectures.end(), 0);
    int result = lectures.size();
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = CountBluray(mid, lectures);
        if (cnt > m)
            start = mid + 1;
        else if (cnt <= m)
        {
            result = mid;
            end = mid - 1;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> lectures(n);
    for (int i = 0; i < n; i++)
        cin >> lectures[i];

    int result = MinBluraySize(m, lectures);
    cout << result << '\n';
}