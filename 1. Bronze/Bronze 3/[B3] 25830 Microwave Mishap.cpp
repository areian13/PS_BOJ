#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
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

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)


using namespace std;


int main()
{
	FastIO;

	int m, s;
	scanf("%d:%d", &m, &s);

	int sec = 60 * 60 * m + 60 * s - (60 * m + s);
	printf("%02d:%02d:%02d\n", sec / 60 / 60, sec / 60 % 60, sec % 60);
}
