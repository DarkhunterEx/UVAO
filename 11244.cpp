#include <bits/stdc++.h>

using namespace std;
char a[103][103];
bool b[103][103];
int z,w;
int ff(int i,int j,int q){
	if(i+1<z and b[i+1][j]!=true and a[i+1][j]=='*'){
		b[i+1][j]=true;
		a[i+1][j]='.';
		ff(i+1,j,q+1);q++;
	}
	if(j+1<w and b[i][j+1]!=true and a[i][j+1]=='*'){
		b[i][j+1]=true;
		a[i][j+1]='.';
		ff(i,j+1,q+1);q++;
	}
	if(i-1>=0 and b[i-1][j]!=true and a[i-1][j]=='*'){
        a[i-1][j]='.';
		b[i-1][j]=true;
		ff(i-1,j,q+1);q++;
	}
	if(j-1>=0 and b[i][j-1]!=true and a[i][j-1]=='*'){
	    a[i][j-1]='.';
		b[i][j-1]=true;
		ff(i,j-1,q+1);q++;
    }
    if(i+1<z and j+1<w and b[i+1][j+1]!=true and a[i+1][j+1]=='*'){
		b[i+1][j+1]=true;
		a[i+1][j+1]='.';
		ff(i+1,j+1,q+1);q++;
	}
	if(j-1>=0 and i-1>=0 and b[i-1][j-1]!=true and a[i-1][j-1]=='*'){
		b[i-1][j-1]=true;
		a[i-1][j-1]='.';
		ff(i-1,j-1,q+1);
		q++;
	}
	if(i+1<z and j-1>=0 and b[i+1][j-1]!=true and a[i+1][j-1]=='*'){
        a[i+1][j-1]='.';
		b[i+1][j-1]=true;
		ff(i+1,j-1,q+1);
		q++;
	}
	if(i-1>=0 and j+1<w and b[i-1][j+1]!=true and a[i-1][j+1]=='*'){
	    a[i-1][j+1]='.';
		b[i-1][j+1]=true;
		ff(i-1,j+1,q+1);
		q++;
    }
    return q;
}
int main(){
    //freopen("12.txt","w",stdout);
    cin>>z>>w;
    while(z!=0 and w!=0){
        for(int i=0;i<103;i++){
            for(int j=0;j<103;j++){
                a[i][j]='.';
                b[i][j]=false;
            }
        }
        for(int i=0;i<z;i++){
            for(int j=0;j<w;j++){
                cin>>a[i][j];
            }
        }
        int k=0;
        for(int i=0;i<z;i++){
            for(int j=0;j<w;j++){
                if(a[i][j]=='*'){
                    a[i][j]='.';
                    b[i][j]=true;
                    if(ff(i,j,1)==1){
                        k++;
                    }
                }
            }
        }
        cout<<k<<endl;
        cin>>z>>w;
    }
}
