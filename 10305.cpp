#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("12.txt","r",stdin);
    //freopen("1.txt","w",stdout);
    int z,w;
    cin>>z>>w;
    while(z!=0 or w!=0){
        int a[z];
        for(int i=0;i<z;i++){
            a[i]=0;
        }
        vector<int>b[z];
        for(int i=0;i<w;i++){
            int c,d;
            cin>>c>>d;
            c--;
            d--;
            b[c].push_back(d);
            a[d]=a[d]+1;
        }
        queue<int >c;
        for(int i=0;i<z;i++){
            if(a[i]==0){
                c.push(i);
            }
        }
        int k=0;
        while(!c.empty()){
            int z=c.front();
            if(k==1)
                cout<<" "<<z+1;
            else{
                cout<<z+1;
            }
            c.pop();
            k=1;
            for(int i=0;i<b[z].size();i++){
                a[b[z][i]]--;
                if(a[b[z][i]]==0){
                    c.push(b[z][i]);
                }
            }
        }
        cout<<endl;
        cin>>z>>w;
    }
}
