/*
 * Sai Cheemalapati
 * UVA 11947: Cancer or Scorpio
 *
 */

import java.util.Calendar;
import java.util.Scanner;

class Main {

	Calendar aquarius = Calendar.getInstance();
	Calendar pisces = Calendar.getInstance();
	Calendar aries = Calendar.getInstance();
	Calendar taurus = Calendar.getInstance();
	Calendar gemini = Calendar.getInstance();
	Calendar cancer = Calendar.getInstance();
	Calendar leo = Calendar.getInstance();
	Calendar virgo = Calendar.getInstance();
	Calendar libra = Calendar.getInstance();
	Calendar scorpio = Calendar.getInstance();
	Calendar sagittarius = Calendar.getInstance();
	Calendar capricorn = Calendar.getInstance();

	Scanner scanner = new Scanner(System.in);

	void run() {
		int N = scanner.nextInt();
		for(int i = 1; i <= N; i++) {
			String date = scanner.next();
			int m = Integer.parseInt(date.substring(0, 2));
			int d = Integer.parseInt(date.substring(2, 4));
			int y = Integer.parseInt(date.substring(4, 8));

			Calendar test = Calendar.getInstance();
			test.set(y, m - 1, d);
			test.add(Calendar.WEEK_OF_YEAR, 40);

			y = test.get(Calendar.YEAR);
			aquarius.set(y, 0, 21);
			pisces.set(y, 1, 20);
			aries.set(y, 2, 21);
			taurus.set(y, 3, 21);
			gemini.set(y, 4, 22);
			cancer.set(y, 5, 22);
			leo.set(y, 6, 23);
			virgo.set(y, 7, 22);
			libra.set(y, 8, 24);
			scorpio.set(y, 9, 24);
			sagittarius.set(y, 10, 23);
			capricorn.set(y, 11, 23);

			System.out.printf("%d %02d/%02d/%04d ", i,
					test.get(Calendar.MONTH) + 1,
					test.get(Calendar.DAY_OF_MONTH),
					y);

			if(test.compareTo(aquarius) >= 0 && test.before(pisces)) {
				System.out.println("aquarius");
			} else if(test.compareTo(pisces) >= 0 && test.before(aries)) {
				System.out.println("pisces");
			} else if(test.compareTo(aries) >= 0 && test.before(taurus)) {
				System.out.println("aries");
			} else if(test.compareTo(taurus) >= 0 && test.before(gemini)) {
				System.out.println("taurus");
			} else if(test.compareTo(gemini) >= 0 && test.before(cancer)) {
				System.out.println("gemini");
			} else if(test.compareTo(cancer) >= 0 && test.before(leo)) {
				System.out.println("cancer");
			} else if(test.compareTo(leo) >= 0 && test.before(virgo)) {
				System.out.println("leo");
			} else if(test.compareTo(virgo) >= 0 && test.before(libra)) {
				System.out.println("virgo");
			} else if(test.compareTo(libra) >= 0 && test.before(scorpio)) {
				System.out.println("libra");
			} else if(test.compareTo(scorpio) >= 0 && test.before(sagittarius)) {
				System.out.println("scorpio");
			} else if(test.compareTo(sagittarius) >= 0 && test.before(capricorn)) {
				System.out.println("sagittarius");
			} else if(test.compareTo(capricorn) >= 0 || test.before(aquarius)) {
				System.out.println("capricorn");
			}
		}
	}

	public static void main(String args[]) {
		new Main().run();
	}
}
