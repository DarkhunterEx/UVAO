#include <bits/stdc++.h>
using namespace std;
bool me(string a,string b){
    if(a[0]=='-' and b[0]=='-'){
        if(a.size()<b.size())
            return false;
        if(a.size()>b.size())
            return true;
        if(a.size()==b.size()){
            for(int i=0;i<a.size();i++){
                int x=a[i]-48;
                int y=b[i]-48;
                if(x<y)
                    return false;
                else if(x>y)
                    return true;
            }
            return true;
        }
    }
    if(a[0]=='-' and b[0]!='-'){
        return true;
    }
    if(a[0]!='-' and b[0]=='-')
        return false;
    if(a.size()<b.size())
        return true;
    if(a.size()>b.size())
        return false;
    if(a.size()==b.size()){
        for(int i=0;i<a.size();i++){
            int x=a[i]-48;
            int y=b[i]-48;
            if(x<y)
                return true;
            else if(x>y)
                return false;
        }
        return false;
    }
}

string m(string a,string b,int neg){
    int len1=a.size();
    int len2=b.size();
    if(len1==0 or len2==0)
    return "0";
    vector<int>r(len1+len2,0);
    int n1=0,n2=0;
    for(int i=len1-1;i>=0;i--){
        int l=0;
        n2=0;
        for(int j=b.size()-1;j>=0;j--){
            int k=(a[i]-48)*(b[j]-48)+r[n1+n2]+l;
            l=k/10;
            r[n1+n2]=k%10;
            n2++;
        }
        if(l>0){
            r[n1+n2]+=l;
        }
		n1++;
    }
    int i=r.size()-1;
    while(i>=0 and r[i]==0){
    	i--;
	}
	if(i==-1)
    return "0";
	string s="";
	if(neg==1)
        s="-";
	while(i>=0){
		s=s+to_string(r[i--]);
	}
	return s;
}

int main() {
    freopen("12.txt","w",stdout);
    string z;
    vector<string>a;
    while(cin>>z){
        if(z=="-999999"){
            string k="-999999999";
            for(int i=0;i<a.size();i++){
                string l="1";
                for(int j=i;j<a.size();j++){
                    int neg=0;
                    string g="";
                    if(l[0]=='-'){
                        neg++;
                        for(int i=1;i<l.size();i++){
                            g=g+l[i];
                        }
                    }
                    else{
                        g=l;
                    }
                    string gg="";
                    if(a[j][0]=='-'){
                        neg++;
                        for(int i=1;i<a[j].size();i++){
                            gg=gg+a[j][i];
                        }
                    }
                    else{
                        gg=a[j];
                    }
                    if(neg%2!=0){
                        l=l+'-';
                    }
                    l=m(g,gg,neg);
                    //cout<<neg<<" "<<l<<endl;
                    if(me(k,l))
                    k=l;
                }
            }
            a.clear();
            cout<<k<<endl;
        }
        else
        a.push_back(z);
    }
}
