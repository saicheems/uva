/*
 * UVa 477: Points in figures: rectangles and circles
 * Sai Cheemalapati
 *
 */

#include <cmath>
#include <cstdio>

struct shape {
    char type;
    float ulx, uly, lrx, lry;
    float x, y, r;
};

shape shapes[10];

int main() {
    char type;
    int n = 0;
    while (scanf("%c", &type), type != '*') {
        shapes[n].type = type;
        if (type == 'r')
            scanf("%f %f %f %f\n",
                &(shapes[n].ulx), &(shapes[n].uly),
                &(shapes[n].lrx), &(shapes[n].lry));
        else
            scanf("%f %f %f\n",
                &(shapes[n].x), &(shapes[n].y), &(shapes[n].r));
        n++;
    }

    float x, y;
    int p = 0, m;
    for (;;) {
        scanf("%f %f", &x, &y);
        if (fabs(x - 9999.9) < 1e-3 && fabs(y - 9999.9) < 1e-3) break;

        p++;
        m = 0;
        for (int i = 0; i < n; i++) {
            if (shapes[i].type == 'r') {
                if (x >= shapes[i].ulx && x <= shapes[i].lrx &&
                        y <= shapes[i].uly && y >= shapes[i].lry) {
                    printf("Point %d is contained in figure %d\n", p, i + 1);
                    m++;
                }
            } else {
                if (sqrt((x - shapes[i].x) * (x - shapes[i].x) +
                        (y - shapes[i].y) * (y - shapes[i].y)) <= shapes[i].r) {
                    printf("Point %d is contained in figure %d\n", p, i + 1);
                    m++;
                }
            }
        }
        if (m == 0)
            printf("Point %d is not contained in any figure\n", p);
    }
}
