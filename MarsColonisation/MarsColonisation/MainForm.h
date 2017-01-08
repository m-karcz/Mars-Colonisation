#pragma once
#include "Graph.hpp"
#include "Series_executor.hpp"
#include <list>
#include <cmath>
#include <string>
#include "XY_CLR.h"
#include <msclr/marshal_cppstd.h>

namespace MarsColonisation {

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
		MainForm()
		{
			InitializeComponent();
			InitializeBrushes();
			std::cout << "stworzy³em" << std::endl;
		}
		MainForm(array<System::String^>^ args)
		{
			InitializeComponent();
			InitializeBrushes();
#ifdef AUTOMATE_IT
			this->args = args;
			this->Shown += gcnew System::EventHandler(this, &MarsColonisation::MainForm::OnShown);
#endif
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


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numeric_slope;
	private: System::Windows::Forms::Label^  label7;


	private: Series_executor^ series_executor;
	private: System::Windows::Forms::Label^  gui_series;
	private: System::Windows::Forms::Label^  gui_iterations;

	private: delegate System::Void test2(System::Windows::Forms::Label^ text);
	private: bool is_run = false;
	private: System::Windows::Forms::NumericUpDown^  numeric_alpha;

	private: System::Drawing::Brush^ base_brush;
	private: System::Drawing::Brush^ range_brush;

	private: System::Drawing::Image^ map_original;

	private: System::Drawing::Image^ map_cpy;

	private: System::Drawing::Graphics^ board_to_draw;

	private: System::Int32 init_x;
	private: System::Int32 init_y;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::PageSetupDialog^  pageSetupDialog1;
	private: System::Windows::Forms::Label^  gui_total_range;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  auto_btn;
	private: System::DirectoryServices::DirectoryEntry^  directoryEntry1;

	private: array<System::String^>^ args;
	private: System::String^ output_filename;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numeric_slope = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->gui_series = (gcnew System::Windows::Forms::Label());
			this->gui_iterations = (gcnew System::Windows::Forms::Label());
			this->numeric_alpha = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pageSetupDialog1 = (gcnew System::Windows::Forms::PageSetupDialog());
			this->gui_total_range = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->auto_btn = (gcnew System::Windows::Forms::Button());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bases))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_temp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_slope))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_alpha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// run_button
			// 
			this->run_button->Enabled = false;
			this->run_button->Location = System::Drawing::Point(45, 168);
			this->run_button->Margin = System::Windows::Forms::Padding(2);
			this->run_button->Name = L"run_button";
			this->run_button->Size = System::Drawing::Size(77, 41);
			this->run_button->TabIndex = 0;
			this->run_button->Text = L"Run";
			this->run_button->UseVisualStyleBackColor = true;
			this->run_button->Click += gcnew System::EventHandler(this, &MainForm::run_button_Click);
			// 
			// map
			// 
			this->map->BackColor = System::Drawing::Color::Transparent;
			this->map->Location = System::Drawing::Point(545, 32);
			this->map->Margin = System::Windows::Forms::Padding(2);
			this->map->Name = L"map";
			this->map->Size = System::Drawing::Size(300, 244);
			this->map->TabIndex = 1;
			this->map->TabStop = false;
			// 
			// open_map_dialog
			// 
			this->open_map_dialog->Filter = L"Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif;"
				L" *.png";
			// 
			// open_map
			// 
			this->open_map->Location = System::Drawing::Point(45, 46);
			this->open_map->Margin = System::Windows::Forms::Padding(2);
			this->open_map->Name = L"open_map";
			this->open_map->Size = System::Drawing::Size(77, 40);
			this->open_map->TabIndex = 2;
			this->open_map->Text = L"Open map";
			this->open_map->UseVisualStyleBackColor = true;
			this->open_map->Click += gcnew System::EventHandler(this, &MainForm::open_map_Click);
			// 
			// best_solutions
			// 
			this->best_solutions->BackColor = System::Drawing::Color::White;
			this->best_solutions->FormattingEnabled = true;
			this->best_solutions->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"0, 0" });
			this->best_solutions->Location = System::Drawing::Point(451, 32);
			this->best_solutions->Margin = System::Windows::Forms::Padding(2);
			this->best_solutions->Name = L"best_solutions";
			this->best_solutions->Size = System::Drawing::Size(91, 238);
			this->best_solutions->TabIndex = 3;
			// 
			// numeric_bases
			// 
			this->numeric_bases->Location = System::Drawing::Point(244, 46);
			this->numeric_bases->Margin = System::Windows::Forms::Padding(2);
			this->numeric_bases->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->numeric_bases->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numeric_bases->Name = L"numeric_bases";
			this->numeric_bases->Size = System::Drawing::Size(89, 20);
			this->numeric_bases->TabIndex = 4;
			this->numeric_bases->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(150, 48);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Number of bases:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(150, 80);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Range:";
			// 
			// numeric_range
			// 
			this->numeric_range->Location = System::Drawing::Point(242, 80);
			this->numeric_range->Margin = System::Windows::Forms::Padding(2);
			this->numeric_range->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numeric_range->Name = L"numeric_range";
			this->numeric_range->Size = System::Drawing::Size(89, 20);
			this->numeric_range->TabIndex = 4;
			this->numeric_range->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 80, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(148, 119);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Temperature:";
			// 
			// numeric_temp
			// 
			this->numeric_temp->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numeric_temp->Location = System::Drawing::Point(242, 119);
			this->numeric_temp->Margin = System::Windows::Forms::Padding(2);
			this->numeric_temp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numeric_temp->Name = L"numeric_temp";
			this->numeric_temp->Size = System::Drawing::Size(89, 20);
			this->numeric_temp->TabIndex = 4;
			this->numeric_temp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(148, 159);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Alpha:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(120, 292);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Number of series: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(120, 323);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Number of iterations:";
			// 
			// numeric_slope
			// 
			this->numeric_slope->Location = System::Drawing::Point(242, 193);
			this->numeric_slope->Margin = System::Windows::Forms::Padding(2);
			this->numeric_slope->Name = L"numeric_slope";
			this->numeric_slope->Size = System::Drawing::Size(90, 20);
			this->numeric_slope->TabIndex = 10;
			this->numeric_slope->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(148, 195);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Max slope:";
			// 
			// gui_series
			// 
			this->gui_series->AutoSize = true;
			this->gui_series->Location = System::Drawing::Point(262, 292);
			this->gui_series->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->gui_series->Name = L"gui_series";
			this->gui_series->Size = System::Drawing::Size(13, 13);
			this->gui_series->TabIndex = 11;
			this->gui_series->Text = L"0";
			// 
			// gui_iterations
			// 
			this->gui_iterations->AutoSize = true;
			this->gui_iterations->Location = System::Drawing::Point(262, 323);
			this->gui_iterations->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->gui_iterations->Name = L"gui_iterations";
			this->gui_iterations->Size = System::Drawing::Size(13, 13);
			this->gui_iterations->TabIndex = 12;
			this->gui_iterations->Text = L"0";
			// 
			// numeric_alpha
			// 
			this->numeric_alpha->DecimalPlaces = 2;
			this->numeric_alpha->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numeric_alpha->Location = System::Drawing::Point(242, 159);
			this->numeric_alpha->Margin = System::Windows::Forms::Padding(2);
			this->numeric_alpha->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_alpha->Name = L"numeric_alpha";
			this->numeric_alpha->Size = System::Drawing::Size(89, 20);
			this->numeric_alpha->TabIndex = 4;
			this->numeric_alpha->Tag = L"d";
			this->numeric_alpha->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 97, 0, 0, 131072 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(120, 262);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Total range:";
			// 
			// gui_total_range
			// 
			this->gui_total_range->AutoSize = true;
			this->gui_total_range->Location = System::Drawing::Point(262, 262);
			this->gui_total_range->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->gui_total_range->Name = L"gui_total_range";
			this->gui_total_range->Size = System::Drawing::Size(13, 13);
			this->gui_total_range->TabIndex = 11;
			this->gui_total_range->Text = L"0";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(336, 336);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"actual";
			series1->XAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"best";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(509, 271);
			this->chart1->TabIndex = 15;
			this->chart1->Text = L"chart1";
			// 
			// auto_btn
			// 
			this->auto_btn->Location = System::Drawing::Point(45, 104);
			this->auto_btn->Margin = System::Windows::Forms::Padding(2);
			this->auto_btn->Name = L"auto_btn";
			this->auto_btn->Size = System::Drawing::Size(77, 42);
			this->auto_btn->TabIndex = 16;
			this->auto_btn->Text = L"Auto";
			this->auto_btn->UseVisualStyleBackColor = true;
			this->auto_btn->Click += gcnew System::EventHandler(this, &MainForm::auto_btn_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(916, 628);
			this->Controls->Add(this->auto_btn);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->gui_iterations);
			this->Controls->Add(this->gui_total_range);
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
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"Mars Colonization";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->map))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_bases))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_range))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_temp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_slope))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_alpha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void InitializeBrushes(void)
		{
			this->base_brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(255, 0, 0, 0));
			this->range_brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(150, 0, 0, 0));
		}
#pragma endregion
	private: System::Void run_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!is_run)
		{
			int number_of_bases = System::Convert::ToInt32(this->numeric_bases->Value);
			int max_slope = System::Convert::ToInt32(this->numeric_slope->Value);
			double alpha = System::Convert::ToDouble(this->numeric_alpha->Value);
			double temperature = System::Convert::ToDouble(this->numeric_temp->Value);
			int max_range = System::Convert::ToInt32(this->numeric_range->Value);
			series_executor = gcnew Series_executor(this->gui_series, this->gui_iterations, this->best_solutions, this);
			series_executor->init(temperature, alpha, init_x, init_y, number_of_bases, map->Image, max_slope, max_range);
			is_run = true;
			this->numeric_bases->Enabled = false;
			this->numeric_slope->Enabled = false;
			this->numeric_alpha->Enabled = false;
			this->numeric_range->Enabled = false;
			this->numeric_temp->Enabled = false;
			this->auto_btn->Enabled = false;
		}
		series_executor->next_series();
		this->gui_series->Text = (System::Int32::Parse(this->gui_series->Text) + 1).ToString();
	}
	private: System::Void open_map_Click(System::Object^  sender, System::EventArgs^  e) {
		auto result = open_map_dialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK)
		{
			map_original = System::Drawing::Image::FromFile(open_map_dialog->FileName);
			map->Image = (System::Drawing::Image^)(map_original->Clone());
			this->board_to_draw = System::Drawing::Graphics::FromImage(map->Image);
			this->map->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::click_on_image);
			this->init_x = 0;
			this->init_y = 0;
			this->map->Width = this->map->Image->Width;
			this->map->Height = this->map->Image->Height;
			this->run_button->Enabled = true;
			this->open_map->Enabled = false;
		}
	}

	private: System::Void open_map_dialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		System::Console::WriteLine("no tutaj xD");

	}
	public: void SetBestSolution(std::shared_ptr<Solution> solution)
	{
		using namespace System;
		using namespace System::Collections::Generic;
		List<String^>^ bases = gcnew List<String^>();
		for (auto& base : solution->bases)
		{
			bases->Add(base.x.ToString() + ", " + base.y.ToString());
		}
		this->Invoke(gcnew Action<List<String^>^>(this, &MainForm::SetBestSolutionAction), bases);
		this->Invoke(gcnew Action<int>(this, &MainForm::SetBestSoltuionValue), solution->achievable_points);
	}
			void SetBestSolutionAction(System::Collections::Generic::List<System::String^>^ bases)
			{
				this->best_solutions->Items->Clear();
				for (int i = 0; i < bases->Count; i++)
				{
					this->best_solutions->Items->Add(bases[i]);
				}
			}
			void SetBestSoltuionValue(int value)
			{
				this->gui_total_range->Text = value.ToString();
			}
			void SetIterations(int iterations)
			{
				this->Invoke(gcnew Action<int>(this, &MainForm::SetIterationsAction), iterations);
			}
			void SetIterationsAction(int iterations)
			{
				this->gui_iterations->Text = iterations.ToString();
			}
	public: void DrawBestSolution(std::shared_ptr<Solution> solution, std::list<SimplePoint>&& ranges)
	{
		using namespace System::Collections::Generic;
		auto bases = gcnew List<XY^>();
		auto achievables = gcnew List<XY^>();
		for (auto b : solution->bases)
		{
			bases->Add(gcnew XY(b));
		}
		for (auto r : ranges)
		{
			achievables->Add(gcnew XY(r.x, r.y));
		}
		auto args = gcnew List<List<XY^>^>();
		args->Add(bases);
		args->Add(achievables);
		this->Invoke(gcnew Action<List<List<XY^>^>^>(this, &MainForm::DrawBestSolutionsAction), args);
	}
	private: void DrawBestSolutionsAction(System::Collections::Generic::List<System::Collections::Generic::List<XY^>^>^ args)
	{
		auto bases = args[0];
		auto achievables = args[1];
		this->clear_map();
		this->board_to_draw = System::Drawing::Graphics::FromImage(this->map->Image);

		/*for (int i = 0; i < achievables->Count; i++)
		{
			auto a = achievables[i];
			this->board_to_draw->FillRectangle(range_brush, 2 * a->x, 2 * a->y, 2, 2);
		}*/
		for(int x=0; x<map->Image->Width/2; x++)
		{
			for(int y=0; y<map->Image->Height/2; y++)
			{
				bool found = false;
				for(int i=0; i<achievables->Count; i++)
				{
					if(achievables[i]->x == x && achievables[i]->y == y)
					{
						found = true;
						break;
					}
				}
				if(!found)
				{
					this->board_to_draw->FillRectangle(range_brush, 2 * x, 2 * y, 2, 2);
				}
			}
		}
		for (int i = 0; i < bases->Count; i++)
		{
			auto b = bases[i];
			this->board_to_draw->FillRectangle(base_brush, 2 * b->x, 2 * b->y, 2, 2);
		}
		this->map->Image = this->map->Image;
	}
	public: void clear_map()
	{
		this->map->Image = (System::Drawing::Image^)(map_original->Clone());
	}
			void click_on_image(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
			{
				if (!is_run)
				{
					this->init_x = e->Location.X / 2;
					this->init_y = e->Location.Y / 2;
					this->best_solutions->Items->Clear();
					this->best_solutions->Items->Add(this->init_x.ToString() + ", " + this->init_y.ToString());
				}
			}
			void SetRun(bool val)
			{
				this->Invoke(gcnew Action<bool>(this, &MainForm::SetRunAction), val);
			}

			void SetRunAction(bool val)
			{
				this->run_button->Enabled = val;
			}

	public: void PlotObjectiveFunction(int actual, int best)
	{

		this->Invoke(gcnew Action<int>(this, &MainForm::PlotActualAction), actual);
		this->Invoke(gcnew Action<int>(this, &MainForm::PlotBestAction), best);
	}
	private: void PlotActualAction(int value)
	{
		this->chart1->Series["actual"]->Points->AddY(value);
	}
	private: void PlotBestAction(int value)
	{
		this->chart1->Series["best"]->Points->AddY(value);
	}
	public: void IncrementSeries(void)
	{
		this->Invoke(gcnew Action(this, &MainForm::IncrementSeriesAction));
	}
	private: void IncrementSeriesAction()
	{
		this->gui_series->Text = (System::Int32::Parse(this->gui_series->Text) + 1).ToString();
	}
	public: void ShowTempAndAlpha(double temp, double alpha)
	{
		this->Invoke(gcnew Action<double>(this, &MainForm::ShowTempAction), temp);
		this->Invoke(gcnew Action<double>(this, &MainForm::ShowAlphaAction), alpha);
	}
	private: void ShowTempAction(double temp)
	{
		this->numeric_temp->Value = System::Convert::ToDecimal(temp);
	}
	private: void ShowAlphaAction(double alpha)
	{
		this->numeric_alpha->Value = System::Convert::ToDecimal(alpha);
	}
#ifdef AUTOMATE_IT
	public: void CloseForAutomation()
	{
		this->Invoke(gcnew Action(this, &MainForm::CloseForAutomationAction));
	}
	private: void CloseForAutomationAction()
	{
		SaveOutput();
		this->Close();
	}
	public: bool AutomaticStart()
	{
		if (args->Length != 7)
		{
			std::cout << "zle dane, powinien byæ format: X Y ilosc_baz max_zasieg max_nachylenie sciezka_do_img nazwa_outputu" << std::endl;
			return false;
		}
		if (this->numeric_bases == nullptr)
		{
			std::cout << "WTF" << std::endl;
			return false;
		}
		if (System::Int32::TryParse(args[0], this->init_x) && System::Int32::TryParse(args[1], this->init_y) && System::Decimal::TryParse(args[2], this->numeric_bases->Value) && System::Decimal::TryParse(args[3], this->numeric_range->Value) && System::Decimal::TryParse(args[4], this->numeric_slope->Value))
		{
			this->numeric_bases->Value = System::Decimal::Parse(args[2]);
			this->numeric_range->Value = System::Decimal::Parse(args[3]);
			this->numeric_slope->Value = System::Decimal::Parse(args[4]);
			map_original = System::Drawing::Image::FromFile(args[5]);
			map->Image = (System::Drawing::Image^)map_original->Clone();
			set_auto_temp_and_alpha();
			this->map->Width = this->map->Image->Width;
			this->map->Height = this->map->Image->Height;
			this->best_solutions->Items->Clear();
			this->best_solutions->Items->Add(this->init_x.ToString() + ", " + this->init_y.ToString());
			int number_of_bases = System::Convert::ToInt32(this->numeric_bases->Value);
			int max_slope = System::Convert::ToInt32(this->numeric_slope->Value);
			double alpha = System::Convert::ToDouble(this->numeric_alpha->Value);
			double temperature = System::Convert::ToDouble(this->numeric_temp->Value);
			int max_range = System::Convert::ToInt32(this->numeric_range->Value);
			series_executor = gcnew Series_executor(this->gui_series, this->gui_iterations, this->best_solutions, this);
			output_filename = args[6];
			//series_executor->sa->set_output_filename(msclr::interop::marshal_as<std::string>(output_filename));
			//series_executor->sa->set_output_filename(CppStrFromNet(output_filename));
			series_executor->init(temperature, alpha, init_x, init_y, number_of_bases, map->Image, max_slope, max_range, CppStrFromNet(output_filename));
			series_executor->next_series();
		}

		return true;
	}
	private: std::string CppStrFromNet(System::String^ str)
	{
		std::string output_str = "";
		interior_ptr<const Char> ppchar = PtrToStringChars(str);
		for (; *ppchar != '\0'; ppchar++)
			output_str.append(1, char(*ppchar));
		return output_str;
	}
	private: void OnShown(System::Object^ sender, System::EventArgs^ e)
	{
		AutomaticStart();
	}
	private: void SaveOutput()
	{
		System::String^ output = output_filename->Split('.')[0] + ".bmp";
		this->map->Image->Save(output);
	}
#endif

	private: System::Void auto_btn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		set_auto_temp_and_alpha();
	}
	private: System::Void set_auto_temp_and_alpha()
	{
		int range = System::Convert::ToInt32(this->numeric_range->Value);
		int base_quantity = System::Convert::ToInt32(this->numeric_bases->Value);

		int arg = range * base_quantity;
		int auto_temperature = static_cast<int> (0.0016213*pow(arg, 2) - 0.717574*arg + 86.5998);
		int auto_alpha = 93 + base_quantity;

		this->numeric_temp->Value = auto_temperature;
		this->numeric_alpha->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { auto_alpha, 0, 0, 131072 });
	}
	};

}
