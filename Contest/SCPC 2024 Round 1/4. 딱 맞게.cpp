#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BS(int n, vector<int>& a)
{
    int start = 0;
    int end = a.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] < n)
            start = mid + 1;
        else if (n < a[mid])
            end = mid - 1;
        else
            return a[mid];
    }

    if (end < 0)
        return a[0];
    if (start >= a.size())
        return a[a.size() - 1];
    return abs(a[start] - n) < abs(a[end] - n) ? a[start] : a[end];
}

//int MaxF(int l, vector<int>& a, vector<int>& b)
//{
//    int n = a.size();
//    sort(a.begin(), a.end());
//    sort(b.begin(), b.end());
//
//    int result = -1;
//    for (int i = 0; i < n; i++)
//    {
//        for (int d : { +1,-1 })
//        {
//            int p = abs(b[i] + l * d);
//            int k = BS(p, a);
//
//            int g = abs(k - b[i]);
//            if (g <= l)
//                result = max(result, g);
//        }
//    }
//    return result;
//}

int MaxF(int l, vector<int>& a, vector<int>& b)
{
    int n = a.size();
    sort(a.begin(), a.end());
    
    int result = -1;
    do
    {
        int f = 0;
        for (int i = 0; i < n; i++)
            f = max(f, abs(a[i] - b[i]));

        if(f <= l)
            result = max(result, f);
    } while (next_permutation(a.begin(), a.end()));
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, l;
        cin >> n >> l;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int result = MaxF(l, a, b);
        cout << "Case #" << t << endl;
        cout << result << endl;
    }
}