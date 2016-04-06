#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maX 1000
using namespace std ;
int main () {
 int t,n,f,b ;
 int i,j ;
 int a[maX+1] ;
 short int flag ;
 scanf ("%d",&t) ;
 while ( t-- ) {
  scanf ( "%d%d%d",&n,&f,&b ) ;
  for ( i = 0 ; i < n ; ++i ) {
  // scanf ( "%d%d",&a[i],&flag ) ;
   cin >> a[i] >> flag ;
   if ( flag == 1 ) a[i] = 2*f-a[i] ;
  }
  sort ( a,a+n ) ;
  int times = b/n ;
  int last = b%n ;
  if ( last != 0 ) {
   --last ;
   ++times ;
  }
  else last = n-1 ;
  printf("%d\n" , a[last]+(2*times-1)*f ) ;
 }
  return 0 ;
}                                 