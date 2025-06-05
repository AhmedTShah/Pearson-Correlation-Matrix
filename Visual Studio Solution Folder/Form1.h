#pragma once
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstdlib>

namespace CppCLRWinFormsProject {
    using namespace std;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public
    ref class Form1 : public System::Windows::Forms::Form {
    public:
        String^ filepath;

        double** data;

        double** matrix;
        int matrixdimension;

        int row;

        bool browsed;
        bool calculated;
        int col;



    private:
        System::Windows::Forms::Button^ button2;

    private:
        System::Windows::Forms::Button^ button3;

    private:
        System::Windows::Forms::Button^ button4;

    private:
        System::Windows::Forms::Button^ button5;

    private:
        System::Windows::Forms::PictureBox^ pictureBox1;

    private:
        System::Windows::Forms::Button^ button6;

    private:
        System::Windows::Forms::RichTextBox^ label1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Label^ label2;

    public:
        

        String^ extractfilename(String^ a)
        {
            String^ result = "";

            for (int i = a->LastIndexOf('\\') + 1; i < a->Length; i++)
            {
                result += a[i];
            }
            return result;
        }

        String^ extractfurther(String^ a)
        {
            String^ result = "";
            for (int i = 0; i < a->LastIndexOf('.'); i++)
            {
                result += a[i];
            }
            return result;
        }

        void addinputdata() {

            const wchar_t* wstr =
                (const wchar_t
                    *)(System::Runtime::InteropServices::Marshal::StringToHGlobalUni(
                        filepath))
                .ToPointer();
            wstring wideString(wstr);
            System::Runtime::InteropServices::Marshal::FreeHGlobal(
                IntPtr((void*)wstr));
            string normalFile(wideString.begin(), wideString.end());

            ifstream f1(normalFile);

            int row1;
            int col1;

            f1 >> row1 >> col1;

            row = row1;
            col = col1;

            data = new double* [row];
            for (int i = 0; i < row; i++) {
                data[i] = new double[col];
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    f1 >> data[i][j];
                }
            }
        }

        Form1(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here

            //
            browsed = false;
            calculated = false;
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1() {
            if (components) {
                delete components;
            }


        }

    private:
        System::Windows::Forms::OpenFileDialog^ openFileDialog1;

    protected:
    private:
        System::Windows::Forms::Button^ browsebutton;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->browsebutton = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::RichTextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // openFileDialog1
            // 
            this->openFileDialog1->FileName = L"openFileDialog1";
            // 
            // browsebutton
            // 
            this->browsebutton->Location = System::Drawing::Point(12, 939);
            this->browsebutton->Name = L"browsebutton";
            this->browsebutton->Size = System::Drawing::Size(134, 23);
            this->browsebutton->TabIndex = 0;
            this->browsebutton->Text = L"Browse File";
            this->browsebutton->UseVisualStyleBackColor = true;
            this->browsebutton->Click += gcnew System::EventHandler(this, &Form1::browsebutton_Click);
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(965, 830);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(102, 23);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Display Data";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(265, 978);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(191, 23);
            this->button3->TabIndex = 4;
            this->button3->Text = L"Calculate Correlation Matrix";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(1666, 830);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(134, 23);
            this->button4->TabIndex = 5;
            this->button4->Text = L"Display Matrix";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(265, 915);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(191, 23);
            this->button5->TabIndex = 6;
            this->button5->Text = L"Discretize";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(196, 173);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(216, 150);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 7;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
            // 
            // button6
            // 
            this->button6->Location = System::Drawing::Point(525, 978);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(125, 23);
            this->button6->TabIndex = 8;
            this->button6->Text = L"Create Bitmap";
            this->button6->UseVisualStyleBackColor = true;
            this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
            // 
            // label1
            // 
            this->label1->BackColor = System::Drawing::SystemColors::Control;
            this->label1->Location = System::Drawing::Point(965, 12);
            this->label1->Name = L"label1";
            this->label1->ReadOnly = true;
            this->label1->Size = System::Drawing::Size(776, 741);
            this->label1->TabIndex = 9;
            this->label1->Text = L"";
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(525, 915);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(125, 23);
            this->button1->TabIndex = 10;
            this->button1->Text = L"Colorize";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // button7
            // 
            this->button7->Location = System::Drawing::Point(12, 192);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(84, 23);
            this->button7->TabIndex = 11;
            this->button7->Text = L"Zoom In";
            this->button7->UseVisualStyleBackColor = true;
            this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
            // 
            // button8
            // 
            this->button8->Location = System::Drawing::Point(12, 277);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(84, 23);
            this->button8->TabIndex = 12;
            this->button8->Text = L"Zoom Out";
            this->button8->UseVisualStyleBackColor = true;
            this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
            // 
            // button9
            // 
            this->button9->Location = System::Drawing::Point(164, 66);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(137, 23);
            this->button9->TabIndex = 13;
            this->button9->Text = L"Shuffle Data Rows";
            this->button9->UseVisualStyleBackColor = true;
            this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
            // 
            // button10
            // 
            this->button10->Location = System::Drawing::Point(351, 66);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(88, 23);
            this->button10->TabIndex = 14;
            this->button10->Text = L"Sort Data";
            this->button10->UseVisualStyleBackColor = true;
            this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(52, 837);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(0, 16);
            this->label2->TabIndex = 15;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1812, 1045);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button10);
            this->Controls->Add(this->button9);
            this->Controls->Add(this->button8);
            this->Controls->Add(this->button7);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->browsebutton);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->label1);
            this->Name = L"Form1";
            this->Text = L"big data\?";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        System::Void browsebutton_Click(System::Object^ sender,
            System::EventArgs^ e) {


            openFileDialog1->ShowDialog();
            filepath = openFileDialog1->FileName;
            addinputdata();
            MessageBox::Show("File loaded successfully");

            browsed = true;

            label2->Text = "File Loaded : " + extractfurther(extractfilename(filepath));

        }

    private:
        System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

            if (browsed)
            {
                if (row > 25 || col > 25) {
                    MessageBox::Show(
                        "This file is too big and displaying it may affect cpu performance");
                }

                else {
                    for (int i = 0; i < row; i++) {
                        for (int j = 0; j < col; j++) {
                            label1->Text +=
                                data[i][j].ToString() + "                                   ";
                        }
                        label1->Text += "\n";
                    }
                }

            }

            else MessageBox::Show("Please browse a file first");
        }

    private:
        System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {


            int n = col;

            double sumx = 0.0;
            double sumy = 0.0;
            double sumxy = 0.0;
            double sumxsquare = 0.0;
            double sumysquare = 0.0;

            matrixdimension = row;
            matrix = new double* [matrixdimension];
            if (browsed) {
                for (int i = 0; i < matrixdimension; i++) {
                    matrix[i] = new double[row];
                }

                double coefficient = 0.0;

                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < row; j++) {
                        sumx = 0.0;
                        sumy = 0.0;
                        sumxy = 0.0;
                        sumxsquare = 0.0;
                        sumysquare = 0.0;

                        for (int k = 0; k < col; k++) {
                            sumx += data[i][k];
                            sumy += data[j][k];
                            sumxy += data[i][k] * data[j][k];
                            sumxsquare += pow(data[i][k], 2);
                            sumysquare += pow(data[j][k], 2);
                        }

                        double numerator = (n * sumxy) - (sumx * sumy);
                        double denominator = sqrt((n * sumxsquare - pow(sumx, 2)) *
                            (n * sumysquare - pow(sumy, 2)));
                        coefficient = numerator / denominator;

                        matrix[i][j] = coefficient;
                    }


                }

            }
            else MessageBox::Show("Please browse a file first");

            calculated = true;
      
        }



    private:
        System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
            if (browsed) {
                if (calculated) {
                    if (matrixdimension < 25) {
                        label1->Text = "";
                        for (int i = 0; i < matrixdimension; i++) {
                            for (int j = 0; j < matrixdimension; j++) {
                                label1->Text += matrix[i][j] + "                          ";
                            }
                            label1->Text += "\n";
                        }
                    }
                    else {
                        MessageBox::Show("Matrix exceeds the limits set for displaying");
                    }
                }
                else {
                    MessageBox::Show("Calculate Corelation Matrix First");
                }
            }
            else {
                MessageBox::Show("Please browse a file first");
            }
        }


    private:
        System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

            double mean;
            if (browsed) {
                if (calculated) {
                    for (int i = 0; i < matrixdimension; i++) {
                        mean = 0.0;
                        for (int j = 0; j < matrixdimension; j++) {
                            mean += matrix[j][i];
                        }
                        mean = mean / matrixdimension;

                        for (int k = 0; k < matrixdimension; k++) {
                            if (matrix[k][i] > mean) {
                                matrix[k][i] = 1;
                            }
                            else {
                                matrix[k][i] = 0;
                            }
                        }
                    }
                }
                else {
                    MessageBox::Show("Calculate Corelation Matrix First");
                }
            }
            else MessageBox::Show("Please browse a file first");
           
        }

    private:
        System::Void pictureBox1_Click(System::Object^ sender,
            System::EventArgs^ e) {}

    private:
        System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {

            Bitmap^ matrixmap = gcnew Bitmap(row, row);

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < row; j++) {
                    if (matrix[i][j] == 1) {
                        matrixmap->SetPixel(i, j, Color::Black);
                        pictureBox1->Image = matrixmap;
                    }
                    else {
                        matrixmap->SetPixel(i, j, Color::White);
                        pictureBox1->Image = matrixmap;
                    }
                }
            }
        }



    private:
        System::Void label1_TextChanged(System::Object^ sender,
            System::EventArgs^ e) {}
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (browsed) {
            if (calculated) {
               

                    Bitmap^ colored = gcnew Bitmap(row, row);

                    for (int i = 0; i < matrixdimension; i++) {
                       
                        double maxVal = matrix[0][i];
                        for (int j = 1; j < matrixdimension; j++) {
                            if (matrix[j][i] > maxVal) {
                                maxVal = matrix[j][i];
                            }
                        }

                       
                        for (int j = 0; j < matrixdimension; j++) {
                            int intensity = static_cast<int>((matrix[j][i] / maxVal) * 255);
                            Color color = Color::FromArgb(255, 0, intensity, 0);
                            colored->SetPixel(i, j, color);
                        }
                    }

                    
                    pictureBox1->Image = colored;
               
            }
            else {
                MessageBox::Show("Calculate Corelation Matrix First");
            }
        }
        else {
            MessageBox::Show("Please browse a file first");
        }
    }
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
        pictureBox1->Height *= 1.25;
        pictureBox1->Width *= 1.25;
    }
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

        pictureBox1->Height *= 0.8;
        pictureBox1->Width *= 0.8;
    }
    private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {

        srand(69);

        int x;

        //double tempmatrix[matrixdimension][matrixdimension];

        for (int i = 0; i < row; i++)
        {
            x = rand() % row;
            for (int j = 0; j < col; j++)
            {
                double temp = data[i][j];
                data[i][j] = data[x][j];
                data[x][j] = temp;
            }
        }
    }
    private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {

        double* signaturemtrx = new double[row];

        for (int i = 0; i < row; i++)
        {
            double sum = 0.0;
            double signature = 0.0;

            for (int j = 0; j < col; j++)
            {
                sum += data[i][j];
            }

            signature = sum / col;
            signature = signature * sum;
            signaturemtrx[i] = signature;


        }



        for (int i = 0; i < row ; i++)


            for (int j = i+1; j < row; j++)
                if (signaturemtrx[j] > signaturemtrx[i])
                {
                    swap(signaturemtrx[j], signaturemtrx[i]);

                    for (int k = 0; k < col; k++)
                    {
                        swap(data[j][k], data[i][k]);
                    }

                }


        delete[] signaturemtrx;
    }
    };
} 