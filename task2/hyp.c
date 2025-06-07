#define sqr(x) ((long) x * (long) x)

/*@
  @ lemma hyp: \forall int a, b, c;
        a > 0 && b > 0 && c > 0 && sqr(c) == sqr(a) + sqr(b) ==> a < c < a + b;
 */

/*@
  @ requires a > 0 && b > 0;
  @ requires \exists int c; c > 0 && sqr(c) == sqr(a) + sqr(b);
  @ ensures \result > 0 && sqr(\result) == sqr(a) + sqr(b);
 */
int hyp (int a, int b) {
    int c = a + 1;
    /*@
      @ loop invariant a < c < a + b;
      @ loop invariant \forall int p; a < p < c ==> sqr(p) != sqr(a) + sqr(b);
      @ loop variant a + b - c;
     */
    while (sqr(c) - sqr(a) != sqr(b)) {
        c++;
    }
    return c;
}
