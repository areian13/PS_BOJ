#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
struct DoublePriorityQueue
{
private:
	priority_queue<T> maxHeap;
	heap<T> minHeap;
	unordered_map<T, int> cnt;

public:
	void push(T data)
	{
		maxHeap.push(data);
		minHeap.push(data);
		cnt[data]++;
	}
	void popMax()
	{
		if (maxHeap.empty())
			return;

		cnt[maxHeap.top()]--;
		maxHeap.pop();
		Clean();
	}
	T topMax()
	{
		if (maxHeap.empty())
			return (T)0;

		return maxHeap.top();
	}
	void popMin()
	{
		if (minHeap.empty())
			return;

		cnt[minHeap.top()]--;
		minHeap.pop();
		Clean();
	}
	T topMin()
	{
		if (minHeap.empty())
			return (T)0;

		return minHeap.top();
	}
	bool empty()
	{
		return minHeap.empty();
	}
	void Clean()
	{
		while (!maxHeap.empty() && cnt[maxHeap.top()] == 0)
			maxHeap.pop();
		while (!minHeap.empty() && cnt[minHeap.top()] == 0)
			minHeap.pop();
	}
};

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		int k;
		Cin k;

		DoublePriorityQueue<int> DPQ;

		For(k)
		{
			char op;
			int value;
			Cin op >> value;
			if (op == 'I')
				DPQ.push(value);
			else
			{
				if(value == 1)
					DPQ.popMax();
				else
					DPQ.popMin();
			}
		}

		if (!DPQ.empty())
			Cout DPQ.topMax() spc DPQ.topMin() Endl;
		else
			Cout "EMPTY" Endl;
	}
}