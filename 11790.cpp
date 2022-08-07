#include <bits/stdc++.h>
using namespace std;
vector<int>B;
vector<int>A;
int memo[200005];
int LIS(int i){
    if(i==0)return 0;
    int &ans=memo[i];
    if(ans!=-1)return ans;
    ans=0;
    for(int j=0;j<i;j++){
        if(A[j]<A[i]){
            ans=max(ans,LIS(j)+B[j]);
        }
    }
    return ans;
}

int main() {
    //freopen("12.txt","w",stdout);
    int z;
    cin>>z;
    int t=1;
    while(t<=z){
        int w;
        cin>>w;
        A.clear();
        B.clear();
        for(int i=0;i<w;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        for(int i=0;i<w;i++){
            int x;
            cin>>x;
            B.push_back(x);
        }
        A.push_back(999999999);
        B.push_back(0);
        memset(memo,-1,sizeof memo);
        int LI=LIS(w);
        A[A.size()-1]=0;
        memset(memo,-1,sizeof memo);
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        A.push_back(999999999);
        B.push_back(0);
        int LD=LIS(w+1);
        cout<<"Case "<<t<<". ";
        if(LI>=LD){
            cout<<"Increasing ("<<LI<<"). Decreasing ("<<LD<<")."<<endl;
        }
        else{
            cout<<"Decreasing ("<<LD<<"). Increasing ("<<LI<<")."<<endl;
        }
        t++;
    }
}
