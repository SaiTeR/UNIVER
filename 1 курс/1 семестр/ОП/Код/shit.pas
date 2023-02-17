Function MergeSort(first,final:integer; mas: array of biginteger):array of biginteger;
var 
  middle,n1,n2:integer; 
  rez:array of biginteger;
begin
  SetLength(rez, final);
  if final <= first then 
    exit 
  else 
  begin
    middle:= (first + final) div 2;
    MergeSort(first,middle, mas);
    MergeSort(middle,final, mas);
    n1:=first; n2:=middle;
    
    for var i:=first to (final - 1) do 
    begin
      if (n1 < middle)and((n2 > final) or (mas[n1] < mas[n2])) then
      begin
        rez[i]:=mas[n1]; 
        inc(n1);
      end 
      else 
      begin
        rez[i]:=mas[n2]; 
        inc(n2);
      end;
      
    end;
    
    for var j:=first to (final - 1) do
      mas[j]:=rez[j];
  end; 
  MergeSort:= mas;
end;

begin
  var mas: array of biginteger;
  SetLength(mas, 10);
  for var i:= 0 to 9 do
    mas[i] := random(10);
  writeln(mas);
  MergeSort(0, 10, mas);
  writeln(mas);
end.