#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CheckMatrix(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    int result = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && matrix[i][j] != 0)
                result = min(result, 1);
            if (i != j && matrix[i][j] <= 0)
                result = min(result, 2);
            if (matrix[i][j] != matrix[j][i])
                result = min(result, 3);
            for (int k = 0; k < n; k++)
            {
                if (matrix[i][j] + matrix[j][k] < matrix[i][k])
                    result = min(result, 4);
            }
        }
    }
    result = (result == 5 ? 0 : result);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int result = CheckMatrix(matrix);
    cout << result << '\n';
}