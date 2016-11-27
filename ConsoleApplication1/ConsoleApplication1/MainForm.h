#pragma once

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  run_button;
	private: System::Windows::Forms::PictureBox^  map;
	private: System::Windows::Forms::OpenFileDialog^  open_map_dialog;

	private: System::Windows::Forms::Button^  open_map;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->run_button = (gcnew System::Windows::Forms::Button());
			this->map = (gcnew System::Windows::Forms::PictureBox());
			this->open_map_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->open_map = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->BeginInit();
			this->SuspendLayout();
			// 
			// run_button
			// 
			this->run_button->Location = System::Drawing::Point(171, 351);
			this->run_button->Name = L"run_button";
			this->run_button->Size = System::Drawing::Size(75, 23);
			this->run_button->TabIndex = 0;
			this->run_button->Text = L"Run";
			this->run_button->UseVisualStyleBackColor = true;
			this->run_button->Click += gcnew System::EventHandler(this, &MainForm::run_button_Click);
			// 
			// map
			// 
			this->map->Location = System::Drawing::Point(574, 48);
			this->map->Name = L"map";
			this->map->Size = System::Drawing::Size(400, 300);
			this->map->TabIndex = 1;
			this->map->TabStop = false;
			// 
			// open_map_dialog
			// 
			this->open_map_dialog->FileName = L"open_map_dialog";
			// 
			// open_map
			// 
			this->open_map->Location = System::Drawing::Point(297, 89);
			this->open_map->Name = L"open_map";
			this->open_map->Size = System::Drawing::Size(86, 23);
			this->open_map->TabIndex = 2;
			this->open_map->Text = L"Open map";
			this->open_map->UseVisualStyleBackColor = true;
			this->open_map->Click += gcnew System::EventHandler(this, &MainForm::open_map_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1022, 404);
			this->Controls->Add(this->open_map);
			this->Controls->Add(this->map);
			this->Controls->Add(this->run_button);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void run_button_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void open_map_Click(System::Object^  sender, System::EventArgs^  e) {
		open_map_dialog->ShowDialog();
		map->Image = System::Drawing::Image::FromFile(open_map_dialog->FileName);
	}
	private: System::Void open_map_dialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

	}
};
}
