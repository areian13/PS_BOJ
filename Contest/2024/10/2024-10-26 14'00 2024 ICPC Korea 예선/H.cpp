#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

// a  b  c  d  e  f  g  h  i  j  k  l  m
// 0  1  2  3  4  5  6  7  8  9 10 11 12

bool IsRightSeq(vector<int>& seq, vector<int>& table)
{
    if (table[4] != seq[0] + seq[1] + seq[2] + seq[3])
        return false;
    if (table[5] != seq[4] + seq[5] + seq[6] + seq[7])
        return false;
    if (table[6] != seq[8] + seq[9] + seq[10])
        return false;
    if (table[7] != seq[11] + seq[12])
        return false;
    if (table[0] != seq[0] + seq[4] + seq[8] + seq[11])
        return false;
    if (table[1] != seq[1] + seq[5] + seq[9] + seq[12])
        return false;
    if (table[2] != seq[2] + seq[6] + seq[10])
        return false;
    if (table[3] != seq[3] + seq[7])
        return false;
    return true;
}

int BT(int k, vector<int>& seq, vector<bool>& isUsed, vector<int>& table)
{
    if (k == 1 && (table[4] <= seq[0] || table[0] <= seq[0]))
        return 0;
    if (k == 2 && (table[4] <= seq[0] + seq[1] || table[1] <= seq[1]))
        return 0;
    if (k == 3 && (table[4] <= seq[0] + seq[1] + seq[2] || table[2] <= seq[2]))
        return 0;
    if (k == 4 && (table[4] != seq[0] + seq[1] + seq[2] + seq[3] || table[3] <= seq[3]))
        return 0;
    if (k == 5 && (table[5] <= seq[4] || table[0] <= seq[0] + seq[4]))
        return 0;
    if (k == 6 && (table[5] <= seq[4] + seq[5] || table[1] <= seq[1] + seq[5]))
        return 0;
    if (k == 7 && (table[5] <= seq[4] + seq[5] + seq[6] || table[2] <= seq[2] + seq[6]))
        return 0;
    if (k == 8 && (table[5] != seq[4] + seq[5] + seq[6] + seq[7] || table[3] != seq[3] + seq[7]))
        return 0;
    if (k == 9 && (table[6] <= seq[8] || table[0] <= seq[0] + seq[4] + seq[8]))
        return 0;
    if (k == 10 && (table[6] <= seq[8] + seq[9] || table[1] <= seq[1] + seq[5] + seq[9]))
        return 0;
    if (k == 11 && (table[6] != seq[8] + seq[9] + seq[10] || table[2] != seq[2] + seq[6] + seq[10]))
        return 0;
    if (k == 12 && (table[7] <= seq[11]))
        return 0;
    if (k == 12 && (table[0] != seq[0] + seq[4] + seq[8] + seq[11]))
        return 0;
    if (k == 13)
        return IsRightSeq(seq, table);

    int result = 0;
    for (int i = 0; i < 13; i++)
    {
        if (isUsed[i])
            continue;

        isUsed[i] = true;
        seq[k] = i + 1;
        result += BT(k + 1, seq, isUsed, table);
        isUsed[i] = false;
        seq[k] = 0;
    }
    return result;
}

int main()
{
    FastIO;

    /*vector<int> table(8);
    for (int i = 0; i < 8; i++)
        cin >> table[i];

    vector<int> seq = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
    do
    {
        if (IsRightSeq(seq, table))
        {
            for (int i = 0; i < 13; i++)
                cout << seq[i] << ' ';
            cout << '\n';
        }


    } while (next_permutation(seq.begin(), seq.end()));*/

    vector<int> table(8);
    for (int i = 0; i < 8; i++)
        cin >> table[i];

    vector<int> seq(13, 0);
    vector<bool> isUsed(13, false);
    int result = BT(0, seq, isUsed, table);
    cout << result << '\n';
}