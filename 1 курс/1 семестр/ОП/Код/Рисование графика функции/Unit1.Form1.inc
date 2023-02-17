procedure InitializeComponent;
    begin
        self.PictureBox := new System.Windows.Forms.PictureBox();
        self.DrawButton := new System.Windows.Forms.Button();
        self.label1 := new System.Windows.Forms.Label();
        self.label2 := new System.Windows.Forms.Label();
        self.XminTextBox := new System.Windows.Forms.TextBox();
        self.label3 := new System.Windows.Forms.Label();
        self.XmaxTextBox := new System.Windows.Forms.TextBox();
        self.label4 := new System.Windows.Forms.Label();
        self.PointsAmountTextBox := new System.Windows.Forms.TextBox();
        (System.ComponentModel.ISupportInitialize(self.PictureBox)).BeginInit();
        self.SuspendLayout();
        // 
        // PictureBox
        // 
        self.PictureBox.Location := new System.Drawing.Point(12, 49);
        self.PictureBox.Name := 'PictureBox';
        self.PictureBox.Size := new System.Drawing.Size(500, 500);
        self.PictureBox.TabIndex := 0;
        self.PictureBox.TabStop := false;
        self.PictureBox.Paint += PictureBox_Paint;
        // 
        // DrawButton
        // 
        self.DrawButton.Font := new System.Drawing.Font('Microsoft Sans Serif', 15);
        self.DrawButton.Location := new System.Drawing.Point(592, 49);
        self.DrawButton.Name := 'DrawButton';
        self.DrawButton.Size := new System.Drawing.Size(128, 63);
        self.DrawButton.TabIndex := 1;
        self.DrawButton.Text := 'Рисовать';
        self.DrawButton.UseVisualStyleBackColor := true;
        self.DrawButton.Click += DrawButton_Click;
        // 
        // label1
        // 
        self.label1.AutoSize := true;
        self.label1.Font := new System.Drawing.Font('Microsoft Sans Serif', 20);
        self.label1.Location := new System.Drawing.Point(117, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(309, 31);
        self.label1.TabIndex := 2;
        self.label1.Text := 'График функции cos(x)';
        // 
        // label2
        // 
        self.label2.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.label2.Location := new System.Drawing.Point(592, 159);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(128, 23);
        self.label2.TabIndex := 3;
        self.label2.Text := 'X минимальное';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // XminTextBox
        // 
        self.XminTextBox.Location := new System.Drawing.Point(592, 186);
        self.XminTextBox.Name := 'XminTextBox';
        self.XminTextBox.Size := new System.Drawing.Size(128, 20);
        self.XminTextBox.TabIndex := 4;
        // 
        // label3
        // 
        self.label3.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.label3.Location := new System.Drawing.Point(592, 279);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(128, 23);
        self.label3.TabIndex := 5;
        self.label3.Text := 'X максимальное';
        self.label3.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // XmaxTextBox
        // 
        self.XmaxTextBox.Location := new System.Drawing.Point(592, 305);
        self.XmaxTextBox.Name := 'XmaxTextBox';
        self.XmaxTextBox.Size := new System.Drawing.Size(128, 20);
        self.XmaxTextBox.TabIndex := 6;
        // 
        // label4
        // 
        self.label4.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.label4.Location := new System.Drawing.Point(592, 403);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(128, 23);
        self.label4.TabIndex := 7;
        self.label4.Text := 'Количество точек';
        self.label4.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // PointsAmountTextBox
        // 
        self.PointsAmountTextBox.Location := new System.Drawing.Point(592, 429);
        self.PointsAmountTextBox.Name := 'PointsAmountTextBox';
        self.PointsAmountTextBox.Size := new System.Drawing.Size(128, 20);
        self.PointsAmountTextBox.TabIndex := 8;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(784, 561);
        self.Controls.Add(self.PointsAmountTextBox);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.XmaxTextBox);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.XminTextBox);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.DrawButton);
        self.Controls.Add(self.PictureBox);
        self.Name := 'Form1';
        self.Text := 'Form1';
        self.Load += Form1_Load;
        (System.ComponentModel.ISupportInitialize(self.PictureBox)).EndInit();
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
