#include <bits/stdc++.h>

using namespace std;
long long int memo[65][65][65];
long long int r(long long int atual,long long int in,long long int q,long long int z,long long int w){
    if(atual==z and q==w){
       return 1;
    }
    long long int &ans=memo[atual][in][q];
    if(ans!=-1)return ans;
    ans=0;
    if(atual<z){
        if(in==0){
            ans=ans+r(atual+1,0,q+1,z,w);
            ans=ans+r(atual+1,1,q,z,w);
        }
        else{
            ans=ans+r(atual+1,0,q,z,w);
            ans=ans+r(atual+1,1,q,z,w);
        }
    }
    return ans;
}

int main(){
    freopen("12.txt","w",stdout);
    long long int z,w;
    cin>>z>>w;
    while(z>=0 and w>=0){
        memset(memo,-1,sizeof memo);
        cout<<r(0,0,0,z,w)<<endl;
        cin>>z>>w;
    }
}
