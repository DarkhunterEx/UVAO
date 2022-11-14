#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","w",stdout);
    //freopen("1.txt","r",stdin);
    int z;
    cin>>z;
    for(int i=0;i<z;i++){
        int w;
        cin>>w;
        vector<string>a;
        for(int j=0;j<w;j++){
            string s;
            cin>>s;
            a.push_back(s);
        }
        sort(a.begin(),a.end());
        bool f=false;
        for(int i=0;i<w-1 and !f;i++){
            int m;
            for(m=0;m<a[i].size() and a[i][m]==a[i+1][m];m++){
            }
            if(m==a[i].size()){
                //cout<<a[i]<<" "<<a[i+1]<<endl;
                f=true;
            }
        }
        if(f){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
