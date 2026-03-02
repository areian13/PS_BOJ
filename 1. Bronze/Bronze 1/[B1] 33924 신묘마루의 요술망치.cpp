#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int r, c, k;
    string s;
    cin >> r >> c >> k >> s;
    r--, c--;

    vector<vector<bool>> mat(4, vector<bool>(2, false));
    mat[r][c] = true;

    for (char t : s)
    {
        if (t == 'A')
        {
            swap(mat[0], mat[2]);
            swap(mat[1], mat[3]);
        }
        else if (t == 'B')
        {
            for (int i = 0; i < 2; i++)
            {
                swap(mat[i * 2][0], mat[i * 2 + 1][1]);
                swap(mat[i * 2 + 1][0], mat[i * 2][1]);
            }
        }
        else if (t == 'C')
        {
            for (int i = 0; i < 2; i++)
            {
                swap(mat[i][0], mat[3 - i][1]);
                swap(mat[i][1], mat[3 - i][0]);
            }
        }
        else if (t == 'D')
        {
            int mat00 = mat[0][0];
            mat[0][0] = mat[1][0];
            mat[1][0] = mat[2][0];
            mat[2][0] = mat[3][0];
            mat[3][0] = mat[3][1];
            mat[3][1] = mat[2][1];
            mat[2][1] = mat[1][1];
            mat[1][1] = mat[0][1];
            mat[0][1] = mat00;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (mat[i][j])
                cout << i + 1 << ' ' << j + 1 << '\n';
        }
    }
}