/*
 * Sai Cheemalapati
 * UVa 495: Fibonacci freeze
 *
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main {
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);

		BigInteger fib[] = new BigInteger[5010];
		BigInteger a = fib[0] = BigInteger.valueOf(0);
		BigInteger b = fib[1] = BigInteger.valueOf(1);

		int n = 2;
		while(n <= 5000) {
			fib[n] = a.add(b);
			a = b;
			b = fib[n];

			n++;
		}

		while(scanner.hasNext()) {
			n = scanner.nextInt();
			System.out.printf("The Fibonacci number for %d is %s\n", n, fib[n].toString());
		}
	}
}
