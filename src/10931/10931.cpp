/*
 * UVa 10931: Parity
 * Sai Cheemalapati
 *
 */

#include <cstdio>
#include <vector>

int main() {
    long long I;
    while (scanf("%lld", &I), I != 0) {
        int P = 0;
        std::vector<char> out;
        for (int i = 0; I != 0; i++) {
            if (I & 1) {
                out.push_back('1');
                P++;
            } else out.push_back('0');
            I = I >> 1;
        }
        printf("The parity of ");
        for (int i = out.size() - 1; i >= 0; i--) printf("%c", out[i]);
        printf(" is %d (mod 2).\n", P);
    }
}
