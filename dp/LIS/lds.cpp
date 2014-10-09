#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int lds( int* a, int N ) {
   int *best, i, j, max = INT_MIN;
   best = (int*) malloc ( sizeof( int ) * N );
 
   for ( i = 0; i < N; i++ ) 
      best[i] = 1;
 
   for ( i = 1; i < N; i++ )
   {
      for ( j = 0; j < i; j++ )
      {
         if ( a[i] < a[j] && best[i] < best[j] + 1 )
         {
           best[i] = best[j] + 1;
           if(max < best[i])
             max = best[i];
         }         
      }
   }
 
   free( best );
   return max;
}
int main(){
  //int b[] = { 389, 207, 155, 300, 299, 170, 158, 65 };
  int b[] = { 23, 34, 21 };
  printf("%d\n", lds( b, 3 ) );
  return 0;
}
