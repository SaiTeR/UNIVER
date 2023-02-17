procedure InitializeComponent;
    begin
        self.NumTextBox := new System.Windows.Forms.TextBox();
        self.label1 := new System.Windows.Forms.Label();
        self.LinearButton := new System.Windows.Forms.Button();
        self.OrderedButton := new System.Windows.Forms.Button();
        self.MergeButton := new System.Windows.Forms.Button();
        self.LinearListBox := new System.Windows.Forms.ListBox();
        self.OrderedListBox := new System.Windows.Forms.ListBox();
        self.MergeListBox := new System.Windows.Forms.ListBox();
        self.SuspendLayout();
        // 
        // NumTextBox
        // 
        self.NumTextBox.Location := new System.Drawing.Point(49, 61);
        self.NumTextBox.Name := 'NumTextBox';
        self.NumTextBox.Size := new System.Drawing.Size(129, 20);
        self.NumTextBox.TabIndex := 0;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(49, 36);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(129, 23);
        self.label1.TabIndex := 1;
        self.label1.Text := 'Количество элементов:';
        self.label1.TextAlign := System.Drawing.ContentAlignment.MiddleCenter;
        // 
        // LinearButton
        // 
        self.LinearButton.Location := new System.Drawing.Point(49, 106);
        self.LinearButton.Name := 'LinearButton';
        self.LinearButton.Size := new System.Drawing.Size(129, 23);
        self.LinearButton.TabIndex := 2;
        self.LinearButton.Text := 'Линейный';
        self.LinearButton.UseVisualStyleBackColor := true;
        self.LinearButton.Click += LinearButton_Click;
        // 
        // OrderedButton
        // 
        self.OrderedButton.Location := new System.Drawing.Point(248, 106);
        self.OrderedButton.Name := 'OrderedButton';
        self.OrderedButton.Size := new System.Drawing.Size(129, 23);
        self.OrderedButton.TabIndex := 3;
        self.OrderedButton.Text := 'Упорядоченный';
        self.OrderedButton.UseVisualStyleBackColor := true;
        self.OrderedButton.Click += OrderedButton_Click;
        // 
        // MergeButton
        // 
        self.MergeButton.Location := new System.Drawing.Point(442, 106);
        self.MergeButton.Name := 'MergeButton';
        self.MergeButton.Size := new System.Drawing.Size(129, 23);
        self.MergeButton.TabIndex := 4;
        self.MergeButton.Text := 'Слияние';
        self.MergeButton.UseVisualStyleBackColor := true;
        // 
        // LinearListBox
        // 
        self.LinearListBox.FormattingEnabled := true;
        self.LinearListBox.Location := new System.Drawing.Point(49, 135);
        self.LinearListBox.Name := 'LinearListBox';
        self.LinearListBox.Size := new System.Drawing.Size(129, 212);
        self.LinearListBox.TabIndex := 5;
        // 
        // OrderedListBox
        // 
        self.OrderedListBox.FormattingEnabled := true;
        self.OrderedListBox.Location := new System.Drawing.Point(248, 135);
        self.OrderedListBox.Name := 'OrderedListBox';
        self.OrderedListBox.Size := new System.Drawing.Size(129, 212);
        self.OrderedListBox.TabIndex := 6;
        // 
        // MergeListBox
        // 
        self.MergeListBox.FormattingEnabled := true;
        self.MergeListBox.Location := new System.Drawing.Point(442, 135);
        self.MergeListBox.Name := 'MergeListBox';
        self.MergeListBox.Size := new System.Drawing.Size(129, 212);
        self.MergeListBox.TabIndex := 7;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(624, 441);
        self.Controls.Add(self.MergeListBox);
        self.Controls.Add(self.OrderedListBox);
        self.Controls.Add(self.LinearListBox);
        self.Controls.Add(self.MergeButton);
        self.Controls.Add(self.OrderedButton);
        self.Controls.Add(self.LinearButton);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.NumTextBox);
        self.Name := 'Form1';
        self.Text := 'Списки';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
