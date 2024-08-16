#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<long long, 3> nums;
    for (int i = 0; i < 3; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    long long result = nums[1];
    cout << result << '\n';
}