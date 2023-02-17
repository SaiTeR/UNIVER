Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

type
  Form1 = class(Form)
    procedure DrawingBox_Paint(sender: Object; e: PaintEventArgs);
    procedure DrawButton_Click(sender: Object; e: EventArgs);
    procedure ClearButton_Click(sender: Object; e: EventArgs);
    procedure Form1_Load(sender: Object; e: EventArgs);
  {$region FormDesigner}
  internal
    {$resource Unit1.Form1.resources}
    DrawButton: Button;
    ClearButton: Button;
    DrawingBox: PictureBox;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;

implementation
  
  procedure Form1.DrawingBox_Paint(sender: Object; e: PaintEventArgs);
  begin
    
    var g:= e.Graphics;
    
    g.DrawEllipse(new System.Drawing.Pen(Color.Green, 10.0), 10, 10, 100, 100);
    g.FillEllipse(System.Drawing.Brushes.Red, 10, 10, 100, 100);
    
    var zxc:= 10; // это какойто треш
    while zxc <> 120 do
    begin
      g.DrawLine(new System.Drawing.Pen(Color.Green, 3.0), 150, zxc, 300, zxc);
      zxc += 10;
    end;
    
    zxc:= 150; // да и это тоже
    while zxc <> 300 do
    begin
      g.DrawLine(new System.Drawing.Pen(Color.Green, 3.0), zxc, 110, zxc, 10);
      zxc += 10;
    end;
    
    g.DrawRectangle(new System.Drawing.Pen(Color.Red, 10.0), 150, 10, 150, 100);
    
    g.DrawLine(new System.Drawing.Pen(Color.Black, 10.0), 0, 150, DrawingBox.Width, 150);
    
    g.DrawString('рисунок',  new System.Drawing.Font('Courier', 35),  System.Drawing.Brushes.Blue, 100, 175);
    
    //g.FillRectangle(new System.Drawing.Brush., 150, 10, 150, 100);
    //g.DrawString('123456789',new System.Drawing.Font('Arial',16),new System.Drawing.SolidBrush(system.Drawing.Color.Black),100,50)
  end;

  procedure Form1.DrawButton_Click(sender: Object; e: EventArgs);
  begin
    DrawingBox.Visible:= True;
  end;

  procedure Form1.ClearButton_Click(sender: Object; e: EventArgs);
  begin
    DrawingBox.Visible:= False;
  end;

  procedure Form1.Form1_Load(sender: Object; e: EventArgs);
  begin
    
  end;

end.
