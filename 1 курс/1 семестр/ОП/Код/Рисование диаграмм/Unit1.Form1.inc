procedure InitializeComponent;
    begin
        self.PieChartPictureBox := new System.Windows.Forms.PictureBox();
        self.BarChartPictureBox := new System.Windows.Forms.PictureBox();
        self.label1 := new System.Windows.Forms.Label();
        self.label2 := new System.Windows.Forms.Label();
        self.DrawButton := new System.Windows.Forms.Button();
        self.LangNumsComboBox := new System.Windows.Forms.ComboBox();
        self.label3 := new System.Windows.Forms.Label();
        self.LangListPictureBox := new System.Windows.Forms.PictureBox();
        self.label4 := new System.Windows.Forms.Label();
        self.MiddlePercentLabel := new System.Windows.Forms.Label();
        self.MaxPercentLabel := new System.Windows.Forms.Label();
        self.listBox1 := new System.Windows.Forms.ListBox();
        (System.ComponentModel.ISupportInitialize(self.PieChartPictureBox)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.BarChartPictureBox)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.LangListPictureBox)).BeginInit();
        self.SuspendLayout();
        // 
        // PieChartPictureBox
        // 
        self.PieChartPictureBox.Location := new System.Drawing.Point(12, 37);
        self.PieChartPictureBox.Name := 'PieChartPictureBox';
        self.PieChartPictureBox.Size := new System.Drawing.Size(400, 400);
        self.PieChartPictureBox.TabIndex := 0;
        self.PieChartPictureBox.TabStop := false;
        self.PieChartPictureBox.Paint += PieChartPictureBox_Paint;
        // 
        // BarChartPictureBox
        // 
        self.BarChartPictureBox.Location := new System.Drawing.Point(695, 37);
        self.BarChartPictureBox.Name := 'BarChartPictureBox';
        self.BarChartPictureBox.Size := new System.Drawing.Size(400, 400);
        self.BarChartPictureBox.TabIndex := 1;
        self.BarChartPictureBox.TabStop := false;
        self.BarChartPictureBox.Paint += BarChartPictureBox_Paint;
        // 
        // label1
        // 
        self.label1.Font := new System.Drawing.Font('Century', 21.75, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(0)));
        self.label1.Location := new System.Drawing.Point(12, -2);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(400, 36);
        self.label1.TabIndex := 2;
        self.label1.Text := 'Круговая диаграмма';
        self.label1.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // label2
        // 
        self.label2.Font := new System.Drawing.Font('Century', 21.75, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.label2.Location := new System.Drawing.Point(695, -2);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(400, 36);
        self.label2.TabIndex := 3;
        self.label2.Text := 'Столбчатая диаграмма';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // DrawButton
        // 
        self.DrawButton.Font := new System.Drawing.Font('Century', 12, (System.Drawing.FontStyle((System.Drawing.FontStyle.Bold or System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.DrawButton.Location := new System.Drawing.Point(501, 37);
        self.DrawButton.Name := 'DrawButton';
        self.DrawButton.Size := new System.Drawing.Size(119, 49);
        self.DrawButton.TabIndex := 4;
        self.DrawButton.Text := 'Рисовать';
        self.DrawButton.UseVisualStyleBackColor := true;
        self.DrawButton.Visible := false;
        self.DrawButton.Click += DrawButton_Click;
        // 
        // LangNumsComboBox
        // 
        self.LangNumsComboBox.FormattingEnabled := true;
        self.LangNumsComboBox.Items.AddRange(new System.Object[10]('1', '2', '3', '4', '5', '6', '7', '8', '9', '10'));
        self.LangNumsComboBox.Location := new System.Drawing.Point(501, 112);
        self.LangNumsComboBox.Name := 'LangNumsComboBox';
        self.LangNumsComboBox.Size := new System.Drawing.Size(119, 21);
        self.LangNumsComboBox.TabIndex := 5;
        self.LangNumsComboBox.TextChanged += LangNumsComboBox_TextChanged;
        // 
        // label3
        // 
        self.label3.ImageAlign := System.Drawing.ContentAlignment.TopCenter;
        self.label3.Location := new System.Drawing.Point(501, 93);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(119, 16);
        self.label3.TabIndex := 6;
        self.label3.Text := 'Кол-во языков';
        self.label3.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // LangListPictureBox
        // 
        self.LangListPictureBox.Location := new System.Drawing.Point(501, 171);
        self.LangListPictureBox.Name := 'LangListPictureBox';
        self.LangListPictureBox.Size := new System.Drawing.Size(119, 266);
        self.LangListPictureBox.TabIndex := 7;
        self.LangListPictureBox.TabStop := false;
        self.LangListPictureBox.Paint += LangListPictureBox_Paint;
        // 
        // label4
        // 
        self.label4.AutoSize := true;
        self.label4.Font := new System.Drawing.Font('Microsoft Sans Serif', 9.75, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.label4.Location := new System.Drawing.Point(663, 421);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(26, 16);
        self.label4.TabIndex := 8;
        self.label4.Text := '0%';
        // 
        // MiddlePercentLabel
        // 
        self.MiddlePercentLabel.Font := new System.Drawing.Font('Microsoft Sans Serif', 9.75, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.MiddlePercentLabel.Location := new System.Drawing.Point(638, 53);
        self.MiddlePercentLabel.Name := 'MiddlePercentLabel';
        self.MiddlePercentLabel.Size := new System.Drawing.Size(51, 368);
        self.MiddlePercentLabel.TabIndex := 9;
        self.MiddlePercentLabel.Text := '?%';
        self.MiddlePercentLabel.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
        // 
        // MaxPercentLabel
        // 
        self.MaxPercentLabel.Font := new System.Drawing.Font('Microsoft Sans Serif', 9.75, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, (System.Byte(204)));
        self.MaxPercentLabel.Location := new System.Drawing.Point(638, 37);
        self.MaxPercentLabel.Name := 'MaxPercentLabel';
        self.MaxPercentLabel.Size := new System.Drawing.Size(51, 16);
        self.MaxPercentLabel.TabIndex := 10;
        self.MaxPercentLabel.Text := '?%';
        self.MaxPercentLabel.TextAlign := System.Drawing.ContentAlignment.MiddleRight;
        // 
        // listBox1
        // 
        self.listBox1.FormattingEnabled := true;
        self.listBox1.Location := new System.Drawing.Point(164, 155);
        self.listBox1.Name := 'listBox1';
        self.listBox1.Size := new System.Drawing.Size(213, 95);
        self.listBox1.TabIndex := 11;
        self.listBox1.SelectedIndexChanged += listBox1_SelectedIndexChanged;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(1107, 449);
        self.Controls.Add(self.listBox1);
        self.Controls.Add(self.MaxPercentLabel);
        self.Controls.Add(self.MiddlePercentLabel);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.LangListPictureBox);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.LangNumsComboBox);
        self.Controls.Add(self.DrawButton);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.BarChartPictureBox);
        self.Controls.Add(self.PieChartPictureBox);
        self.Name := 'Form1';
        self.Text := 'The TIOBE Programming Community index [Декабрь, 2021]';
        (System.ComponentModel.ISupportInitialize(self.PieChartPictureBox)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.BarChartPictureBox)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.LangListPictureBox)).EndInit();
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
