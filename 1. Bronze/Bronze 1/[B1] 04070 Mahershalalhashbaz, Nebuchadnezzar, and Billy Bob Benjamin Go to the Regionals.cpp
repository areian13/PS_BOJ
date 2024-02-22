#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsValidTeam(int start, int k, vector<int>& nameSize)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nameSize[start + i];
    if (nameSize[start] * k < sum - 2 * k || sum + 2 * k < nameSize[start] * k)
        return false;
    return true;
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n, k;
        cin >> n >> k;

        if (n == 0 && k == 0)
            break;

        vector<int> nameSize(n);
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            nameSize[i] = name.size();
        }
        sort(nameSize.begin(), nameSize.end());

        bool result = true;
        for (int i = 0; i < n; i += k)
            result &= IsValidTeam(i, k, nameSize);

        printf("Case %d: %s\n\n", ++tc, (result ? "yes" : "no"));
    }
}