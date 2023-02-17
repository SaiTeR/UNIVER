Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

type
  Form1 = class(Form)
    procedure LinearButton_Click(sender: Object; e: EventArgs);
    procedure OrderedButton_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  internal
    {$resource Unit1.Form1.resources}
    NumTextBox: TextBox;
    label1: &Label;
    LinearButton: Button;
    OrderedButton: Button;
    LinearListBox: ListBox;
    OrderedListBox: ListBox;
    MergeListBox: ListBox;
    MergeButton: Button;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation
  type 
    point = ^L; //указатель списка LinearList
    L = record // определяем запись 
      data: integer; // поле в записи отвечающее за тип данных в списке
      next: point // поле содержащее ажрес следующего элемента
    end;
        
  procedure Form1.LinearButton_Click(sender: Object; e: EventArgs);
  begin
    //var head: point; // указатель на первый элемент списка
    var LinearPointer: point; // вспомогательный указатель для создания очередного элемента списка
    var s: integer; // переменная в которую будем загонять числа
    
    LinearListBox.Items.Clear;
    var Num:= StrToInt(NumTextBox.Text);
    
    new(LinearPointer); // выделяем место в памяти для элемента списка
    var head:= LinearPointer; // ГОЛОВА ДАЙ ДЕНЕГ, ДАЙ ДЕНЕГ ГОЛОВА
    s:= PABCSystem.Random(-999, 999);
    LinearPointer^.data:= s;
    for var i:= 1 to Num - 1 do
    begin
      writeln(s);
      new(LinearPointer^.next);//выделяем место для следующего элемента и передаем в поле next его адрес
      LinearPointer:= LinearPointer^.next; //сещаем указатель
      s:= PABCSystem.Random(-999, 999);
      LinearPointer^.data:= s;
      LinearPointer^.next:= nil;
    end;
    
    LinearPointer:= head;
    while LinearPointer <> nil do
    begin
      LinearListBox.Items.Add(LinearPointer^.data);
      LinearPointer:= LinearPointer^.next;
    end;
    
  end;

procedure Form1.OrderedButton_Click(sender: Object; e: EventArgs);
begin
  var OrdPointPrev, OrdPoint, OrdPointNext, Head: pointO;
  var s: integer;
  
  OrderedListBox.Items.Clear;
  var Num:= StrToInt(NumTextBox.text);
  s:= PABCSystem.Random(-999, 999);
  
  for var i:= 1 to Num do
  begin
    new(OrdPoint);
    OrdPoint^.data:= s;
    OrdPoint^.next:= nil;
    if Head = nil then
      Head:= OrderedList
    else
    begin
      dOrderedList:= Head;
      pOrderedList:= Head;
      
      while(dOrderedList <> nil) and (dOrderedList^.data <= s) do
      begin
        pOrderedList:= dOrderedList;
        dOrderedList:= dOrderedList^.next;
      end;
      
      if dOrderedList = nil then
        pOrderedList^.next:= OrderedList
      else
      begin
        OrderedList^.next:= dOrderedList;
        if dOrderedList = Head then
          Head:= OrderedList
        else
          pOrderedList^.next:= OrderedList;
      end;
    end; 
    
    s:= PABCSystem.Random(-999, 999);
  end;
  
  OrderedList:= Head;
  while OrderedList <> Nil do
  begin
    OrderedListBox.Items.Add(OrderedList^.data);
    OrderedList:= OrderedList^.next;
  end;
end;

end.
