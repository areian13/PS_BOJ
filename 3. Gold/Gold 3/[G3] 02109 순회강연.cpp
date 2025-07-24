#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];

    vector<vector<int>> schedule(10'001);
    for (int i = 0; i < n; i++)
        schedule[nums[i][1]].push_back(nums[i][0]);

    priority_queue<int> H;
    int result = 0;
    for (int i = 10000; i >= 1; i--)
    {
        for (int d : schedule[i])
            H.push(d);
        if (!H.empty())
        {
            result += H.top();
            H.pop();
        }
    }
    cout << result << '\n';
}