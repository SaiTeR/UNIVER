Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

var
  IsButtonClicked: boolean:= False;

type
  Form1 = class(Form)
    procedure DrawButton_Click(sender: Object; e: EventArgs);
    procedure PieChartPictureBox_Paint(sender: Object; e: PaintEventArgs);
    procedure BarChartPictureBox_Paint(sender: Object; e: PaintEventArgs);
   
    procedure LangListPictureBox_Paint(sender: Object; e: PaintEventArgs);
    procedure LangNumsComboBox_TextChanged(sender: Object; e: EventArgs);
  {$region FormDesigner}
  internal
    {$resource Unit1.Form1.resources}
    PieChartPictureBox: PictureBox;
    BarChartPictureBox: PictureBox;
    label1: &Label;
    label2: &Label;
    DrawButton: Button;
    label3: &Label;
    LangListPictureBox: PictureBox;
    label4: &Label;
    MiddlePercentLabel: &Label;
    MaxPercentLabel: &Label;
    LangNumsComboBox: ComboBox;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;
  
  

implementation
  const ymin = 0.0;
  var 
    LangColor: array[1..10] of System.Drawing.Color = 
    (
    System.Drawing.Color.Green, System.Drawing.Color.Blue, System.Drawing.Color.Fuchsia,
    System.Drawing.Color.Red, System.Drawing.Color.Navy, System.Drawing.Color.Maroon,
    System.Drawing.Color.Teal, System.Drawing.Color.Olive, System.Drawing.Color.Purple,
    System.Drawing.Color.Black
    );
  
    Languages: array[1..10] of string = 
    (
    'Python', 'C', 'Java', 'C++', 'C#', 
    'Visual Basic', 'JavaScript', 
    'Assembly lng', 'SQL', 'Swift'
    );
    
    Rating: array[1..10] of real = 
    (
    12.90, 11.80, 10.12, 7.73, 6.40,
    5.40, 2.30,
    2.25, 1.79, 1.76 //1.79 1.76
    );

  procedure Form1.DrawButton_Click(sender: Object; e: EventArgs);
  begin
    IsButtonClicked:= True;
    PieChartPictureBox.Refresh;
    BarChartPictureBox.Refresh;
    LangListPictureBox.Refresh;
  end;
  
  procedure Form1.PieChartPictureBox_Paint(sender: Object; e: PaintEventArgs);
  begin
    if IsButtonClicked then
    begin
      var gr:= e.Graphics;
      var BlackPen:= new System.Drawing.Pen(Color.Black, 3.0); //создаем черную ручку (толщиной 3.0) для риссования контуров
      var DiagEllipse:= new System.Drawing.Rectangle(0 + 20, 0 + 20, (PieChartPictureBox.Width - 20 - 3), (PieChartPictureBox.Height - 20 - 3)); //создаем эллип в котором заполнять куски
      
      gr.FillEllipse(System.Drawing.Brushes.Gray, DiagEllipse); //сразу заполняем круг серым
      
      var KolLang:= StrToInt(LangNumsComboBox.Text);
      var rad1:real:= -90; //нижняя граница радиана

      for var i:= 1 to KolLang do
      begin
        //нужно рассчитать какое количество градусов занимает определенный язык, те нужно взять процент этого языка относительно окружности и перевести этот процент от окружности в радианы
        gr.FillPie(new System.Drawing.SolidBrush(LangColor[i]), DiagEllipse, rad1, (360 / 100 * Rating[i]));
        rad1 += (360 / 100 * Rating[i]);
      end;
      gr.DrawEllipse(BlackPen, DiagEllipse); //прорисовываем контур
    end;
  end;
  
  procedure Form1.BarChartPictureBox_Paint(sender: Object; e: PaintEventArgs);
  begin
    if IsButtonClicked then
    begin
      var gr:= e.Graphics;
      
      var KolLang:= StrToInt(LangNumsComboBox.Text);
      var sum: real:= 0;
      for var i:= 1 to KolLang do
        sum += Rating[i];
      
      var step:= round((BarChartPictureBox.Width) / (KolLang + 1));
      var x:= 0;
      var y: real; 
      var k:= 50 / Rating[1]; //коэффициент маштабирования столбца(делает чтобы первый стобец был высотой в 50% от PictureBox.Height, а остальные масштабировались относительно его)
      for var i:= 1 to KolLang do
        begin
          y:= BarChartPictureBox.Height - ((BarChartPictureBox.Height / 100 * Rating[i]) * k); // высчитываем сколько нужно взять от вершины PictureBox для вычисления высоты столбца
          gr.FillRectangle(new System.Drawing.SolidBrush(LangColor[i]), x, y, step, BarChartPictureBox.Height);
          x += step;
        end;
        
      
      gr.FillRectangle(new System.Drawing.SolidBrush(System.Drawing.Color.Gray), x, 0, step, BarChartPictureBox.Height); // дорисовываем оставшийся серый столбик
      
      MiddlePercentLabel.Text:= FloatToStr(Rating[1]) + '%';
      MaxPercentLabel.Text:= FloatToStr(Rating[1] * 2) + '%';
    end;
  end;
  
  procedure Form1.LangListPictureBox_Paint(sender: Object; e: PaintEventArgs);
  begin
    if IsButtonClicked then
    begin
      var gr:= e.Graphics;
      var KolLang:= StrToInt(LangNumsComboBox.Text);
      var step:= LangListPictureBox.Height / (KolLang + 1);
      var xt:= 20;
      var yt:= xt / 2;
      
      for var i:= 1to KolLang do
      begin
        gr.DrawString(Languages[i], new System.Drawing.Font('Courier', 8),  new System.Drawing.SolidBrush(LangColor[i]), xt, yt);
        yt += step;
      end;
      
      gr.DrawString('Другие', new System.Drawing.Font('Courier', 8),  System.Drawing.Brushes.Gray, xt, yt);
    end;
  end;

procedure Form1.LangNumsComboBox_TextChanged(sender: Object; e: EventArgs);
begin
  IsButtonClicked:= True;
  PieChartPictureBox.Refresh;
  BarChartPictureBox.Refresh;
  LangListPictureBox.Refresh;
end;



end.
