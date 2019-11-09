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

II ex_eu(LL a,LL b){
    LL x0=1,y0=0,x1=0,y1=1,xr,yr;
    while(b){
        LL q=a/b;
        a-=q*b;
        swap(a,b);
        xr=x0-q*x1;
        yr=y0-q*y1;
        x0=x1,y0=y1;
        x1=xr,y1=yr;
    }
    return {x0,y0};
}
