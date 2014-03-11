/*
 * UVa 11185: Ternary
 * Sai Cheemalapati
 *
 */

import java.util.Scanner;

 class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

	while (true) {
	    long n = scanner.nextLong();
	    if (n < 0) break;
	    System.out.println(Long.toString(n, 3));
	}
    }
 }
