Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

type
  Form1 = class(Form)
    procedure Form1_Load(sender: Object; e: EventArgs);
    procedure CalculateButton_Click(sender: Object; e: EventArgs);
    procedure ArgumentTextBox_TextChanged(sender: Object; e: EventArgs);
    procedure AccuracyTextBox_TextChanged(sender: Object; e: EventArgs);
  {$region FormDesigner}
  internal
    {$resource Unit1.Form1.resources}
    CalculateButton: Button;
    ArgumentTextBox: TextBox;
    AccuracyTextBox: TextBox;
    label2: &Label;
    label3: &Label;
    label4: &Label;
    label5: &Label;
    CalculationOutputLabel: &Label;
    label1: &Label;
    IterationsOutputLabel: &Label;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;



implementation

  procedure Form1.Form1_Load(sender: Object; e: EventArgs);
  begin
    
  end;

  procedure Form1.CalculateButton_Click(sender: Object; e: EventArgs);
  begin 
    
    if ((ArgumentTextBox.Text).IsReal = False) or ((AccuracyTextBox.Text).IsReal = False) then
    begin
      if ((ArgumentTextBox.Text).IsReal = False) then
        ArgumentTextBox.Text:= 'Неверный формат данных';
      if ((AccuracyTextBox.Text).IsReal = False) then
        AccuracyTextBox.Text:= 'Неверный формат данных';
      
      Exit;
    end;
      
      
    var x: real:= StrToFloat(ArgumentTextBox.Text); //аргумент
    var eps_temp:= AccuracyTextBox.Text;
    var eps: real:= StrToFloat(AccuracyTextBox.Text); //точность
    var s: real:= 1; var a: real:= 1; var itr:= 2;
    
    while abs(a) > eps do
    begin
      a:= -x * a;
      s:= s + a;
      itr += 1;
    end;
    
    var cnt:= 0;                          //
    for var i:= 1 to length(eps_temp) do  // ДАЖЕ СТИВ ДЖОБС БЫЛ В ШОКЕ
      if eps_temp[i] = '0' then           // КОГДА УВИДЕЛ
        inc(cnt);                         // ЧТО ЗА АЛГОРИТМ ПРИДУМАЛ
    var pwr:= power(10, cnt);             // ЭТОТ МАЛЬЧИК ИЗ ТОМСКА
    s:= (Round(s*pwr)) / pwr;             //
    
    CalculationOutputLabel.Text:= FloatToStr(s);
    IterationsOutputLabel.Text:= FloatToStr(itr);
  end;

  procedure Form1.ArgumentTextBox_TextChanged(sender: Object; e: EventArgs);
  begin
    CalculationOutputLabel.Text:= '???';
    IterationsOutputLabel.Text:= '???';
  end;
  
  procedure Form1.AccuracyTextBox_TextChanged(sender: Object; e: EventArgs);
  begin
    CalculationOutputLabel.Text:= '???';
    IterationsOutputLabel.Text:= '???';
  end;


end.
