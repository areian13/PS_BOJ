#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBluray(int limit, int m, vector<int>& lecture)
{
    int cnt = 1;
    int sum = 0;

    int n = lecture.size();
    for (int i = 0; i < n; i++)
    {
        if (sum + lecture[i] <= limit)
            sum += lecture[i];
        else if (sum + lecture[i] > limit)
        {
            cnt++;
            sum = lecture[i];
        }
    }
    return cnt;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> lecture(n);
    for (int i = 0; i < n; i++)
        cin >> lecture[i];

    int start = *max_element(lecture.begin(), lecture.end());
    int end = accumulate(lecture.begin(), lecture.end(), 0);
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = CountBluray(mid, m, lecture);
        if (cnt > m)
            start = mid + 1;
        else if (cnt <= m)
        {
            result = mid;
            end = mid - 1;
        }
    }
    cout << result << '\n';
}