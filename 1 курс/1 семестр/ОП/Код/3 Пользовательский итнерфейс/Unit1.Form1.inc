procedure InitializeComponent;
    begin
        self.CalculateButton := new System.Windows.Forms.Button();
        self.ArgumentTextBox := new System.Windows.Forms.TextBox();
        self.AccuracyTextBox := new System.Windows.Forms.TextBox();
        self.label2 := new System.Windows.Forms.Label();
        self.label3 := new System.Windows.Forms.Label();
        self.label4 := new System.Windows.Forms.Label();
        self.label5 := new System.Windows.Forms.Label();
        self.CalculationOutputLabel := new System.Windows.Forms.Label();
        self.IterationsOutputLabel := new System.Windows.Forms.Label();
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // CalculateButton
        // 
        self.CalculateButton.Font := new System.Drawing.Font('Microsoft Sans Serif', 20);
        self.CalculateButton.Location := new System.Drawing.Point(160, 322);
        self.CalculateButton.Name := 'CalculateButton';
        self.CalculateButton.Size := new System.Drawing.Size(315, 95);
        self.CalculateButton.TabIndex := 0;
        self.CalculateButton.Text := 'ВЫЧИСЛИТЬ';
        self.CalculateButton.UseVisualStyleBackColor := true;
        self.CalculateButton.Click += CalculateButton_Click;
        // 
        // ArgumentTextBox
        // 
        self.ArgumentTextBox.Location := new System.Drawing.Point(100, 125);
        self.ArgumentTextBox.Name := 'ArgumentTextBox';
        self.ArgumentTextBox.Size := new System.Drawing.Size(150, 20);
        self.ArgumentTextBox.TabIndex := 1;
        self.ArgumentTextBox.TextChanged += ArgumentTextBox_TextChanged;
        // 
        // AccuracyTextBox
        // 
        self.AccuracyTextBox.Location := new System.Drawing.Point(400, 125);
        self.AccuracyTextBox.Name := 'AccuracyTextBox';
        self.AccuracyTextBox.Size := new System.Drawing.Size(150, 20);
        self.AccuracyTextBox.TabIndex := 4;
        self.AccuracyTextBox.TextChanged += AccuracyTextBox_TextChanged;
        // 
        // label2
        // 
        self.label2.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.label2.Location := new System.Drawing.Point(100, 99);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(150, 23);
        self.label2.TabIndex := 5;
        self.label2.Text := 'Значение аргумента';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // label3
        // 
        self.label3.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.label3.Location := new System.Drawing.Point(400, 99);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(150, 23);
        self.label3.TabIndex := 6;
        self.label3.Text := 'Точность';
        self.label3.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // label4
        // 
        self.label4.Font := new System.Drawing.Font('Microsoft Sans Serif', 12);
        self.label4.Location := new System.Drawing.Point(100, 193);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(196, 23);
        self.label4.TabIndex := 7;
        self.label4.Text := 'Значение функции';
        // 
        // label5
        // 
        self.label5.Font := new System.Drawing.Font('Microsoft Sans Serif', 12);
        self.label5.Location := new System.Drawing.Point(100, 249);
        self.label5.Name := 'label5';
        self.label5.Size := new System.Drawing.Size(150, 23);
        self.label5.TabIndex := 8;
        self.label5.Text := 'Число итераций';
        // 
        // CalculationOutputLabel
        // 
        self.CalculationOutputLabel.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.CalculationOutputLabel.ForeColor := System.Drawing.Color.Red;
        self.CalculationOutputLabel.Location := new System.Drawing.Point(400, 193);
        self.CalculationOutputLabel.Name := 'CalculationOutputLabel';
        self.CalculationOutputLabel.Size := new System.Drawing.Size(100, 23);
        self.CalculationOutputLabel.TabIndex := 9;
        self.CalculationOutputLabel.Text := '???';
        // 
        // IterationsOutputLabel
        // 
        self.IterationsOutputLabel.Font := new System.Drawing.Font('Microsoft Sans Serif', 10);
        self.IterationsOutputLabel.ForeColor := System.Drawing.Color.Red;
        self.IterationsOutputLabel.Location := new System.Drawing.Point(400, 249);
        self.IterationsOutputLabel.Name := 'IterationsOutputLabel';
        self.IterationsOutputLabel.Size := new System.Drawing.Size(100, 23);
        self.IterationsOutputLabel.TabIndex := 10;
        self.IterationsOutputLabel.Text := '???';
        // 
        // label1
        // 
        self.label1.AutoSize := true;
        self.label1.Font := new System.Drawing.Font('Microsoft Sans Serif', 20);
        self.label1.Location := new System.Drawing.Point(160, 39);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(315, 31);
        self.label1.TabIndex := 11;
        self.label1.Text := 'Функция f(x) = 1 / (x + 1)';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(624, 441);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.IterationsOutputLabel);
        self.Controls.Add(self.CalculationOutputLabel);
        self.Controls.Add(self.label5);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.AccuracyTextBox);
        self.Controls.Add(self.ArgumentTextBox);
        self.Controls.Add(self.CalculateButton);
        self.MaximizeBox := false;
        self.MinimizeBox := false;
        self.Name := 'Form1';
        self.Text := 'Итеративная сумма v1.337';
        self.Load += Form1_Load;
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
