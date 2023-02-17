//SORTING METHODS v2.0
//DEVELOPED BY SAITER
//Здоровье кода 114% =)

function Test(var Mass, MassSort: array of integer; n: integer): boolean; //код для проверки
var 
  MassCount, MassSortCount: array[-999..999] of longint;
  i: longint;
begin
  i:= 0;
  while (i < n - 1) and (MassSort[i] <= MassSort[i + 1]) do
    i:= i + 1;
  if i < n - 1 then
    Test:= False
  else
  begin
    for i:= -999 to 999 do
    begin
      MassCount[i]:= 0;
      MassSortCount[i]:= 0;
    end;
    
    for i:= 0 to (n - 1) do
    begin
      MassCount[Mass[i]]:= MassCount[Mass[i]] + 1;
      MassSortCount[MassSort[i]]:= MassSortCount[MassSort[i]] + 1;
    end;
    
    i:= -999;
    while (i <= 999) and (MassCount[i] = MassSortCount[i]) do
      i:= i + 1;
    if i = 1000 then
      Test:= True
    else
      Test:= False;
  end;
end;


procedure EasySort(var len: integer; var EasyArr: array of integer); //легчайшая для величайшего 
begin
  var i:= 0;
  var temp: integer;
  while i < (len - 1) do
  begin
    if EasyArr[i] <= EasyArr[i + 1] then
      i:= i + 1
    else
    begin
      temp:= EasyArr[i];
      EasyArr[i]:= EasyArr[i + 1];
      EasyArr[i + 1]:= temp;
      i:= 0;
    end;
  end;
end;
  
  
procedure ChoosingSort(var len: integer; var ChoosingArr: array of integer); //сортировка выбором
begin
  var temp: integer;
  for var j:= 0 to (len - 2) do
  begin
    var k:= j;
    for var i:= j + 1 to (len - 1) do
      if ChoosingArr[k] > ChoosingArr[i] then
        k:= i;
      
      temp:= ChoosingArr[j];
      ChoosingArr[j]:= ChoosingArr[k];
      ChoosingArr[k]:= temp;
  end;
end;

procedure MergeSort(left,right:integer; var MergeArr, Rez: array of integer); //сортировка слиянием
var 
  middle,n1,n2:integer; 
begin
  if right <= left then 
    exit 
  else 
  begin
    middle:= (left + right) div 2;                //
    MergeSort(left, middle, MergeArr, Rez);       // рекурсивная
    MergeSort(middle + 1, right, MergeArr, Rez);  //    часть
    n1:= left; n2:= middle + 1;                   //
    
    //сортировка
    for var i:=left to right do
    begin
      if (n1 < (middle + 1))and((n2 > right) or (MergeArr[n1] < MergeArr[n2])) then
      begin
        Rez[i]:= MergeArr[n1]; 
        inc(n1);
      end 
      
      else 
      begin
        Rez[i]:= MergeArr[n2]; 
        inc(n2);
      end;
      
    end;
    for var j:= left to right do
      MergeArr[j]:= Rez[j];
  end; 
end;

procedure ElapsedTimeOutput (var Arr: array of integer; n: integer);
begin
  var EasyArr: array of integer; //копия исхоного массива для простейщей сортировки
  var ChoosingArr: array of integer; //копия исхоного массива для выборочной сортировки
  var MergeArr: array of integer; //копия исхоного массива для сортировки слиянием
  var Rez: array of integer; //буферный массив для сортировки слиянем
  
  writeln();
  writeln('N: ', n);
  writeln();  
  if (n < 1000) then
  begin
    writeln('Простейщая соритровка');
    
    SetLength(EasyArr, n);
    for var i:= 0 to (n - 1) do
      EasyArr[i]:= Arr[i];
    
    Milliseconds;
    EasySort(n, EasyArr); 
    var timer:= MillisecondsDelta;
    
    if Test(Arr, EasyArr, n) then
      writeln('Времени затрачено: ', timer / 1000, ' с');
    
    writeln('');
  end;
  
  if (n < 100000) then
  begin
    writeln('Сортировка выбором');
    
    SetLength(ChoosingArr, n);
    for var i:= 0 to (n - 1) do
      ChoosingArr[i]:= Arr[i];
    
    Milliseconds;
    ChoosingSort(n, ChoosingArr);
    var timer:= MillisecondsDelta;
    
    if Test(Arr, ChoosingArr, n) then
       writeln('Времени затрачено: ', timer / 1000, ' с');
    
    writeln('');
  end;
  
  
  writeln('Сортировка слиянием');
  
  SetLength(MergeArr, n);
  SetLength(Rez, n);
  for var i:= 0 to (n - 1) do
    MergeArr[i]:= Arr[i];
  
  Milliseconds;
  MergeSort(0, (n - 1), MergeArr, Rez);
  var timer:= MillisecondsDelta;
  
  if Test(Arr, MergeArr, n) then 
    writeln('Времени затрачено: ', timer / 1000, ' с');
  
  writeln();
  writeln('##################################');
  
end;


begin // main
  var Arr: array of integer; //исходный массив
  var n: integer:= 10;
  
  SetLength(Arr, 100000000);
  for var i:= 0 to (1000000 - 1) do
    Arr[i]:= (random(1999) - 999);
  
  while n <> 1000000000 do
  begin
    ElapsedTimeOutput(Arr, n);
    n:= n * 10;
  end;
  
end.