procedure ChoosingSort(var len: integer; var ChoosingArr: array of string; var Ind: array of integer); //сортировка выбором
begin
  var temp: integer;
  for var j:= 0 to (len - 2) do
  begin
    var k:= j;
    for var i:= j + 1 to (len - 1) do
      if ChoosingArr[Ind[k]] > ChoosingArr[Ind[i]] then
        k:= i;
      
      temp:= Ind[j];
      Ind[j]:= Ind[k];
      Ind[k]:= temp;
  end;
end;


begin
  var f : text;             //считываем файл
  assign(f, 'File1.txt');
  reset(f);
  
  var FArr: array of string;
  SetLength(FArr, 1);
  
  var Ind: array of integer;
  SetLength(Ind, 1);
  
  var i:= 0;
  var s: string;
  while not EoF(f) do       //копируем строки файла в массив строк
  begin                     //и параллельно с этим заполняем массив индексов
    SetLength(FArr, i + 1);
    SetLength(Ind, i + 1);
    
    readln(f, s);
    FArr[i]:= s;
    Ind[i]:= i;
    
    i+= 1;
  end;
  
  writeln('Исходные значения');
  for var j:= 0 to length(FArr) - 1 do
    writeln(Ind[j]:2, ' ', FArr[j]);
  
  var len:= length(FArr);
  ChoosingSort(len, FArr, Ind); //сортировочка
  
  writeln();
  writeln('После непосредственного упорядочения');
  for var j:= 0 to length(FArr) - 1 do
    writeln(FArr[Ind[j]]);
  
  writeln();
  writeln('После косвенного упорядочения');
  for var j:= 0 to length(FArr) - 1 do
    writeln(Ind[j]:2, ' ', FArr[j]);
  

  
end.