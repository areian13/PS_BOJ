#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long GetTree(int x, vector<int>& trees)
{
    long long result = 0;
    for (int tree : trees)
        result += max(tree - x, 0);
    return result;
}

int CutterHeight(int m, vector<int>& trees)
{
    int start = 0;
    int end = *max_element(trees.begin(), trees.end()) - 1;

    int result = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        long long tree = GetTree(mid, trees);

        if (tree >= m)
        {
            start = mid + 1;
            result = max(result, mid);
        }
        else
            end = mid - 1;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i];

    int result = CutterHeight(m, trees);
    cout << result << '\n';
}