procedure InitializeComponent;
    begin
        self.DrawButton := new System.Windows.Forms.Button();
        self.DrawingBox := new System.Windows.Forms.PictureBox();
        self.ClearButton := new System.Windows.Forms.Button();
        (System.ComponentModel.ISupportInitialize(self.DrawingBox)).BeginInit();
        self.SuspendLayout();
        // 
        // DrawButton
        // 
        self.DrawButton.Location := new System.Drawing.Point(479, 72);
        self.DrawButton.Name := 'DrawButton';
        self.DrawButton.Size := new System.Drawing.Size(133, 55);
        self.DrawButton.TabIndex := 0;
        self.DrawButton.Text := 'Рисовать';
        self.DrawButton.UseVisualStyleBackColor := true;
        self.DrawButton.Click += DrawButton_Click;
        // 
        // DrawingBox
        // 
        self.DrawingBox.Location := new System.Drawing.Point(12, 41);
        self.DrawingBox.Name := 'DrawingBox';
        self.DrawingBox.Size := new System.Drawing.Size(418, 254);
        self.DrawingBox.TabIndex := 1;
        self.DrawingBox.TabStop := false;
        self.DrawingBox.Visible := false;
        self.DrawingBox.Paint += DrawingBox_Paint;
        // 
        // ClearButton
        // 
        self.ClearButton.Location := new System.Drawing.Point(479, 240);
        self.ClearButton.Name := 'ClearButton';
        self.ClearButton.Size := new System.Drawing.Size(133, 55);
        self.ClearButton.TabIndex := 2;
        self.ClearButton.Text := 'Стереть';
        self.ClearButton.UseVisualStyleBackColor := true;
        self.ClearButton.Click += ClearButton_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(624, 441);
        self.Controls.Add(self.ClearButton);
        self.Controls.Add(self.DrawingBox);
        self.Controls.Add(self.DrawButton);
        self.Name := 'Form1';
        self.Text := 'Рисование красного круга ну и еще там прямоугольник в клетку';
        self.Load += Form1_Load;
        (System.ComponentModel.ISupportInitialize(self.DrawingBox)).EndInit();
        self.ResumeLayout(false);
    end;
