/*
 * Sai Cheemalapati
 * UVa 10220: I love big numbers!
 */

import java.math.BigInteger;
import java.util.Scanner;

class Main {
  public static void main (String args[]) {
    Scanner scanner = new Scanner(System.in);
    int sum[] = new int[1010];

    BigInteger factorial = BigInteger.ONE;
    for (int i = 1; i <= 1000; i++) {
      factorial = factorial.multiply(BigInteger.valueOf(i));
      String value = factorial.toString();
      for (int j = 0; j < value.length(); j++) {
        sum[i] += value.charAt(j) - '0';
      }
    }

    while (scanner.hasNext()) {
      System.out.println(sum[scanner.nextInt()]);
    }
  }
}
