/*
 * Sai Cheemalapati
 * UVA 458: The decoder
 *
 */

#include<cstdio>
#include<iostream>

using namespace std;

string line;

int main() {
	while(getline(cin, line)) {
		for(int i = 0; i < line.length(); i++)
			printf("%c", line[i] - ('1' - '*'));
		printf("\n");
	}
}
