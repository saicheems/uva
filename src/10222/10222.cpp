/*
 * Sai Cheemalapati
 * UVa 10222: Decode the mad man
 *
 */

#include<cstdio>
#include<cstring>

char input[5000];

int main() {
	gets(input);
	int length = strlen(input);

	char letters[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-=[]\\;',./";
	char mapping[] = "  czaqsdfyghjbvui w etx  r  czaqsdfyghjbvui w etx  r   `1234567890op[klnm,";

	int mlength = strlen(letters);

	for(int i = 0; i < length; i++) {
		for(int j = 0; j < mlength; j++) {
			if(letters[j] == input[i]) {
				printf("%c", mapping[j]);
				break;
			}
		}
	} printf("\n");
}
