Unit Unit1;

interface

uses System, System.Drawing, System.Windows.Forms;

var
  IsButtonClicked: boolean;
  
type
  Form1 = class(Form)
    procedure PictureBox_Paint(sender: Object; e: PaintEventArgs);
    procedure Form1_Load(sender: Object; e: EventArgs);
   
    procedure DrawButton_Click(sender: Object; e: EventArgs);
  {$region FormDesigner}
  internal
    {$resource Unit1.Form1.resources}
    DrawButton: Button;
    label1: &Label;
    label2: &Label;
    XminTextBox: TextBox;
    label3: &Label;
    XmaxTextBox: TextBox;
    label4: &Label;
    PointsAmountTextBox: TextBox;
    PictureBox: PictureBox;
    {$include Unit1.Form1.inc}
  {$endregion FormDesigner}
  public
    constructor;
    begin
      InitializeComponent;
    end;
  end;
  




implementation

  procedure Form1.PictureBox_Paint(sender: Object; e: PaintEventArgs);
  begin
   if IsButtonClicked then
   begin  
     var gr:= e.Graphics;
     var Xmin, Xmax, PointsAmount: real;
   
   ///////////////////////////////////////////////////////////////////////////
    if ((XminTextBox.Text).IsReal = False) or ((XmaxTextBox.Text).IsReal = False) or ((PointsAmountTextBox.Text).IsReal = False) then
    begin
      if (XminTextBox.Text).IsReal = False then
        XminTextBox.Text:= 'Неверное значение'
      else
        Xmin:= StrToFloat(XminTextBox.Text);
       
      if (XmaxTextBox.Text).IsReal = False then
        XmaxTextBox.Text:= 'Неверное значение'
      else
        Xmax:= StrToFloat(XmaxTextBox.Text);
       
      if (PointsAmountTextBox.Text).IsReal = False then
        PointsAmountTextBox.Text:= 'Неверное значение'
      else
        PointsAmount:= StrToFloat(PointsAmountTextBox.Text);
    end;
    ///////////////////////////////////////////////////////////////////////////
     
    if ((XminTextBox.Text).IsReal = True) and ((XmaxTextBox.Text).IsReal = True) and((PointsAmountTextBox.Text).IsReal = True) then
    begin 
      Xmin:= StrToFloat(XminTextBox.Text);
      Xmax:= StrToFloat(XmaxTextBox.Text);
      PointsAmount:= StrToFloat(PointsAmountTextBox.Text);
      
      //debug
      writeln(Xmin);
      writeln(Xmax);
      writeln(PointsAmount);
      writeln();
      //
      
      var Iter:= (Abs(Xmin) + Abs(Xmax)) / (PointsAmount + 1);
      var x, y,minY, maxY, temp_Xmin: real;
      var grX, grY: real;
      minY:= 100000;
      maxY:= -100000;
      grX:= 100000;
      grY:= 100000;
      temp_Xmin:= Xmin;
      
      while temp_Xmin <= Xmax do
      begin
        if cos(temp_Xmin) <= minY then
          minY:= cos(temp_Xmin);
        if cos(temp_Xmin) >= maxY then
          maxY:= cos(temp_Xmin);
        
        if abs(0 - temp_Xmin) < grX then
          grX:= abs(0 - temp_Xmin);
        
        if abs(0 - cos(temp_Xmin)) < grY then
          grY:= abs(0 - cos(temp_Xmin));
        
        temp_Xmin += Iter;
      end;
      
      minY:= round(minY);
      maxY:= round(maxY);
      
      
      var Xbeg:= Xmin;
      
      while Xmin <= Xmax do  
      begin
        x:= ((Xmin - Xbeg)*(PictureBox.Width - 0)) / (Xmax - Xbeg) + 1;
        y:= ((cos(Xmin) - minY)*(PictureBox.Height - 0)) / (minY - maxY) + PictureBox.Height;
        
        
        if abs(0 - Xmin) = grX then
          gr.DrawLine(new System.Drawing.Pen(Color.Black, 2.0), x + 5, 0, x + 5, 500);
        if abs(0 - cos(Xmin)) = grY then
          gr.DrawLine(new System.Drawing.Pen(Color.Black, 2.0), 0, y + 5, 500, y + 5);
        
        gr.FillEllipse(System.Drawing.Brushes.Red, x, y, 10, 10);
        
        
        Xmin += Iter;
        //writeln(Xmin);
        //writeln(x,' ', y);
      end;
      
      
    end;
     
     
     
     
    IsButtonClicked:= False;
   end;
  end;

  procedure Form1.Form1_Load(sender: Object; e: EventArgs);
  begin
    
  end;
  
  
  procedure Form1.DrawButton_Click(sender: Object; e: EventArgs);
  begin
    IsButtonClicked:= True;
    PictureBox.Refresh;

  end;


  
end.

