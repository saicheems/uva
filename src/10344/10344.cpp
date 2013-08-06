/*
 * Sai Cheemalapati
 * UVA 10344: 23 out of 5
 *
 */

#include<algorithm>
#include<cstdio>

using namespace std;

int tuple[5];
bool possible;

bool search(int n, long t) {
	if(n == 5)
		if(t == 23) return true;
		else return false;

	return search(n + 1, t + tuple[n]) || \
		search(n + 1, t - tuple[n]) || search(n + 1, t * tuple[n]);
}

int main() {
	for(;;) {
		scanf("%d %d %d %d %d", \
			&tuple[0], &tuple[1], &tuple[2], &tuple[3], &tuple[4]);
		if(tuple[0] == 0 && tuple[1] == 0 && \
			tuple[2] == 0 && tuple[3] == 0 && tuple[4] == 0) break;
		sort(tuple, tuple + 5);
		possible = false;
		do {
			if(search(1, tuple[0])) {
				possible = true;
				break;
			}
		} while(next_permutation(tuple, tuple + 5));
		if(possible) printf("Possible\n");
		else printf("Impossible\n");
	}
}
