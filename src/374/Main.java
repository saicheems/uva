/*
 * Sai Cheemalapati
 * UVA 374: Big mod
 *
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		BigInteger B, P, M;
		Scanner s = new Scanner(System.in);
		while(s.hasNext()) {
			B = s.nextBigInteger();
			P = s.nextBigInteger();
			M = s.nextBigInteger();

			System.out.println(B.modPow(P, M).toString());
		}
	}
}
