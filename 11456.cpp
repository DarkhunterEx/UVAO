#include <bits/stdc++.h>

using namespace std;
int memos[2005];
int memo[2005];
vector<int>A;
int z;
int LDS(int i){
    if(i==z)
        return 1;
    int &ans=memos[i];
    if(ans!=-1)
        return ans;
    ans=1;
    for(int j=i+1;j<z;j++){
        if(A[j]>A[i])
            ans=max(ans,LDS(j)+1);
    }
    return ans;
}

int LIS(int i){
    if(i==z)
        return 1;
    int &ans=memo[i];
    if(ans!=-1)
        return ans;
    ans=1;
    for(int j=i+1;j<z;j++){
        if(A[j]<A[i])
            ans=max(ans,LIS(j)+1);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("12.txt","w",stdout);
    int w;
    cin>>w;
    for(int i=0;i<w;i++){
        A.clear();
        cin>>z;
        for(int i=0;i<z;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }
        int w=0;
        memset(memo,-1,sizeof memo);
        memset(memos,-1,sizeof memo);
        for(int i=0;i<z;i++){
            int k=LIS(i);
            k=k+LDS(i);
            w=max(w,k-1);
        }
        cout<<w<<endl;
    }
}
