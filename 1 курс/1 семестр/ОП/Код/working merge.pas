//НУ КААААААК СДЕЛАТЬ MERGESORT С ДИНМАМИЧЕСКИМ МАССИВОМ КААААААААААААААААААААААААААААААААААК
var
  mas: array of integer;
  rez:array of integer;
Procedure MergeSort(left,right:integer);
  var 
    middle,n1,n2:integer; 
begin
  if right <= left then 
    exit 
  else 
  begin
    middle:= (left + right) div 2;
    MergeSort(left, middle);
    MergeSort(middle + 1, right);
    n1:= left; n2:= middle + 1;
    for var i:=left to right do 
    begin
      if (n1 < (middle + 1))and((n2 > right)or(mas[n1] < mas[n2])) then
      begin
        rez[i]:= mas[n1]; 
        inc(n1);
      end 
      else 
      begin
        rez[i]:= mas[n2]; 
        inc(n2);
      end;
    end;
    for var j:= left to right do
      mas[j]:= rez[j];
  end; 
end;

begin
  var n: integer;
  readln(n);
  SetLength(mas, n);
  SetLength(rez, n);
  for var i:= 0 to (n - 1) do
    mas[i]:= random(10);
  
  writeln(mas);
  MergeSort(0, n - 1);
  writeln(mas);
end.