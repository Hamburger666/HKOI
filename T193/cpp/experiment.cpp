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

#define forn(i, n) for (long long i = 0; i < n; i++)
typedef long long ll;
// TODO: global variables can be declared here

void experiment(int N) {
	int ans[N];
	forn(i, N) {
		ans[i] = i + 1;
	}
	answer(ans);
}

int main() {
	
}