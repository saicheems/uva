/*
 * Sai Cheemalapati
 * UVA 369: Combinatorics
 *
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static BigInteger factorial(BigInteger n) {
		if(n.compareTo(BigInteger.valueOf(1)) <= 0)
			return BigInteger.valueOf(1);
		return n.multiply(factorial(n.subtract(BigInteger.valueOf(1))));
	}

	public static void main(String args[]) {
		BigInteger M, N;
		Scanner s = new Scanner(System.in);
		for(;;) {
			N = s.nextBigInteger();
			M = s.nextBigInteger();
			if(N.equals(BigInteger.valueOf(0))
				&& M.equals(BigInteger.valueOf(0))) break;
			System.out.printf("%s things taken %s at a time is %s exactly.\n",
				N.toString(),
				M.toString(),
				factorial(N).divide(factorial(N.subtract(M))
					.multiply(factorial(M))).toString());
		}
	}
}
