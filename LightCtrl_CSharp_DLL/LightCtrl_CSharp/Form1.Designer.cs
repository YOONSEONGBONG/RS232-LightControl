namespace LightCtrl_CSharp
{
    partial class LightCtrl
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.AutoTestChannel = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.AutoTestSpeed = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.AutoTestCount = new System.Windows.Forms.ComboBox();
            this.Btn_AutoTest = new System.Windows.Forms.Button();
            this.Btn_Save = new System.Windows.Forms.Button();
            this.Btn_OnOFF = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.hScrollBar_Ch1 = new System.Windows.Forms.HScrollBar();
            this.hScrollBar_Ch2 = new System.Windows.Forms.HScrollBar();
            this.hScrollBar_Ch3 = new System.Windows.Forms.HScrollBar();
            this.hScrollBar_Ch4 = new System.Windows.Forms.HScrollBar();
            this.hScrollBar_Ch5 = new System.Windows.Forms.HScrollBar();
            this.hScrollBar_Ch6 = new System.Windows.Forms.HScrollBar();
            this.textBox_Ch1 = new System.Windows.Forms.TextBox();
            this.textBox_Ch2 = new System.Windows.Forms.TextBox();
            this.textBox_Ch3 = new System.Windows.Forms.TextBox();
            this.textBox_Ch4 = new System.Windows.Forms.TextBox();
            this.textBox_Ch5 = new System.Windows.Forms.TextBox();
            this.textBox_Ch6 = new System.Windows.Forms.TextBox();
            this.Btn_WriteInit = new System.Windows.Forms.Button();
            this.Btn_Connect = new System.Windows.Forms.Button();
            this.Btn_DisConnect = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // AutoTestChannel
            // 
            this.AutoTestChannel.AllowDrop = true;
            this.AutoTestChannel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.AutoTestChannel.FormattingEnabled = true;
            this.AutoTestChannel.Items.AddRange(new object[] {
            "채널 1",
            "채널 2",
            "채널 3",
            "채널 4",
            "채널 5",
            "채널 6"});
            this.AutoTestChannel.Location = new System.Drawing.Point(78, 13);
            this.AutoTestChannel.Name = "AutoTestChannel";
            this.AutoTestChannel.Size = new System.Drawing.Size(65, 20);
            this.AutoTestChannel.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(5, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 12);
            this.label1.TabIndex = 1;
            this.label1.Text = "테스트 채널:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(148, 16);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 12);
            this.label2.TabIndex = 3;
            this.label2.Text = "SPEED:";
            // 
            // AutoTestSpeed
            // 
            this.AutoTestSpeed.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.AutoTestSpeed.FormattingEnabled = true;
            this.AutoTestSpeed.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5"});
            this.AutoTestSpeed.Location = new System.Drawing.Point(200, 13);
            this.AutoTestSpeed.Name = "AutoTestSpeed";
            this.AutoTestSpeed.Size = new System.Drawing.Size(65, 20);
            this.AutoTestSpeed.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(275, 15);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "횟 수:";
            // 
            // AutoTestCount
            // 
            this.AutoTestCount.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.AutoTestCount.FormattingEnabled = true;
            this.AutoTestCount.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5"});
            this.AutoTestCount.Location = new System.Drawing.Point(314, 12);
            this.AutoTestCount.Name = "AutoTestCount";
            this.AutoTestCount.Size = new System.Drawing.Size(65, 20);
            this.AutoTestCount.TabIndex = 4;
            // 
            // Btn_AutoTest
            // 
            this.Btn_AutoTest.Location = new System.Drawing.Point(6, 42);
            this.Btn_AutoTest.Name = "Btn_AutoTest";
            this.Btn_AutoTest.Size = new System.Drawing.Size(118, 46);
            this.Btn_AutoTest.TabIndex = 6;
            this.Btn_AutoTest.Text = "AutoTest";
            this.Btn_AutoTest.UseVisualStyleBackColor = true;
            this.Btn_AutoTest.Click += new System.EventHandler(this.Btn_AutoTest_Click);
            // 
            // Btn_Save
            // 
            this.Btn_Save.Location = new System.Drawing.Point(136, 42);
            this.Btn_Save.Name = "Btn_Save";
            this.Btn_Save.Size = new System.Drawing.Size(118, 46);
            this.Btn_Save.TabIndex = 7;
            this.Btn_Save.Text = "Save";
            this.Btn_Save.UseVisualStyleBackColor = true;
            this.Btn_Save.Click += new System.EventHandler(this.Btn_Save_Click);
            // 
            // Btn_OnOFF
            // 
            this.Btn_OnOFF.Location = new System.Drawing.Point(266, 42);
            this.Btn_OnOFF.Name = "Btn_OnOFF";
            this.Btn_OnOFF.Size = new System.Drawing.Size(118, 46);
            this.Btn_OnOFF.TabIndex = 8;
            this.Btn_OnOFF.Text = "ON";
            this.Btn_OnOFF.UseVisualStyleBackColor = true;
            this.Btn_OnOFF.Click += new System.EventHandler(this.Btn_OnOFF_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 102);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(43, 12);
            this.label4.TabIndex = 9;
            this.label4.Text = "채널 1:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 148);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(43, 12);
            this.label5.TabIndex = 10;
            this.label5.Text = "채널 2:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(8, 188);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(43, 12);
            this.label6.TabIndex = 11;
            this.label6.Text = "채널 3:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(8, 225);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(43, 12);
            this.label7.TabIndex = 12;
            this.label7.Text = "채널 4:";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(8, 265);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(43, 12);
            this.label8.TabIndex = 13;
            this.label8.Text = "채널 5:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(8, 305);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(43, 12);
            this.label9.TabIndex = 14;
            this.label9.Text = "채널 6:";
            // 
            // hScrollBar_Ch1
            // 
            this.hScrollBar_Ch1.Location = new System.Drawing.Point(52, 99);
            this.hScrollBar_Ch1.Maximum = 264;
            this.hScrollBar_Ch1.Name = "hScrollBar_Ch1";
            this.hScrollBar_Ch1.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch1.TabIndex = 15;
            this.hScrollBar_Ch1.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch1_Scroll);
            // 
            // hScrollBar_Ch2
            // 
            this.hScrollBar_Ch2.Location = new System.Drawing.Point(52, 145);
            this.hScrollBar_Ch2.Maximum = 264;
            this.hScrollBar_Ch2.Name = "hScrollBar_Ch2";
            this.hScrollBar_Ch2.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch2.TabIndex = 16;
            this.hScrollBar_Ch2.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch2_Scroll);
            // 
            // hScrollBar_Ch3
            // 
            this.hScrollBar_Ch3.Location = new System.Drawing.Point(52, 185);
            this.hScrollBar_Ch3.Maximum = 264;
            this.hScrollBar_Ch3.Name = "hScrollBar_Ch3";
            this.hScrollBar_Ch3.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch3.TabIndex = 17;
            this.hScrollBar_Ch3.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch3_Scroll);
            // 
            // hScrollBar_Ch4
            // 
            this.hScrollBar_Ch4.Location = new System.Drawing.Point(52, 222);
            this.hScrollBar_Ch4.Maximum = 264;
            this.hScrollBar_Ch4.Name = "hScrollBar_Ch4";
            this.hScrollBar_Ch4.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch4.TabIndex = 18;
            this.hScrollBar_Ch4.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch4_Scroll);
            // 
            // hScrollBar_Ch5
            // 
            this.hScrollBar_Ch5.Location = new System.Drawing.Point(52, 261);
            this.hScrollBar_Ch5.Maximum = 264;
            this.hScrollBar_Ch5.Name = "hScrollBar_Ch5";
            this.hScrollBar_Ch5.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch5.TabIndex = 19;
            this.hScrollBar_Ch5.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch5_Scroll);
            // 
            // hScrollBar_Ch6
            // 
            this.hScrollBar_Ch6.Location = new System.Drawing.Point(52, 300);
            this.hScrollBar_Ch6.Maximum = 264;
            this.hScrollBar_Ch6.Name = "hScrollBar_Ch6";
            this.hScrollBar_Ch6.Size = new System.Drawing.Size(270, 17);
            this.hScrollBar_Ch6.TabIndex = 20;
            this.hScrollBar_Ch6.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Ch6_Scroll);
            // 
            // textBox_Ch1
            // 
            this.textBox_Ch1.Location = new System.Drawing.Point(328, 99);
            this.textBox_Ch1.Name = "textBox_Ch1";
            this.textBox_Ch1.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch1.TabIndex = 21;
            this.textBox_Ch1.Text = "0";
            this.textBox_Ch1.TextChanged += new System.EventHandler(this.textBox_Ch1_TextChanged);
            // 
            // textBox_Ch2
            // 
            this.textBox_Ch2.Location = new System.Drawing.Point(328, 145);
            this.textBox_Ch2.Name = "textBox_Ch2";
            this.textBox_Ch2.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch2.TabIndex = 22;
            this.textBox_Ch2.Text = "0";
            this.textBox_Ch2.TextChanged += new System.EventHandler(this.textBox_Ch2_TextChanged);
            // 
            // textBox_Ch3
            // 
            this.textBox_Ch3.Location = new System.Drawing.Point(328, 181);
            this.textBox_Ch3.Name = "textBox_Ch3";
            this.textBox_Ch3.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch3.TabIndex = 23;
            this.textBox_Ch3.Text = "0";
            this.textBox_Ch3.TextChanged += new System.EventHandler(this.textBox_Ch3_TextChanged);
            // 
            // textBox_Ch4
            // 
            this.textBox_Ch4.Location = new System.Drawing.Point(328, 224);
            this.textBox_Ch4.Name = "textBox_Ch4";
            this.textBox_Ch4.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch4.TabIndex = 24;
            this.textBox_Ch4.Text = "0";
            this.textBox_Ch4.TextChanged += new System.EventHandler(this.textBox_Ch4_TextChanged);
            // 
            // textBox_Ch5
            // 
            this.textBox_Ch5.Location = new System.Drawing.Point(328, 266);
            this.textBox_Ch5.Name = "textBox_Ch5";
            this.textBox_Ch5.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch5.TabIndex = 25;
            this.textBox_Ch5.Text = "0";
            this.textBox_Ch5.TextChanged += new System.EventHandler(this.textBox_Ch5_TextChanged);
            // 
            // textBox_Ch6
            // 
            this.textBox_Ch6.Location = new System.Drawing.Point(328, 300);
            this.textBox_Ch6.Name = "textBox_Ch6";
            this.textBox_Ch6.Size = new System.Drawing.Size(50, 21);
            this.textBox_Ch6.TabIndex = 26;
            this.textBox_Ch6.Text = "0";
            this.textBox_Ch6.TextChanged += new System.EventHandler(this.textBox_Ch6_TextChanged);
            // 
            // Btn_WriteInit
            // 
            this.Btn_WriteInit.Location = new System.Drawing.Point(14, 327);
            this.Btn_WriteInit.Name = "Btn_WriteInit";
            this.Btn_WriteInit.Size = new System.Drawing.Size(364, 46);
            this.Btn_WriteInit.TabIndex = 27;
            this.Btn_WriteInit.Text = "초기화";
            this.Btn_WriteInit.UseVisualStyleBackColor = true;
            this.Btn_WriteInit.Click += new System.EventHandler(this.Btn_WriteInit_Click);
            // 
            // Btn_Connect
            // 
            this.Btn_Connect.Location = new System.Drawing.Point(14, 381);
            this.Btn_Connect.Name = "Btn_Connect";
            this.Btn_Connect.Size = new System.Drawing.Size(178, 46);
            this.Btn_Connect.TabIndex = 28;
            this.Btn_Connect.Text = "접속 하기";
            this.Btn_Connect.UseVisualStyleBackColor = true;
            this.Btn_Connect.Click += new System.EventHandler(this.Btn_Connect_Click);
            // 
            // Btn_DisConnect
            // 
            this.Btn_DisConnect.Location = new System.Drawing.Point(200, 381);
            this.Btn_DisConnect.Name = "Btn_DisConnect";
            this.Btn_DisConnect.Size = new System.Drawing.Size(178, 46);
            this.Btn_DisConnect.TabIndex = 29;
            this.Btn_DisConnect.Text = "접속 해제";
            this.Btn_DisConnect.UseVisualStyleBackColor = true;
            this.Btn_DisConnect.Click += new System.EventHandler(this.Btn_DisConnect_Click);
            // 
            // LightCtrl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(390, 439);
            this.Controls.Add(this.Btn_DisConnect);
            this.Controls.Add(this.Btn_Connect);
            this.Controls.Add(this.Btn_WriteInit);
            this.Controls.Add(this.textBox_Ch6);
            this.Controls.Add(this.textBox_Ch5);
            this.Controls.Add(this.textBox_Ch4);
            this.Controls.Add(this.textBox_Ch3);
            this.Controls.Add(this.textBox_Ch2);
            this.Controls.Add(this.textBox_Ch1);
            this.Controls.Add(this.hScrollBar_Ch6);
            this.Controls.Add(this.hScrollBar_Ch5);
            this.Controls.Add(this.hScrollBar_Ch4);
            this.Controls.Add(this.hScrollBar_Ch3);
            this.Controls.Add(this.hScrollBar_Ch2);
            this.Controls.Add(this.hScrollBar_Ch1);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.Btn_OnOFF);
            this.Controls.Add(this.Btn_Save);
            this.Controls.Add(this.Btn_AutoTest);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.AutoTestCount);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.AutoTestSpeed);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.AutoTestChannel);
            this.Name = "LightCtrl";
            this.Text = "LightCtrl";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox AutoTestChannel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox AutoTestSpeed;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox AutoTestCount;
        private System.Windows.Forms.Button Btn_AutoTest;
        private System.Windows.Forms.Button Btn_Save;
        private System.Windows.Forms.Button Btn_OnOFF;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch1;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch2;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch3;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch4;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch5;
        private System.Windows.Forms.HScrollBar hScrollBar_Ch6;
        private System.Windows.Forms.TextBox textBox_Ch1;
        private System.Windows.Forms.TextBox textBox_Ch2;
        private System.Windows.Forms.TextBox textBox_Ch3;
        private System.Windows.Forms.TextBox textBox_Ch4;
        private System.Windows.Forms.TextBox textBox_Ch5;
        private System.Windows.Forms.TextBox textBox_Ch6;
        private System.Windows.Forms.Button Btn_WriteInit;
        private System.Windows.Forms.Button Btn_Connect;
        private System.Windows.Forms.Button Btn_DisConnect;
    }
}

