/*
 * Sai Cheemalapati
 * UVA 10055: Hashmat the brave warrior
 *
 */

#include<cstdio>

using namespace std;

long long a, b;

int main() {
	while(scanf("%lld %lld", &a, &b) == 2)
		printf("%lld\n", b > a? b - a : a - b);
}
