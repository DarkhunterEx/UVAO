#include<bits/stdc++.h>
using namespace std;
map<string,int>a;
map<int,string>aa;
vector<int>b[106];
int t[106];
vector<string>o;
void ts(int n){
    priority_queue<int,vector<int>,greater<int>>c;
    for(int i=0;i<n;i++){
        if(t[i]==0){
            c.push(i);
        }
    }
    while(!c.empty()){
        int z=c.top();
        map<int,string>::iterator it;
        it=aa.find(z);
        o.push_back(it->second);
        c.pop();
        for(int i=0;i<b[z].size();i++){
            t[b[z][i]]--;
            if(t[b[z][i]]==0){
                c.push(b[z][i]);
            }
        }
    }
}

int main(){
    freopen("12.txt","w",stdout);
    int z;
    int v=0;
    while(cin>>z){
        v++;
        a.clear();
        aa.clear();
        for(int i=0;i<z;i++){
            string A;
            cin>>A;
            a.insert(make_pair(A,i));
            aa.insert(make_pair(i,A));
        }
        int w;
        cin>>w;

        o.clear();
        for(int i=0;i<106;i++){
            b[i].clear();
            t[i]=0;
        }
        for(int i=0;i<w;i++){
            map<string,int>::iterator it;
            map<string,int>::iterator it1;
            string A,B;
            cin>>A>>B;
            it=a.find(A);
            it1=a.find(B);
            b[it->second].push_back(it1->second);
            t[it1->second]++;
        }
        ts(z);
        cout<<"Case #"<<v<<": Dilbert should drink beverages in this order:";
        for(int i=0;i<o.size();i++){
            cout<<" "<<o[i];
        }
        cout<<'.'<<endl;
        cout<<endl;
    }
}
