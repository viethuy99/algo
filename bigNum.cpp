#include<iostream>
#include<string>
using namespace std;

string cong (string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

string tru (string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}

string nhan (string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}

string Cong(string a,string b){
    if(a[0]=='-'&&b[0]=='-') return "-"+cong(a.substr(1,a.size()-1),b.substr(1,b.size()-1));
    if(a[0]=='-') return tru(b,a.substr(1,a.size()-1));
    if(b[0]=='-') return tru(a,b.substr(1,b.size()-1));
    return cong(a,b);
}

string Tru(string a,string b){
    if(a[0]=='-'&&b[0]=='-') return tru(b,a);
    if(a[0]=='-') return "-"+cong(a.substr(1,a.size()-1),b);
    if(b[0]=='-') return tru(b,a.substr(1,a.size()-1));
    return tru(a,b);
}

string Nhan(string a,string b){
    if(a[0]=='-'&&b[0]=='-') return nhan(a.substr(1,a.size()-1),b.substr(1,b.size()-1));
    if(a[0]=='-') return "-"+nhan(b,a.substr(1,a.size()-1));
    if(b[0]=='-') return "-"+nhan(a,b.substr(1,b.size()-1));
    return nhan(a,b);
}
int main()
{
    //freopen("in.txt","r",stdin);
    string a, b;
    cin>>a>>b;
    cout<<Cong(a,b)<<endl;
    cout<<Tru(a,b)<<endl;
    cout<<Nhan(a,b);
}
