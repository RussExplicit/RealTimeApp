#pragma once

namespace RealTimeApp {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            // Set up the timer event handler
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
            this->timer1->Start(); // Start the timer
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
               this->SuspendLayout();
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->Location = System::Drawing::Point(216, 110);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(135, 31);
               this->label1->TabIndex = 0;
               this->label1->Text = L"Time here";
               // 
               // timer1
               // 
               this->timer1->Interval = 1000;
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->ClientSize = System::Drawing::Size(646, 261);
               this->Controls->Add(this->label1);
               this->Name = L"MyForm";
               this->Text = L"Real-Time Clock";
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        DateTime now = DateTime::Now;
        this->label1->Text = now.ToString("MM/dd/yyyy hh:mm:ss tt");
    }
    };
}
