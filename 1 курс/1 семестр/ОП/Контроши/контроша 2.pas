procedure Search(var M: array of integer; n, k: integer);
begin
  
end;

{
procedure Search(var c: array of integer; elem: integer; var N: integer);
    var m,i,j: integer;
    begin
        m := N div 2;
        i := 1;
        j := N;
        while (c[m] <> elem) and (i <= j) do begin
            if elem > c[m] then i := m + 1
            else j := m - 1;
            m := (i+j) div 2;
        end;
        if i > j then writeln('Элемент не найден')
        else writeln(i);
    end;
}
procedure MergeSort(left,right:integer; var MergeArr, Rez, Ind: array of integer); //сортировка слиянием
var 
  middle,n1,n2:integer; 
begin
  if right <= left then 
    exit 
  else 
  begin
    middle:= (left + right) div 2;                //
    MergeSort(left, middle, MergeArr, Rez, Ind);       // рекурсивная
    MergeSort(middle + 1, right, MergeArr, Rez, Ind);  //    часть
    n1:= left; n2:= middle + 1;                   //
    
    //сортировка
    for var i:=left to right do
    begin
      if (n1 < (middle + 1))and((n2 > right) or (MergeArr[Ind[n1]] < MergeArr[Ind[n2]])) then
      begin
        Rez[i]:= MergeArr[Ind[n1]]; 
        inc(n1);
      end 
      
      else 
      begin
        Rez[i]:= MergeArr[Ind[n2]]; 
        inc(n2);
      end;
      
    end;
    for var j:= left to right do
      MergeArr[Ind[j]]:= Rez[Ind[j]];
  end; 
end;

begin
  var n: integer;
  var M: array of integer;
  var Rez: array of integer;
  var Ind: array of integer;
  
  readln(n);
  SetLength(Ind, n);
  SetLength(Rez, n);
  SetLength(M, n);
  for var i:= 0 to (n - 1) do
    M[i]:= random(30);
  for var i:= 0 to (n - 1) do
    Ind[i]:= i;
  
  MergeSort(0, (n - 1), M, Rez, Ind);
  writeln(M);
  
  
  var k: integer;
  readln(k);
  Search(M, k, n);
  
  
end.