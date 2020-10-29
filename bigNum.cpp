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

#include<bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;


const int BASE = 10000;
typedef vector <int> BigInt;
BigInt Init(string s) {
    BigInt a; if (s.size() == 0) { a.push_back(0); return a; }
    while (s.size() % 4 != 0) s = '0' + s;
    for (int i = 0; i < (int)s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++)
            value = value * 10 + (s[i + j] - '0');
        a.insert(a.begin(), value);
    } return a;
}
void Print(const BigInt a) {
    int L = a.size(); printf("%d", a[L - 1]);
    for (int i = L - 2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
BigInt operator + (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size() || i < (int)b.size(); i++) {
        if (i < (int)a.size()) carry += a[i];
        if (i < (int)b.size()) carry += b[i];
        c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
BigInt operator - (const BigInt a, const BigInt b) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int s = a[i] - carry;
        if (i < (int)b.size()) s -= b[i];
        if (s < 0) s += BASE, carry = 1; else carry = 0;
        c.push_back(s);
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}
BigInt operator * (const BigInt a, const int mul) {
    BigInt c; int carry = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        carry += a[i] * mul; c.push_back(carry % BASE); carry /= BASE;
    }
    if (carry) c.push_back(carry); return c;
}
BigInt operator * (const BigInt a, const BigInt b) {
    BigInt c(a.size() + b.size() + 5, 0);
    for (int i = 0; i < (int)a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < (int)b.size(); j++) {
            int k = i + j; c[k] += a[i] * b[j] + carry;
            carry = c[k] / BASE; c[k] %= BASE;
        }
        if (carry) c[i + b.size()] += carry;
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back(); return c;
}
bool operator < (BigInt a, BigInt b) {
    while (a.size() && *a.rbegin() == 0) a.pop_back();
    while (b.size() && *b.rbegin() == 0) b.pop_back();
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

ll tongchuso(string a) {
  ll res = 0;
  for (int i = 0; i < a.size(); i++) res += a[i] - '0';
  return res % 9;
}

void Solve(){
  cin >> a >> b;
//  cout << c << endl;
  BigInt A = Init(a);
    BigInt B = Init(b);
    BigInt chin = Init("9");
    BigInt tam = Init("8");
    BigInt bay = Init("7");
    BigInt sau = Init("6");
    BigInt nam = Init("5");
    BigInt bon = Init("4");
    BigInt ba = Init("3");
    BigInt hai = Init("2");
    BigInt mot = Init("1");
    BigInt khong = Init("0");
    BigInt hieu = B - A;
  if(chin < hieu) {
    cout << 9;
    return;
  }

  ll tmp = tongchuso(b) % 9, tcsa = tongchuso(a) % 9, dai = 0;
  if (hieu == chin) dai = 9;
  else if (hieu == tam) dai = 8;
  else if (hieu == bay) dai = 7;
  else if (hieu == sau) dai = 6;
  else if (hieu == nam) dai = 5;
  else if (hieu == bon) dai = 4;
  else if (hieu == ba) dai = 3;
  else if (hieu == hai) dai = 2;
  else if (hieu == mot) dai = 1;
  else if (hieu == khong) dai = 0;
//  cout << "Haha\n";
  for (int i = 1; i <= dai; i++) {
    tmp = (tmp * tcsa) % 9;
    tcsa = (tcsa + 1) % 9;
//    cout << tmp << endl;
  }
  tmp %= 9;
  if (tmp == 0) tmp = 9;
  cout << tmp;
}


