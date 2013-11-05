/*
 * Sai Cheemalapati
 * UVa 10106: Product
 *
 */

import java.util.Scanner;
import java.math.BigInteger;

class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			System.out.println(a.multiply(b).toString());
		}
	}
}
