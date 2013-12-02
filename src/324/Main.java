/*
 * Sai Cheemalapati
 * UVa 324: Factorial frequencies
 *
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		int digit[][] = new int[10][1000];
		Scanner in = new Scanner(System.in);

		BigInteger f = BigInteger.ONE;
		digit[0][0] = 1;
		for(int i = 1; i <= 366; i++) {
			f = f.multiply(BigInteger.valueOf(i));
			String fs = f.toString();
			for(int j = 0; j < fs.length(); j++)
				digit[fs.charAt(j) - '0'][i]++;
		}
		for(;;) {
			int n = in.nextInt();
			if(n == 0) break;
			System.out.printf("%d! --\n", n);
			System.out.printf("    (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d   (4)  %3d\n", digit[0][n], digit[1][n], digit[2][n], digit[3][n], digit[4][n]);
			System.out.printf("    (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d   (9)  %3d\n", digit[5][n], digit[6][n], digit[7][n], digit[8][n], digit[9][n]);
		}
	}
}
