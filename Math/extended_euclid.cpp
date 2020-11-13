{Thuật toán Euclide: a, b không đồng thời bằng 0, trả về gcd(a, b)}
function gcd(a, b);
begin
  while b ≠ 0 do
    begin
      r:= a mod b; a:= b; b:= r;
    end;
  Result:= a;
end;
{Thuật toán Euclide mở rộng: a, b không đồng thời bằng 0, trả về cặp (x, y) sao cho a * x + b * y = gcd(a, b)
Về tư tưởng là ghép quá trình tính cặp số (x, y) vào trong vòng lặp chính của thuật toán Euclide.}
function Extended_gcd(a, b);
begin
  (xa, ya):= (1, 0);
  (xb, yb):= (0, 1);
  while b ≠ 0 do
    begin
      q:= a div b;
      r:= a mod b; a:= b; b:= r; //Đoạn này giống thuật toán Euclide.
      (xr, yr):= (xa, ya) - q * (xb, yb); //Hiểu là: (xr, yr):= (xa, ya) "mod" (xb, yb);
      (xa, ya):= (xb, yb);
      (xb, yb):= (xr, yr);
    end;
  Result:= (xa, ya);
end;

ii ex_eu(ll a,ll b){
    ll x0=1,y0=0,x1=0,y1=1,xr,yr;
    while(b){
        ll q=a/b;
        a-=q*b;
        swap(a,b);
        xr=x0-q*x1;
        yr=y0-q*y1;
        x0=x1,y0=y1;
        x1=xr,y1=yr;
    }
    return {x0,y0};
}


int d, x, y;
void extendedEuclid(int A, int B) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main() {
    extendedEuclid(16, 10);
    cout << "gcd(16, 10) = " << d << endl;
    cout << "x, y: " << x <<  ", " << y << endl;
    return 0;
}
