#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define MAX_DATA_SIZE 100000

ll S[MAX_DATA_SIZE];
int N;

/*******************************************************/
/* Builds your segment tree given that your leaf nodes */
/* are already populated (S[N] to S[2*N-1]).           */
/*                                                     */
/* N - Actual number of tree nodes.                    */
/*                                                     */
/*******************************************************/
void build_tree() {
   for (int n=N-1; n>0; n--)
      S[n] = S[n<<1] + S[n<<1 | 1];
}

/* Update node p with value v */
void update(int p, ll v) {
   S[p+N] = v; p += N;
   for (int i=p; i>1; i>>=1)
      S[i>>1] = S[i] + S[i^1];
}

/* return sum [L, R) */
ll query(int l, int r) {
   ll response = 0;
   for (l+=N, r+=N; l<r; l>>=1, r>>=1) {
      if (l&1) response += S[l++];
      if (r&1) response += S[--r];
   }
   return response;
}

int main() {
   int T;
   scanf("%d", &T);
   while (T--) {

      // Read in array size
      scanf("%d", &N);

      // build leaf nodes
      memset(S, 0, 2*N);
      for (int n=0; n<N; n++) 
         scanf("%lld", &S[N+n]);

      // build tree
      build_tree();

      // run queries
      for (int L=0; L<N; L++) {
         for (int R=L+1; R<=N; R++) 
            printf("Sum [%d, %d): %lld\n", L, R, query(L,R));
      }
      
   }
   return 0;
}
