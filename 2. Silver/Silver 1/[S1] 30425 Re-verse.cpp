#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanReverse(int left, int right, vector<vector<char>>& str)
{
    int n = str.size();
    int k = n * 2 - 1;
    for (int i = 0; i < k; i++)
    {
        if (str[left][i] == '.' || str[right][i] == '.')
            continue;

        if (str[left][i] != str[right][i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    string str;
    cin >> n >> str;

    vector<vector<char>> reverse(n, vector<char>(2 * n - 1, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            reverse[i][i + j] = str[j];
    }

    int result = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        if (CanReverse(0, i, reverse))
        {
            result++;
            arr.push_back(i);
        }
    }

    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (!CanReverse(arr[i], arr[j], reverse))
            {
                result--;
                arr.erase(arr.begin() + j);
                j--;
            }
        }
    }
    cout << result << '\n';
}