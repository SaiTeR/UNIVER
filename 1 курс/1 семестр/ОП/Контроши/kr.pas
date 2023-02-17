type // cсоздание списка
  PNode = ^Node;
  Node = record
    data: integer;
    next: PNode;
end;
 

Procedure InsInto(Digit : integer; var Head : PNode ); // процедура поиска места в списке для переданного элемента. Врезультате выполнения процедуры получим упроядоченный список
var
  dx, px, x : PNode ;
begin
  new(x);
  x^.Data := Digit;
  x^.Next := Nil;
  if Head = Nil
    then
      Head := x
    else
      begin
        dx := Head;
        px := Head;
        while (dx<>Nil) and (dx^.Data<=Digit) do
          begin
            px := dx;
            dx :=dx^.Next;
          end;
        if dx=Nil
          then
            px^.Next := x
          else
            begin
              x^.Next := dx;
              if dx=Head
                then
                  Head := x
                else
                  px^.Next := x;
            end;
      end;
end;

begin
  var n: integer; // считываем количество элементов в списке
  var p: ^Node;
  readln(n);
  
  for var i:= 1 to n do // вводим элемент и выполняем процедуру поиска места для элемента 
  begin
    var zxc: integer;
    readln(zxc);
    InsInto(zxc, p);
  end;
  
  
  while p<>Nil do // выводим список
  begin
    write(p^.Data, ' ');
    p := p^.Next;
  end;
  
  
  while p<>nil do // удаляем список
  begin
    var t := p;
    p := p^.next;
    Dispose(t);
  end;
end.