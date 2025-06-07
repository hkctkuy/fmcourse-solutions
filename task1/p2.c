#include <limits.h>

#define OFsub(x, y) (y < 0 && x > INT_MAX + y || y > 0 && x < INT_MIN + y)
#define OFadd(x, y) (y < 0 && x < INT_MIN - y || y > 0 && x > INT_MAX - y)
#define NOFsub(x, y) (!OFsub(x, y))
#define NOFadd(x, y) (!OFadd(x, y))

/*@
  @ requires INT_MIN <= x1 - x3 + x2 <= INT_MAX;
  @ ensures \result == x1 - x3 + x2;
 */
int comp(int x1, int x2, int x3) {
    int y;
    if (NOFsub(x1, x3)) {
        y = x1 - x3;
        return y + x2;
    }
    if (NOFadd(x1, x2)) {
        y = x1 + x2;
        return y - x3;
    }
    y = x2 - x3;
    return y + x1;
}
