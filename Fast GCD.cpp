ll gcd(ll a, ll b){if( a<0 ) a = -a;if( b<0 ) b = -b;while( b!=0 ){a %= b;if( a==0 ) return b;b %= a;}return a;}
