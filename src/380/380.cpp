/*
 * Sai Cheemalapati
 * UVA 380: Call forwarding
 *
 */

#include<cstdio>
#include<vector>

using namespace std;

int N, source, dtime, dext;
vector<vector<int> > time, duration, target;

int traverse(int n, int o, int t, int e) {
	if(n > 0 && o == e)
		return 9999;
	for(int i = 0; i < target[e].size(); i++)
		if(t >= time[e][i] && t <= time[e][i] + duration[e][i])
			return traverse(n + 1, o, t, target[e][i]);
	return e;
}

int main() {
	printf("CALL FORWARDING OUTPUT\n");
	scanf("%d", &N);
	for(int n = 1; n <= N; n++) {
		target.clear(); time.clear(); duration.clear();
		target.resize(10000); time.resize(10000); duration.resize(10000);
		for(;;) {
			scanf("%d", &source);
			if(source == 0) break;
			int ti, du, ta;
			scanf("%d %d %d", &ti, &du, &ta);
			time[source].push_back(ti);
			duration[source].push_back(du);
			target[source].push_back(ta);
		}
		printf("SYSTEM %d\n", n);
		while(scanf("%d", &dtime) && dtime != 9000 && scanf("%d", &dext)) {
			printf("AT %04d CALL TO %04d RINGS %04d\n", dtime, dext, traverse(0, dext, dtime, dext));
		}
	}
	printf("END OF OUTPUT\n");
}
