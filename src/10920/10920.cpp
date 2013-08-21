/*
 * Sai Cheemalapati
 * UVA 10920: Spiral tap
 *
 */

#include<cmath>
#include<cstdio>

using namespace std;

long long SZ, P;

int main() {
	for(;;) {
		scanf("%lld %lld", &SZ, &P);
		if(SZ == 0 && P == 0) break;
		
		// get next highest anchor
		long long root = sqrt(P);
		if(root * root == P && root % 2 == 1) {
		} else if(root % 2 == 1) root += 2;
		else root++;

		long long i = root / 2, j = root / 2;
		if(root * root != 1) {	
			long group = (root * root - P) / (root - 1);
			switch(group) {
				case 0:
					i -= root * root - P;
					break;
				case 1:
					i -= root - 1;
					j -= (root * root - P - (root - 1));
					break;
				case 2:
					i -= (root - 1) - (root * root - P - (root - 1) * 2);
					j -= root - 1;
					break;
				case 3:
					j -= (root - 1) - (root * root - P - (root - 1) * 3);
					break;
			}
		}
		printf("Line = %lld, column = %lld.\n", i + SZ / 2 + 1, j + SZ / 2 + 1);
	}
}
