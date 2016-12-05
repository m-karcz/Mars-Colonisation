#pragma once
#include "Graph.hpp"
#include "Series_executor.hpp"

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
	private: System::Windows::Forms::ListBox^  best_solutions;

	private: System::Windows::Forms::NumericUpDown^  numeric_bases;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::NumericUpDown^  numeric_range;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numeric_temp;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  numeric_alpha;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numeric_slope;
	private: System::Windows::Forms::Label^  label7;


	private: Series_executor^ series_executor;
	private: System::Windows::Forms::Label^  gui_series;
	private: System::Windows::Forms::Label^  gui_iterations;



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
			this->best_solutions = (gcnew System::Windows::Forms::ListBox());
			this->numeric_bases = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numeric_range = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numeric_temp = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numeric_alpha = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numeric_slope = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->gui_series = (gcnew System::Windows::Forms::Label());
			this->gui_iterations = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bases))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_temp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_alpha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_slope))->BeginInit();
			this->SuspendLayout();
			// 
			// run_button
			// 
			this->run_button->Location = System::Drawing::Point(29, 145);
			this->run_button->Name = L"run_button";
			this->run_button->Size = System::Drawing::Size(103, 50);
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
			this->open_map->Location = System::Drawing::Point(29, 60);
			this->open_map->Name = L"open_map";
			this->open_map->Size = System::Drawing::Size(103, 49);
			this->open_map->TabIndex = 2;
			this->open_map->Text = L"Open map";
			this->open_map->UseVisualStyleBackColor = true;
			this->open_map->Click += gcnew System::EventHandler(this, &MainForm::open_map_Click);
			// 
			// best_solutions
			// 
			this->best_solutions->FormattingEnabled = true;
			this->best_solutions->ItemHeight = 16;
			this->best_solutions->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"tu beda", L"wspolrzedne", L"baz" });
			this->best_solutions->Location = System::Drawing::Point(448, 48);
			this->best_solutions->Name = L"best_solutions";
			this->best_solutions->Size = System::Drawing::Size(120, 292);
			this->best_solutions->TabIndex = 3;
			// 
			// numeric_bases
			// 
			this->numeric_bases->Location = System::Drawing::Point(295, 60);
			this->numeric_bases->Name = L"numeric_bases";
			this->numeric_bases->Size = System::Drawing::Size(119, 22);
			this->numeric_bases->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(169, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Number of bases:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(172, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Range:";
			// 
			// numeric_range
			// 
			this->numeric_range->Location = System::Drawing::Point(295, 98);
			this->numeric_range->Name = L"numeric_range";
			this->numeric_range->Size = System::Drawing::Size(119, 22);
			this->numeric_range->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(169, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Temperature:";
			// 
			// numeric_temp
			// 
			this->numeric_temp->Location = System::Drawing::Point(295, 137);
			this->numeric_temp->Name = L"numeric_temp";
			this->numeric_temp->Size = System::Drawing::Size(119, 22);
			this->numeric_temp->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(169, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Alpha:";
			// 
			// numeric_alpha
			// 
			this->numeric_alpha->Location = System::Drawing::Point(295, 178);
			this->numeric_alpha->Name = L"numeric_alpha";
			this->numeric_alpha->Size = System::Drawing::Size(119, 22);
			this->numeric_alpha->TabIndex = 4;
			this->numeric_alpha->Tag = L"d";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 261);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Number of series: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(38, 306);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(140, 17);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Number of iterations:";
			// 
			// numeric_slope
			// 
			this->numeric_slope->Location = System::Drawing::Point(295, 218);
			this->numeric_slope->Name = L"numeric_slope";
			this->numeric_slope->Size = System::Drawing::Size(120, 22);
			this->numeric_slope->TabIndex = 10;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(169, 220);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 17);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Max slope:";
			// 
			// gui_series
			// 
			this->gui_series->AutoSize = true;
			this->gui_series->Location = System::Drawing::Point(197, 260);
			this->gui_series->Name = L"gui_series";
			this->gui_series->Size = System::Drawing::Size(16, 17);
			this->gui_series->TabIndex = 11;
			this->gui_series->Text = L"0";
			// 
			// gui_iterations
			// 
			this->gui_iterations->AutoSize = true;
			this->gui_iterations->Location = System::Drawing::Point(247, 323);
			this->gui_iterations->Name = L"gui_iterations";
			this->gui_iterations->Size = System::Drawing::Size(16, 17);
			this->gui_iterations->TabIndex = 12;
			this->gui_iterations->Text = L"0";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1022, 404);
			this->Controls->Add(this->gui_iterations);
			this->Controls->Add(this->gui_series);
			this->Controls->Add(this->numeric_slope);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numeric_alpha);
			this->Controls->Add(this->numeric_temp);
			this->Controls->Add(this->numeric_range);
			this->Controls->Add(this->numeric_bases);
			this->Controls->Add(this->best_solutions);
			this->Controls->Add(this->open_map);
			this->Controls->Add(this->map);
			this->Controls->Add(this->run_button);
			this->Name = L"MainForm";
			this->Text = L"Mars Colonization";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bases))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_temp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_alpha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_slope))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void run_button_Click(System::Object^  sender, System::EventArgs^  e) {
		series_executor = gcnew Series_executor(this->gui_series, this->gui_iterations, this->best_solutions->Items);
		series_executor->init(100.0, 0.98, 20, 0, 0, 3, map->Image, 30);
		series_executor->next_series();
	}
	private: System::Void open_map_Click(System::Object^  sender, System::EventArgs^  e) {
		open_map_dialog->ShowDialog();
		map->Image = System::Drawing::Image::FromFile(open_map_dialog->FileName);
		Graph map(System::Drawing::Image::FromFile(open_map_dialog->FileName), 10);
	}
	private: System::Void open_map_dialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

	}
};
}
