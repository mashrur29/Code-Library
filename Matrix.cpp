#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD=1000000007;

struct matrix{
   ll mat[50][50];
   ll dim;

   matrix(){};
   matrix(ll d){
      dim=d;
      for(ll i=0; i<dim; i++)
            for(ll j=0; j<dim; j++) mat[i][j]=0;
   }

   matrix operator *(const matrix &mul){
        matrix ret = matrix(dim);
        for(ll i=0; i<dim; i++){
            for(ll j=0; j<dim; j++){
                for(ll k=0; k<dim; k++){
                    ret.mat[i][j] += (mat[i][k])*(mul.mat[k][j]);
                    ret.mat[i][j] %= MOD;
                }
            }
        }

        return ret;
   }

   matrix operator ^(ll p){
       matrix ret = matrix(dim);
       matrix m = *this;
       for(ll i=0; i<dim; i++) ret.mat[i][i] = 1;

       while(p){
        if(p&1) ret = ret * m;
        m = m * m;
        p >>= 1;
       }

     return ret;
   }

};

int main(){
   ll n;
   cin>>n;
   matrix m = matrix(3);
   m.mat[0][0]=1;
   m.mat[0][1]=4;
   m.mat[0][2]=7;
   m.mat[1][0]=2;
   m.mat[1][1]=5;
   m.mat[1][2]=8;
   m.mat[2][0]=3;
   m.mat[2][1]=6;
   m.mat[2][2]=9;

   m=m*m;

   for(int i=0; i<3; i++){
    for(int j=0; j<3; j++) cout<<m.mat[i][j]<<" ";
    cout<<endl;
   }
}

