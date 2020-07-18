#ifndef __cplusplus

#include <stdbool.h>
#else
extern "C" {
#endif
	void pourLiquid(int index);
	int getReading();
	void answer(int order[]);

	void experiment(int N);
#ifdef __cplusplus
}
#endif

#include <vector>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)

vector<int> sort(vector<int> ns) {
	if (ns.size() <= 1) {
		return ns;
	}
	int mid = ns.size() / 2;
	vector<int> as, bs;
	int i = 0;
	for (; i < mid; i++) {
		as.push_back(ns[i]);
	}
	for (; i < ns.size(); i++) {
		bs.push_back(ns[i]);
	}
	as = sort(as);
	bs = sort(bs);
	int ai = 0;
	int bi = 0;
	vector<int> re;
	while (ai + bi <= as.size() + bs.size() - 3) {
		if (ai == as.size() - 1) {
			re.push_back(bs[bi]);
			bi++;
		} else if (bi == bs.size() - 1) {
			re.push_back(as[ai]);
			ai++;
		} else if (comp(as[ai], bs[bi])) {
			re.push_back(as[ai]);
			ai++;
		} else {
			re.push_back(bs[bi]);
			bi++;
		}
	}
	if (ai == as.size() - 1) {
		re.push_back(bs[bi]);
	} else {
		re.push_back(as[ai]);
	}
	return re;
}
bool comp(int a, int b) {
	pourLiquid(a);
	pourLiquid(b);
	int c = getReading();
	return (c == 0);
}
void experiment(int N) {
	vector<int> ans(N);
	forn(i, N) {
		ans[i] = i + 1;
	}
	ans = sort(ans);
	int ans2[N];
	forn(i, N) {
		ans2[i] = ans[i];
	}
	
}
