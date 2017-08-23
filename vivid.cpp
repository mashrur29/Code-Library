/************* BigInt multiply *************/

string multiply(string a, int b) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for(int i = 0; i < a.size(); i++) {
        carry += (a[i] - 48) * b;
        a[i] = (carry % 10 + 48);
        carry /= 10;
    }
    while(carry) {
        a += (carry % 10 + 48);
        carry /= 10;
    }
    return a;
}

/**************** Checking RelativelyCoprime *****************/

bool RelativelyPrime (int a, int b){
  for ( ; ; ) {
    if (!(a %= b)) return b == 1 ;
    if (!(b %= a)) return a == 1 ;
  }
}

/*************** Digits of String to number *************/

string a = "25";

int b = atoi(a.c_str());

/************* Determining Set bits ******************/

uint64_t NumberOfSetBits(uint64_t i){
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

/************* Extended GCD *********************/

// if x>y (x+y is minimum)

ll egcd(ll a,ll b,ll &x,ll &y){
 if(a==0){
    x=0;y=1;
    return b;
 }
 ll x1,y1;
 ll d=egcd(b%a,a,x1,y1);
 x=y1-(b/a)*x1;
 y=x1;
 return d;
}

// if x<y (x+y is minimum)

ll egcd(ll a,ll b,ll &x,ll &y){
 if(b==0){
    x=1;y=0;
    return a;
 }
 ll x1,y1;
 ll d=egcd(b,a%b,x1,y1);
 x=y1;
 y=x1-(a/b)*y1;
 return d;
}

/************* Erasing elements from String ************/

char chars[]={'+','-','*','(',')'}; //the array whose elements are to be deleted

for(unsigned int i=0; i<strlen(chars) ;++i) {
          a.erase(remove(a.begin(),a.end(),chars[i]),a.end());  //erasing elements of char[i] from string-a
}

/************* Goldbachs Conjecture ****************/

#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    long long i, lim=sqrt(n);

    if(n%2==0) return false;

    for(i=3; i<=lim; i+=2) {
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    long long n;
    cin>>n;

    if(n%2==0) {
        if(n==2) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    } 
	else if(isPrime(n)) cout<<"1"<<endl;
    else if(n&1) {
        if(isPrime(n-2)) cout<<"2"<<endl;
        else cout<<"3"<<endl;
    }

    return 0;
}

/*********** Longest incresing Zigzag(DP) **********/

ll LIZ(ll n){
  ll i,j,mx=1;

  for(i=0;i<n;i++){
    for(j=0;j<i;j++){
        if(a[i]>a[j]) dp[i][0]=max(dp[i][0],dp[j][1]+1);
    }

    for(j=0;j<i;j++){
        if(a[i]<a[j]) dp[i][1]=max(dp[i][1],dp[j][0]+1);
    }
  }

  return max(mx,max(dp[n-1][0],dp[n-1][1]));
}

/************ Max substring using TRIE ***********/

#include<bits/stdc++.h>
using namespace std;

struct node {
  int cc[27];
  bool endmark;
  node *next[26+1];
  node() {
   memset(cc, 0, sizeof(cc));
   endmark = false;
   for(int i = 0; i<26; i++) next[i] = NULL;
  }
};

struct TRIE {
  node *root;
  bool pre;

  TRIE() {
   root = new node();
   pre = false;
  }

  void insert(string str) {
   node *curr = root;
   int cnt = 0;

   int len = str.size();
   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) {
            curr->next[id] = new node();
    }
    else cnt++;

    curr->cc[id]++;
    if(curr->endmark) pre = true;
    curr = curr->next[id];
   }

   if(cnt==len) pre = true;
   curr->endmark = true;
  }

  bool search(string str) {
   node *curr = root;
   int len = str.size();

   for(int i=0; i<len; i++) {
    int id = str[i] - 'a';
    if(curr->next[id]==NULL) return false;
    curr = curr->next[id];
   }


   return curr->endmark;
  }

  int prefix_occurance(string s) {

   int res = INT_MAX;
   node *curr = root;

   for(int i=0; i<s.size(); i++) {
    int id = s[i] - 'a';
    if(curr==NULL) {
        res = 0;
        break;
    }

    res = min(res, curr->cc[id]);
    curr = curr->next[id];
   }

   return res;

  }

  void del(node *curr) {
   for(int i=0; i<26; i++) {
    if(curr->next[i]) del(curr->next[i]);
   }
   delete(curr);
  }

  int max_substring(node *curr) {

    int res = 1;

     for(int i=0; i<26; i++) {
        if(curr->next[i]!=NULL) {
         if(curr->cc[i]>1) return max(res, 1+max_substring(curr->next[i]));
         else return max(res, max_substring(curr->next[i]));
        }
     }
  }

  bool prefix() {
   return pre;
  }

};

int main() {
  TRIE a;
  a.insert("oggy");
  a.insert("ggy");
  a.insert("gy");
  a.insert("y");

  a.insert("pgfq");
  a.insert("gfq");
  a.insert("fq");
  a.insert("q");
 cout<<a.max_substring(a.root)<<endl;
}

/************ Finding Nth Palindrome *************/

#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b) {
    long long s=1;
    while(b) {
        if(b&1) s*=a;
        b/=2;
        if(b) a*=a;
    }
    return s;
}

int main() {
    long long n,s,i,count=1,r=9,res,p;
    cin>>n;
    p=n-1;
    for(s=1;; s+=2) {

        if(count>=n) break;

        count+=(r+r);
        if(p-2*r>0) p-=2*r;
        r*=10;
        if(count>=n) break;
    }

    long long t=s/2;
    if(s%2!=0) t++;

    res=(p-1)+power(10,t-1);

    cout<<res;

    if(s%2!=0) res/=10;
    while(res) {
        cout<<res%10;
        res/=10;
    }

    cout<<endl;
    return 0;
}

/*************** Segmented Sieve ****************/

#include<bits/stdc++.h>
using namespace std;

const int maxi = 2000001;
bool is[maxi];
vector<long long> p;

void sieve() {
    memset(is, 0, sizeof(is));
    int lim, n = maxi-1;
    lim = sqrt(n);
    is[1] = true;
    for(int i=3; i<=lim; i+=2) {
        if(!is[i]) {
            for(int j = i*i; j<=n; j+=2*i) is[j] = 1;
        }
    }

    p.push_back(2);
    for(int i=3; i<=n; i+=2) {
        if(!is[i]) p.push_back(i);
    }
}

int segmented_sieve(int L, int R) {
    int range = R - L, cnt = 0;
    vector<long long> prime_in_range;

    bool ok[maxi-1];
    memset(ok, 0, sizeof(ok));

    for(int i=0; i<p.size(); i++) {
        long long prime = p[i];
        long long inc = prime + prime;

        long long start = max(((L + prime - 1)/prime)*prime, prime*prime);
        if((start&1)==0) {
            start += prime;
        }

        start -= L;
        for(long long j=start; j<=range; j+=inc) ok[j] = 1;
    }

    if(L<=2 && R>=2) prime_in_range.push_back(2);
    for(long long k = (L & 1) ? 0 : 1; k<=range; k+=2) {
        if(!ok[k]) prime_in_range.push_back(L + k);
    }

    return prime_in_range.size();
}

int main() {
    sieve();
    int l, r;

    while(scanf("%d %d", &l, &r)==2) {
        if(l==1) l++;
        cout<<segmented_sieve(l, r)<<endl;
    }

    return 0;
}

/************** Splitting a String ************/

#include<bits/stdc++.h>
using namespace std;

int main() {
    std::string original;
    cin>>original;
    std::size_t index = (original.size()/2)+1;
    std::string::iterator it = original.begin();

    std::string part1(it, it + index);
    std::string part2(it + index, original.end());
    cout<<part1;
    cout<<part1<<endl;
    return 0;
}

/************** String Tokenizer *************/

#include <iostream>
#include <sstream>

int main() {

    std::string input = "abc,def,ghi";
    std::istringstream ss(input);
    std::string token;

    while(std::getline(ss, token, ',')) {
        std::cout << token << '\n';
    }

}

/********** String to Int ************/

std::string myString = "45";
int value = atoi(myString.c_str());

/********* Using next permutation ***********/

// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}

/************* substring **********/

string new = old.substr(start_index,how many character from start) // both are integer


