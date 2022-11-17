#include <bits/stdc++.h>

using namespace std;

bool o(pair<int,int>a,pair<int,int>b){
    if(a.first>b.first){
        return !true;
    }
    if(a.first<b.first){
        return !false;
    }
    if(a.second<b.first){
        return !false;
    }
    return !true;
}

int main(){
    freopen("12.txt","w",stdout);
    int zz;
    cin>>zz;
    int ui=zz;
    while(zz){
        if(ui!=zz){
            cout<<endl;
        }
        zz--;
        int w;
        cin>>w;
        int a,b;
        vector<pair<int,int>>c;
        cin>>a>>b;
        while(a!=0 or b!=0){
            c.push_back(make_pair(a,b));
            cin>>a>>b;
        }
        sort(c.begin(),c.end(),o);
        int x=0;
        int s=0;
        vector<pair<int,int>>r;
        while(x<w and s<c.size()){
            pair<int,int>maior=make_pair(-1000000,-1000000);
            while(c[s].first<=x and s<c.size()){
                if(c[s].second>x and c[s].first<=x){
                    if(maior.second<c[s].second){
                        maior=make_pair(c[s].first,c[s].second);
                    }
                }
                s++;
            }
            if(maior.first!=-100){
                r.push_back(maior);
                x=maior.second;
            }
            if(s>0 and c[s].first<=x){
                s--;
            }
            s++;
            //cout<<s<<endl;
        }
        if(x<w){
            cout<<"0"<<endl;
        }
        else{
            cout<<r.size()<<endl;
            for(int i=0;i<r.size();i++){
                cout<<r[i].first<<" "<<r[i].second<<endl;
            }
        }
    }
}
