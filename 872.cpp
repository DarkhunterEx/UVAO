#include <bits/stdc++.h>

using namespace std;
char a[25];
vector<char>b[25];
set<string>res;
void r(bool g[25],string in,int c[25],int k){
    if(in.size()==k){
        res.insert(in);
        return;
    }
    queue<char>q;
    for(int i=0;i<k;i++){
        if(c[i]==0){
            if(g[i]==false)
            q.push(a[i]);
            for(int j=0;j<b[i].size();j++){
                int l;
                for(l=0;l<k and a[l]!=b[i][j];l++){
                }
                if(g[l]==true and g[i]==false){
                    return;
                }
                if(c[l]>0)
                c[l]--;

                if(c[l]==0 and g[l]==false){
                    q.push(b[i][j]);
                }
            }
        }
    }
    while(!q.empty()){
        int i;
        for(i=0;i<k and a[i]!=q.front();i++){
        }
        g[i]=true;
        r(g,in+q.front(),c,k);
        g[i]=false;
        q.pop();
    }
}

int main(){
    string Z;
    getline(cin,Z);
    int z=stoi(Z);
    for(int i=0;i<z;i++){
    if(i>0)
    cout<<endl;
    res.clear();
    int c[25];
    string G;
    getline(cin,G);
    getline(cin,G);
    int k=0;
    for(int j=0;j<25;j++)
    b[j].clear();
    for(int j=0;j<G.size();j++){
        if(G[j]!=' '){
            a[k]=G[j];
            c[k]=0;
            k++;
        }
    }
    string B;
    scanf(" ");
    getline(cin,B);
    int j=0;
    char x,y;
    for(int i=0;i<B.size();i++){
        if(j==0 and i%2==0){
            x=B[i];
            j=1;
        }
        else if(j==1 and i%2==0){
            y=B[i];
            int l;
            for(l=0;l<k and a[l]!=x;l++){
            }
            b[l].push_back(y);
            for(l=0;l<k and a[l]!=y;l++){
            }
            c[l]++;
            j=0;
        }
    }
    bool g[25];
    for(int i=0;i<k;i++){
        g[i]=false;
    }
        r(g,"",c,k);
        set<string>::iterator it;
        for(it=res.begin();it!=res.end();it++){
        cout<<(*it)[0];
        for(int i=1;i<(*it).size();i++){
            cout<<" "<<(*it)[i];
        }
        cout<<endl;
        }
        if(res.size()==0){
            cout<<"NO"<<endl;
        }
    }
}
