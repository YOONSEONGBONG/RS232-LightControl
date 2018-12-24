using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LightCtrl_CSharp_OCX
{

    public partial class LightCtrl : Form
    {

        public LightCtrl()
        {
            InitializeComponent();
        }

        int nLightChannel, nLightEventFlag, nLightOnOff;
        int[] nLightLevel = new int[6];
        bool bOnOff;
        int nConnected_flag;
        int nMaxChannel = 6;
        int portNum = 1;
        String saveFile_Path = Application.StartupPath + @"\SaveFile.dat";

        private void Form1_Load(object sender, EventArgs e)
        {

            this.AutoTestSpeed.SelectedIndex = 0;
            this.AutoTestChannel.SelectedIndex = 0;
            this.AutoTestCount.SelectedIndex = 0;
            /*OCX  함수*/
            nConnected_flag = this.axLightControl_ocx2.PortOpen(portNum);
            CheckConnected();

        }

        private void hScrollBar_Ch1_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 1;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch1.Value;
            this.textBox_Ch1.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch1_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 1;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch1.Text);

            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;
            }
            this.hScrollBar_Ch1.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch1.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);



        }

        private void hScrollBar_Ch2_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 2;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch2.Value;
            this.textBox_Ch2.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch2_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 2;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch2.Text);
            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;

            }
            this.hScrollBar_Ch2.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch2.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void hScrollBar_Ch3_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 3;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch3.Value;
            this.textBox_Ch3.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch3_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 3;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch3.Text);

            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;

            }
            this.hScrollBar_Ch3.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch3.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void hScrollBar_Ch4_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 4;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch4.Value;
            this.textBox_Ch4.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch4_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 4;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch4.Text);

            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;

            }
            this.hScrollBar_Ch4.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch4.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void hScrollBar_Ch5_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 5;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch5.Value;
            this.textBox_Ch5.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch5_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 5;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch5.Text);

            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;

            }
            this.hScrollBar_Ch5.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch5.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void hScrollBar_Ch6_Scroll(object sender, ScrollEventArgs e)
        {
            nLightChannel = 6;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = this.hScrollBar_Ch6.Value;
            this.textBox_Ch6.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void textBox_Ch6_TextChanged(object sender, EventArgs e)
        {
            nLightChannel = 6;
            nLightEventFlag = 0;
            nLightOnOff = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch6.Text);

            if (nLightLevel[nLightChannel - 1] < 0)
            {
                nLightLevel[nLightChannel - 1] = 0;

            }
            else if (nLightLevel[nLightChannel - 1] > 255)
            {
                nLightLevel[nLightChannel - 1] = 255;

            }
            this.hScrollBar_Ch6.Value = nLightLevel[nLightChannel - 1];
            this.textBox_Ch6.Text = nLightLevel[nLightChannel - 1].ToString();

            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

        private void Btn_AutoTest_Click(object sender, EventArgs e)
        {
            int nAutoTestChannel, nAutoTestSpeed, nAutoTestCount, nSleepTime;
            nAutoTestChannel = this.AutoTestChannel.SelectedIndex + 1;
            nAutoTestSpeed = this.AutoTestSpeed.SelectedIndex + 1;
            nAutoTestCount = this.AutoTestCount.SelectedIndex + 1;
            nSleepTime = 0;
            switch (nAutoTestSpeed)
            {
                case 1:
                    nSleepTime = 300;
                    break;
                case 2:
                    nSleepTime = 200;
                    break;
                case 3:
                    nSleepTime = 150;
                    break;
                case 4:
                    nSleepTime = 100;
                    break;
                case 5:
                    nSleepTime = 50;
                    break;
                case 6:
                    nSleepTime = 10;
                    break;

            }
            if (this.Btn_OnOFF.Text.Equals("ON"))
            {
                nLightEventFlag = 0;
                nLightOnOff = 1;

                this.axLightControl_ocx2.LightAutoTest(nAutoTestChannel, nSleepTime, nAutoTestCount);

                this.axLightControl_ocx2.SendLightMessage(nAutoTestChannel, nLightEventFlag, nLightOnOff, nLightLevel[nAutoTestChannel - 1]);

            }
            else
            {
                MessageBox.Show("[ERROR]: 조명 OFF입니다!");
            }

        }

        private void Btn_Save_Click(object sender, EventArgs e)
        {
            nLightEventFlag = 1;
            if (bOnOff == true)
            {
                nLightOnOff = 1;
            }
            else
            {
                nLightOnOff = 0;
            }

            nLightChannel = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch1.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 2;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch2.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 3;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch3.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 4;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch4.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 5;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch5.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 6;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch6.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            SaveFile();
        }

        private void Btn_OnOFF_Click(object sender, EventArgs e)
        {

            CheckOnOff(bOnOff);

        }

        private void Btn_Connect_Click(object sender, EventArgs e)
        {
            nConnected_flag = this.axLightControl_ocx2.PortOpen(portNum);
            CheckConnected();
        }
        private void Btn_DisConnect_Click(object sender, EventArgs e)
        {
            if (nConnected_flag == 1)
            {
                nLightOnOff = 0;

                for (int nCnt = 0; nCnt < nMaxChannel; nCnt++)
                {
                    nLightEventFlag = 0;
                    nLightChannel = nCnt + 1;
                    nLightLevel[nCnt] = 0;
                    this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nCnt]);


                    nLightEventFlag = 2;
                    this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nCnt]);

                }
                this.axLightControl_ocx2.PortClose();
                nConnected_flag = 0;
            }
            CheckConnected();

        }

        private void Btn_WriteInit_Click(object sender, EventArgs e)
        {
            this.hScrollBar_Ch1.Value = 0;
            this.textBox_Ch1.Text = 0.ToString();
            this.hScrollBar_Ch2.Value = 0;
            this.textBox_Ch2.Text = 0.ToString();
            this.hScrollBar_Ch3.Value = 0;
            this.textBox_Ch3.Text = 0.ToString();
            this.hScrollBar_Ch4.Value = 0;
            this.textBox_Ch4.Text = 0.ToString();
            this.hScrollBar_Ch5.Value = 0;
            this.textBox_Ch5.Text = 0.ToString();
            this.hScrollBar_Ch6.Value = 0;
            this.textBox_Ch6.Text = 0.ToString();
            this.AutoTestChannel.SelectedIndex = 0;
            this.AutoTestSpeed.SelectedIndex = 0;
            this.AutoTestCount.SelectedIndex = 0;
            nLightEventFlag = 0;
            nLightOnOff = 1;

            for (int nCnt = 0; nCnt < nMaxChannel; nCnt++)
            {

                nLightChannel = nCnt + 1;
                nLightLevel[nCnt] = 0;
                this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nCnt]);
            }
            SaveFile();

        }

        private void SaveFile()
        {
            List<string> list = new List<string>();
            for (int nCnt = 0; nCnt < nMaxChannel; nCnt++)
            {

                list.Add("Ch" + (nCnt + 1).ToString() + " = " + nLightLevel[nCnt].ToString());

            }
            try
            {
                if (System.IO.File.Exists(saveFile_Path))
                {
                    System.IO.File.WriteAllLines(saveFile_Path, list.ToArray());
                }
                else
                {
                    System.IO.File.Create(saveFile_Path);
                    System.IO.File.WriteAllLines(saveFile_Path, list.ToArray());
                }
            }
            catch (System.Exception ex)
            {
                Console.WriteLine(ex.Message.ToString());
            }

        }

        private void LoadFile()
        {
            string line;
            int nCount = 0;
            if (System.IO.File.Exists(saveFile_Path))
            {
                System.IO.StreamReader file = new System.IO.StreamReader(saveFile_Path);
                while ((line = file.ReadLine()) != null)
                {
                    String tmp = line.Substring(line.IndexOf('=') + 1);
                    nLightLevel[nCount] = Convert.ToInt32(tmp);
                    nCount++;
                }

                this.hScrollBar_Ch1.Value = nLightLevel[0];
                this.textBox_Ch1.Text = nLightLevel[0].ToString();
                this.hScrollBar_Ch2.Value = nLightLevel[1];
                this.textBox_Ch2.Text = nLightLevel[1].ToString();
                this.hScrollBar_Ch3.Value = nLightLevel[2];
                this.textBox_Ch3.Text = nLightLevel[2].ToString();
                this.hScrollBar_Ch4.Value = nLightLevel[3];
                this.textBox_Ch4.Text = nLightLevel[3].ToString();
                this.hScrollBar_Ch5.Value = nLightLevel[4];
                this.textBox_Ch5.Text = nLightLevel[4].ToString();
                this.hScrollBar_Ch6.Value = nLightLevel[5];
                this.textBox_Ch6.Text = nLightLevel[5].ToString();
                file.Close();
            }
            else
            {
                for (int nCnt = 0; nCnt < nMaxChannel; nCnt++)
                {
                    nLightLevel[nCnt] = 0;
                }

            }
        }

        private void CheckConnected()
        {
            if (nConnected_flag == 1)
            {


                this.AutoTestChannel.Enabled = true;
                this.AutoTestSpeed.Enabled = true;
                this.AutoTestCount.Enabled = true;
                this.Btn_AutoTest.Enabled = true;
                this.Btn_Save.Enabled = true;
                this.Btn_OnOFF.Enabled = true;
                this.Btn_WriteInit.Enabled = true;
                this.Btn_DisConnect.Enabled = true;
                this.Btn_Connect.Enabled = false;

                LoadFile();
                bOnOff = true;

            }
            else
            {
                this.AutoTestChannel.Enabled = false;
                this.AutoTestSpeed.Enabled = false;
                this.AutoTestCount.Enabled = false;
                this.Btn_AutoTest.Enabled = false;
                this.Btn_Save.Enabled = false;
                this.Btn_OnOFF.Enabled = false;
                this.Btn_WriteInit.Enabled = false;
                this.Btn_DisConnect.Enabled = false;
                this.Btn_Connect.Enabled = true;

                bOnOff = false;

            }

            CheckOnOff(bOnOff);

        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (nConnected_flag == 1)
            {
                nLightOnOff = 0;

                for (int nCnt = 0; nCnt < nMaxChannel; nCnt++)
                {
                    nLightEventFlag = 0;
                    nLightChannel = nCnt + 1;
                    nLightLevel[nCnt] = 0;
                    this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nCnt]);

                    nLightEventFlag = 2;
                    this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nCnt]);
                }
                this.axLightControl_ocx2.PortClose();

                nConnected_flag = 0;
            }
            CheckConnected();

            e.Cancel = false;
            System.Diagnostics.Process.GetCurrentProcess().Kill();


        }

        private void CheckOnOff(bool OnOff)
        {

            if (OnOff == true)
            {
                this.Btn_OnOFF.Text = "ON";
                nLightOnOff = 1;
                bOnOff = false;

                this.hScrollBar_Ch1.Enabled = true;
                this.hScrollBar_Ch2.Enabled = true;
                this.hScrollBar_Ch3.Enabled = true;
                this.hScrollBar_Ch4.Enabled = true;
                this.hScrollBar_Ch5.Enabled = true;
                this.hScrollBar_Ch6.Enabled = true;
                this.textBox_Ch1.Enabled = true;
                this.textBox_Ch2.Enabled = true;
                this.textBox_Ch3.Enabled = true;
                this.textBox_Ch4.Enabled = true;
                this.textBox_Ch5.Enabled = true;
                this.textBox_Ch6.Enabled = true;
            }
            else
            {
                this.Btn_OnOFF.Text = "OFF";
                nLightOnOff = 0;
                bOnOff = true;

                this.hScrollBar_Ch1.Enabled = false;
                this.hScrollBar_Ch2.Enabled = false;
                this.hScrollBar_Ch3.Enabled = false;
                this.hScrollBar_Ch4.Enabled = false;
                this.hScrollBar_Ch5.Enabled = false;
                this.hScrollBar_Ch6.Enabled = false;
                this.textBox_Ch1.Enabled = false;
                this.textBox_Ch2.Enabled = false;
                this.textBox_Ch3.Enabled = false;
                this.textBox_Ch4.Enabled = false;
                this.textBox_Ch5.Enabled = false;
                this.textBox_Ch6.Enabled = false;

            }
            nLightEventFlag = 2;

            nLightChannel = 1;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch1.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);


            nLightChannel = 2;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch2.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);


            nLightChannel = 3;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch3.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);


            nLightChannel = 4;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch4.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);


            nLightChannel = 5;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch5.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

            nLightChannel = 6;
            nLightLevel[nLightChannel - 1] = Convert.ToInt32(this.textBox_Ch6.Text);
            this.axLightControl_ocx2.SendLightMessage(nLightChannel, nLightEventFlag, nLightOnOff, nLightLevel[nLightChannel - 1]);

        }

    }
}
