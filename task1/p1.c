#include <limits.h>

/*@
  @ requires INT_MIN <= x1 - x3 <= INT_MAX;
  @ requires INT_MIN <= x1 - x3 + x2 <= INT_MAX;
  @ ensures \result == x1 - x3 + x2;
 */
int comp(int x1, int x2, int x3) {
    int y = x1 - x3;
    return y + x2;
}
