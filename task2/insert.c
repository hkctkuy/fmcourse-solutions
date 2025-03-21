/*@
  @ requires n >= 0 && 0 <= i <= n;
  @ requires \valid(a + (i .. n));
  @ assigns a[i .. n];
  @ ensures a[i] == m;
  @ ensures \forall int j; i < j <= n ==> a[j] == \old(a[j - 1]);
 */
void insert(int *a, int n, int i, int m) {
    /*@
      @ loop invariant i <= j <= n;
      @ loop invariant \forall int k; j < k <= n ==> a[k] == \at(a[k - 1], Pre);
      @ loop invariant \forall int k; i <= k <= j ==> a[k] == \at(a[k], Pre);
      @ loop variant j;
     */
    for (int j = n; j > i; j--) {
        a[j] = a[j - 1];
    }
    a[i] = m;
}
