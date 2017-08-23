bool RelativelyPrime (int a, int b){
  for ( ; ; ) {
    if (!(a %= b)) return b == 1 ;
    if (!(b %= a)) return a == 1 ;
  }
}