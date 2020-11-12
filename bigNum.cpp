#include<iostream>
#include<string>
using namespace std;

string Cong(string a, string b)
{
  string res="";
  string tmpstra = "", tmpstrb = "";
  for (int i = 0; i < b.length() - a.length(); i++) tmpstra += "0";
  a = tmpstra + a;
  for (int i = 0; i < a.length() - b.length(); i++) tmpstrb += "0";
  b = tmpstrb + b;
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
 
string Tru(string a, string b)
{
  string res="";
  string tmpstra = "", tmpstrb = "";
  for (int i = 0; i < b.length() - a.length(); i++) tmpstra += "0";
  a = tmpstra + a;
  for (int i = 0; i < a.length() - b.length(); i++) tmpstrb += "0";
  b = tmpstrb + b;
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
  int top = 0;
  while (top < res.length() - 1 && res[top] == '0') top++;
  if (top) res.erase(0,top);
  if(neg) res="-"+res;
  return res;
}
 
string Nhan(string a, string b)
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
  int top = 0;
  while (top < res.length() - 1 && res[top] == '0') top++;
  if (top) res.erase(0,top);
  return res;
}


#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define endl "\n"
#define debug cout<<"debug\n"
#define pb push_back
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define FTB(i,a,b) for(ll i=a,_b=b;i<=_b;i++)
#define FT(i,a,b) for(ll i=a,_b=b;i<_b;i++)
#define FGB(i,a,b) for(ll i=a,_b=b;i>=_b;i--)
#define FG(i,a,b) for(ll i=a,_b=b;i>_b;i--)
 
ll mod=1e5;
 
vi operator +(vi a,vi b){
  vi res;
  ll tmp=0;
  FT(i,0,max(a.size(),b.size())){
    if(i<a.size()) tmp+=a[i];
    if(i<b.size()) tmp+=b[i];
    res.pb(tmp%mod);
    tmp/=mod;
  }
  if(tmp) res.pb(tmp);
  return res;
}
//chi tru duoc so lon cho so be
vi operator -(vi a,vi b){
  ll nho=0;
  vi res;
  FT(i,0,a.size()){
    ll tmp=a[i]-nho;
    if(i<b.size()) tmp-=b[i];
    if(tmp<0) tmp+=mod,nho=1;
    else nho=0;
    res.pb(tmp);
  }
  while(res.size()>1&&res.back()==0) res.pop_back();
  return res;
}

vi operator *(vi a,int z){
  vi res;
  ll tmp=0;
  FT(i,0,a.size()){
    tmp+=a[i]*z;
    res.pb(tmp%mod);
    tmp/=mod;
  }
  if(tmp) res.pb(tmp);
  return res;
}

vi operator *(vi a, vi b) {
  vi res;
  int n=a.size(),m=b.size();
  int len=n+m;
  ll tmp=0;
  FT(i,0,len){
    FT(j,0,n){
      if(j>i) break;
      if(i-j<m){
        tmp+=a[j]*b[i-j];
      }
    }
    res.pb(tmp%mod);
    tmp/=mod;
  }
  while(res.size()>1&&res.back()==0) res.pop_back();
  return res;
}

vi strtovi(string s) {
  if (s == "0") return vi(1, 0);
  int tmp = 0;
  vi res;  
  for (int i = s.size() - 1, dem = 1; i >= 0; i--, dem *= 10) {
    if (dem == mod) {
      res.push_back(tmp % mod);
      tmp /= mod;
      dem = 1;
    }
    tmp += dem * (s[i] - '0');
  }
  if (tmp) res.push_back(tmp);
  return res;
}
 
void in(vi a){
  cout<<a[a.size()-1];
  if(a.size()>1) FGB(i,a.size()-2,0){
    cout<<setfill('0')<<setw(5)<<a[i];
  }
}

void Solve(){
  string a, b; cin >> a >> b;
  vi via = strtovi(a), vib = strtovi(b);
  in(via + vib);
  cout << "\n";
  if (a.size() > b.size() || (a.size() == b.size() && a >= b))
    in(via - vib);
  else {
    cout << "-";
    in(vib - via);
  }
  cout << "\n";
  in(via * vib); 
}


int main(){
  ios::sync_with_stdio(0);cin.tie(0);

 // freopen("1.txt","r",stdin);
//  freopen("1.out","w",stdout);

  int Test_numbers=1;
//  cin>>Test_numbers;

  while(Test_numbers--) Solve();

  return 0;
}


// C++ program to implement division with large 
// number 
#include <bits/stdc++.h> 
using namespace std; 
  
// A function to perform division of large numbers 
string longDivision(string number, int divisor) 
{ 
    // As result can be very large store it in string 
    string ans; 
  
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
        temp = temp * 10 + (number[++idx] - '0'); 
  
    // Repeatedly divide divisor with temp. After 
    // every division, update temp to include one 
    // more digit. 
    while (number.size() > idx) { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
  
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
  
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
  
    // else return ans 
    return ans; 
} 
  
// Driver program to test longDivison() 
int main() 
{ 
    string number = "1248163264128256512"; 
    int divisor = 125; 
    cout << longDivision(number, divisor); 
    return 0; 
} 