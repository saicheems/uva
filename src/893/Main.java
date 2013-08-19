/*
 * Sai Cheemalapati
 * UVA 893: Y3K problem
 *
 */

import java.util.Calendar;
import java.util.Scanner;

class Main {
	int f, d, m, y;
	Scanner scanner = new Scanner(System.in);
	Calendar calendar = Calendar.getInstance();

	void run() {
		for(;;) {
			f = scanner.nextInt();
			d = scanner.nextInt();
			m = scanner.nextInt();
			y = scanner.nextInt();
			if(f == 0 && d == 0 & m == 0 & y == 0) break;

			m--;
			calendar.set(y, m, d);
			calendar.add(Calendar.DAY_OF_YEAR, f);

			System.out.printf("%d %d %d\n",
				calendar.get(Calendar.DAY_OF_MONTH),
				calendar.get(Calendar.MONTH) + 1,
				calendar.get(Calendar.YEAR));
		}
	}

	public static void main(String args[]) {
		new Main().run();
	}
}
