/*
 * Sai Cheemalapati
 * UVA 136: Ugly numbers
 *
 */

#include<cstdio>
#include<queue>

using namespace std;

int main() {
	// makes a min heap
	priority_queue<long long, vector<int>, greater<int> > pq;

	// current ugly #
	long long c = 1;
	int n = 1;

	// push prime factors
	pq.push(2);
	pq.push(3);
	pq.push(5);

	while(n < 1500) {
		// get smallest
		long long nc = pq.top();
		pq.pop();
		// get first # > c if we don't already have it
		while(nc <= c) {
			nc = pq.top();
			pq.pop();
		}

		n++;
		// set c and push all possible combinations
		c = nc;
		pq.push(c * 2);
		pq.push(c * 3);
		pq.push(c * 5);
	}

	printf("The 1500'th ugly number is %lld.\n", c);
}
