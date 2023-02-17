var
    M,Rez,Ind:array of integer;
    i,s,n:integer;
Procedure MergeSort(left,right:integer);
  var 
    middle,j,i,n1,n2:integer; 
  begin
    if right<=left then 
      exit 
    else
    begin
      middle:=(left+right) div 2;
      MergeSort(left,middle);MergeSort(middle+1,right);
      n1:=left; n2:=middle+1;
        
      for i:=left to right do 
      begin
        if (n1 < (middle + 1))and((n2 > right)or(M[Ind[n1]] < M[Ind[n2]])) then
        begin
          Rez[i]:=Ind[n1]; 
          inc(n1);
        end
          
        else
        begin
          Rez[i]:=Ind[n2]; 
          inc(n2);
        end;
      end;
      for i:= left to right do
        Ind[i]:=Rez[i];
    end;
  end;
   
procedure Search(p,b,e:integer; var M,Ind:array of integer);
  var midl:integer;
  begin
    while b < e do  
      begin
      midl:=(b + e) div 2;
      if M[Ind[midl]] < p then
        b := midl + 1
      else 
        e:=midl;
      end;
      if M[Ind[b]]=p then 
        writeln(Ind[b])
      else 
        writeln('Элемент не найден');
  end;
        
   
  begin
    write('Введите количество эелментов: ');
    readln(n);
    SetLength(M,n);
    SetLength(Rez,n);
    SetLength(Ind,n);
    for i:=0 to n-1 do begin
      M[i]:=Random(11);
      Ind[i]:=i;
    end;
    
    writeln('Отсортированный массив');
    MergeSort(0, n-1);
    for i:=0 to n-1 do 
      write(M[Ind[i]]:3);
    writeln();
    write('Введите элемент для поиска: ');
    readln(s);
    write('Результат поиска: ');
    Search(s,0,n-1,M,Ind);
  
  end.