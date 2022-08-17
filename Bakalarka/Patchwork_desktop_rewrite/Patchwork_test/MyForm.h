#pragma once

#include "Game_handling.h"
#include "Game.h"

namespace Patchworktest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ set_button;
	protected:

	protected:

	private: System::Windows::Forms::Button^ stats_button;
	private: System::Windows::Forms::Button^ end_game_button;
	private: System::Windows::Forms::Button^ back_to_menu_button;
	private: System::Windows::Forms::Button^ skip_time_knobs_button;
	private: System::Windows::Forms::Button^ start_patching_button;
	private: System::Windows::Forms::Button^ look_at_patches_button;
	private: System::Windows::Forms::Button^ select_fst_patch;
	private: System::Windows::Forms::Button^ select_snd_patch;
	private: System::Windows::Forms::Button^ select_thrd_patch;
	private: System::Windows::Forms::Button^ undo_patch_looking;
	private: System::Windows::Forms::Button^ undo_patching;
	private: System::Windows::Forms::Button^ looking_patches_back;
	private: System::Windows::Forms::Button^ looking_patches_next;
	private: System::Windows::Forms::Label^ player1_blanket;
	private: System::Windows::Forms::Label^ player2_blanket;
	private: System::Windows::Forms::Label^ patching_blanket;
	private: System::Windows::Forms::Label^ game_seeds_list_label;
	private: System::Windows::Forms::Label^ selected_patch_matching;
	private: System::Windows::Forms::Label^ patch1_map;
	private: System::Windows::Forms::Label^ patch2_map;
	private: System::Windows::Forms::Label^ patch3_map;
	private: System::Windows::Forms::Label^ player_turn;
	private: System::Windows::Forms::Label^ additional_info;
	private: System::Windows::Forms::Button^ play_with_seed;
	private: System::Windows::Forms::CheckBox^ player1_ai_choice;
	private: System::Windows::Forms::CheckBox^ player2_ai_choice;
	private: System::Windows::Forms::Button^ start_button;
	private: System::Windows::Forms::RadioButton^ player_1_greedy_no_man;
	private: System::Windows::Forms::RadioButton^ player_2_greedy_no_man;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ player_1_min_max_no_man;
	private: System::Windows::Forms::RadioButton^ player_1_greedy_man;
	private: System::Windows::Forms::RadioButton^ player_2_min_max_no_man;
	private: System::Windows::Forms::RadioButton^ player_2_greedy_man;
	private: System::Windows::Forms::RadioButton^ player_1_min_max_man;
	private: System::Windows::Forms::RadioButton^ player_2_min_max_man;
	private: System::Windows::Forms::RadioButton^ player_1_min_max_free;
	private: System::Windows::Forms::RadioButton^ player_2_min_max_free;
	private: System::Windows::Forms::RadioButton^ player_1_monte_carlo;
	private: System::Windows::Forms::RadioButton^ player_2_monte_carlo;
	private: System::Windows::Forms::RadioButton^ player_1_random_ai;

	private: System::Windows::Forms::RadioButton^ player_2_random_ai;
	private: System::Windows::Forms::RadioButton^ player_1_random_select;
	private: System::Windows::Forms::RadioButton^ player_2_random_select;
	private: System::Windows::Forms::RadioButton^ player_1_frequency_ai;
	private: System::Windows::Forms::RadioButton^ player_2_frequency_ai;
	private: System::Windows::Forms::Button^ simulate_100_games;
	private: System::Windows::Forms::Button^ game_looking_back;
	private: System::Windows::Forms::Button^ game_looking_next;
	private: System::Windows::Forms::Label^ simulation_result;








	protected:
	private:











	protected:

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
		void InitializeComponent(void)
		{
			this->set_button = (gcnew System::Windows::Forms::Button());
			this->end_game_button = (gcnew System::Windows::Forms::Button());
			this->stats_button = (gcnew System::Windows::Forms::Button());
			this->back_to_menu_button = (gcnew System::Windows::Forms::Button());
			this->skip_time_knobs_button = (gcnew System::Windows::Forms::Button());
			this->start_patching_button = (gcnew System::Windows::Forms::Button());
			this->look_at_patches_button = (gcnew System::Windows::Forms::Button());
			this->select_fst_patch = (gcnew System::Windows::Forms::Button());
			this->select_snd_patch = (gcnew System::Windows::Forms::Button());
			this->select_thrd_patch = (gcnew System::Windows::Forms::Button());
			this->undo_patch_looking = (gcnew System::Windows::Forms::Button());
			this->undo_patching = (gcnew System::Windows::Forms::Button());
			this->looking_patches_back = (gcnew System::Windows::Forms::Button());
			this->looking_patches_next = (gcnew System::Windows::Forms::Button());
			this->player1_blanket = (gcnew System::Windows::Forms::Label());
			this->player2_blanket = (gcnew System::Windows::Forms::Label());
			this->patching_blanket = (gcnew System::Windows::Forms::Label());
			this->game_seeds_list_label = (gcnew System::Windows::Forms::Label());
			this->selected_patch_matching = (gcnew System::Windows::Forms::Label());
			this->patch1_map = (gcnew System::Windows::Forms::Label());
			this->patch2_map = (gcnew System::Windows::Forms::Label());
			this->patch3_map = (gcnew System::Windows::Forms::Label());
			this->player_turn = (gcnew System::Windows::Forms::Label());
			this->additional_info = (gcnew System::Windows::Forms::Label());
			this->play_with_seed = (gcnew System::Windows::Forms::Button());
			this->player1_ai_choice = (gcnew System::Windows::Forms::CheckBox());
			this->player2_ai_choice = (gcnew System::Windows::Forms::CheckBox());
			this->start_button = (gcnew System::Windows::Forms::Button());
			this->player_1_greedy_no_man = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_greedy_no_man = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->player_1_frequency_ai = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_random_select = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_random_ai = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_monte_carlo = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_min_max_free = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_min_max_man = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_min_max_no_man = (gcnew System::Windows::Forms::RadioButton());
			this->player_1_greedy_man = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->player_2_frequency_ai = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_random_select = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_random_ai = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_monte_carlo = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_min_max_free = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_min_max_man = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_min_max_no_man = (gcnew System::Windows::Forms::RadioButton());
			this->player_2_greedy_man = (gcnew System::Windows::Forms::RadioButton());
			this->simulate_100_games = (gcnew System::Windows::Forms::Button());
			this->game_looking_back = (gcnew System::Windows::Forms::Button());
			this->game_looking_next = (gcnew System::Windows::Forms::Button());
			this->simulation_result = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// set_button
			// 
			this->set_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->set_button->Location = System::Drawing::Point(414, 46);
			this->set_button->Name = L"set_button";
			this->set_button->Size = System::Drawing::Size(151, 68);
			this->set_button->TabIndex = 0;
			this->set_button->Text = L"Set game";
			this->set_button->UseVisualStyleBackColor = true;
			this->set_button->Click += gcnew System::EventHandler(this, &MyForm::set_button_Click);
			// 
			// end_game_button
			// 
			this->end_game_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->end_game_button->Location = System::Drawing::Point(414, 348);
			this->end_game_button->Name = L"end_game_button";
			this->end_game_button->Size = System::Drawing::Size(151, 73);
			this->end_game_button->TabIndex = 3;
			this->end_game_button->Text = L"End";
			this->end_game_button->UseVisualStyleBackColor = true;
			this->end_game_button->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// stats_button
			// 
			this->stats_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stats_button->Location = System::Drawing::Point(414, 139);
			this->stats_button->Name = L"stats_button";
			this->stats_button->Size = System::Drawing::Size(151, 66);
			this->stats_button->TabIndex = 4;
			this->stats_button->Text = L"Past game stats";
			this->stats_button->UseVisualStyleBackColor = true;
			this->stats_button->Click += gcnew System::EventHandler(this, &MyForm::stats_button_Click);
			// 
			// back_to_menu_button
			// 
			this->back_to_menu_button->Enabled = false;
			this->back_to_menu_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->back_to_menu_button->Location = System::Drawing::Point(13, 405);
			this->back_to_menu_button->Name = L"back_to_menu_button";
			this->back_to_menu_button->Size = System::Drawing::Size(102, 49);
			this->back_to_menu_button->TabIndex = 5;
			this->back_to_menu_button->Text = L"Menu\r\n(M)";
			this->back_to_menu_button->UseVisualStyleBackColor = true;
			this->back_to_menu_button->Visible = false;
			this->back_to_menu_button->Click += gcnew System::EventHandler(this, &MyForm::back_to_menu_button_Click);
			// 
			// skip_time_knobs_button
			// 
			this->skip_time_knobs_button->Enabled = false;
			this->skip_time_knobs_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->skip_time_knobs_button->Location = System::Drawing::Point(736, 405);
			this->skip_time_knobs_button->Name = L"skip_time_knobs_button";
			this->skip_time_knobs_button->Size = System::Drawing::Size(99, 49);
			this->skip_time_knobs_button->TabIndex = 6;
			this->skip_time_knobs_button->Text = L"Skip\r\n (S)";
			this->skip_time_knobs_button->UseVisualStyleBackColor = true;
			this->skip_time_knobs_button->Visible = false;
			this->skip_time_knobs_button->Click += gcnew System::EventHandler(this, &MyForm::skip_time_knobs_button_Click);
			// 
			// start_patching_button
			// 
			this->start_patching_button->Enabled = false;
			this->start_patching_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->start_patching_button->Location = System::Drawing::Point(859, 405);
			this->start_patching_button->Name = L"start_patching_button";
			this->start_patching_button->Size = System::Drawing::Size(93, 49);
			this->start_patching_button->TabIndex = 7;
			this->start_patching_button->Text = L"Patching\r\n(P)";
			this->start_patching_button->UseVisualStyleBackColor = true;
			this->start_patching_button->Visible = false;
			this->start_patching_button->Click += gcnew System::EventHandler(this, &MyForm::start_patching_button_Click);
			// 
			// look_at_patches_button
			// 
			this->look_at_patches_button->Enabled = false;
			this->look_at_patches_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->look_at_patches_button->Location = System::Drawing::Point(612, 405);
			this->look_at_patches_button->Name = L"look_at_patches_button";
			this->look_at_patches_button->Size = System::Drawing::Size(100, 49);
			this->look_at_patches_button->TabIndex = 8;
			this->look_at_patches_button->Text = L"Patches\r\n(L)";
			this->look_at_patches_button->UseVisualStyleBackColor = true;
			this->look_at_patches_button->Visible = false;
			this->look_at_patches_button->Click += gcnew System::EventHandler(this, &MyForm::look_at_patches_button_Click);
			// 
			// select_fst_patch
			// 
			this->select_fst_patch->Enabled = false;
			this->select_fst_patch->Location = System::Drawing::Point(228, 289);
			this->select_fst_patch->Name = L"select_fst_patch";
			this->select_fst_patch->Size = System::Drawing::Size(75, 23);
			this->select_fst_patch->TabIndex = 9;
			this->select_fst_patch->Text = L"select(F1)";
			this->select_fst_patch->UseVisualStyleBackColor = true;
			this->select_fst_patch->Visible = false;
			this->select_fst_patch->Click += gcnew System::EventHandler(this, &MyForm::select_fst_patch_Click);
			// 
			// select_snd_patch
			// 
			this->select_snd_patch->Enabled = false;
			this->select_snd_patch->Location = System::Drawing::Point(447, 289);
			this->select_snd_patch->Name = L"select_snd_patch";
			this->select_snd_patch->Size = System::Drawing::Size(75, 23);
			this->select_snd_patch->TabIndex = 10;
			this->select_snd_patch->Text = L"select(F2)";
			this->select_snd_patch->UseVisualStyleBackColor = true;
			this->select_snd_patch->Visible = false;
			this->select_snd_patch->Click += gcnew System::EventHandler(this, &MyForm::select_snd_patch_Click);
			// 
			// select_thrd_patch
			// 
			this->select_thrd_patch->Enabled = false;
			this->select_thrd_patch->Location = System::Drawing::Point(666, 289);
			this->select_thrd_patch->Name = L"select_thrd_patch";
			this->select_thrd_patch->Size = System::Drawing::Size(75, 23);
			this->select_thrd_patch->TabIndex = 11;
			this->select_thrd_patch->Text = L"select(F3)";
			this->select_thrd_patch->UseVisualStyleBackColor = true;
			this->select_thrd_patch->Visible = false;
			this->select_thrd_patch->Click += gcnew System::EventHandler(this, &MyForm::select_thrd_patch_Click);
			// 
			// undo_patch_looking
			// 
			this->undo_patch_looking->Enabled = false;
			this->undo_patch_looking->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->undo_patch_looking->Location = System::Drawing::Point(145, 405);
			this->undo_patch_looking->Name = L"undo_patch_looking";
			this->undo_patch_looking->Size = System::Drawing::Size(100, 49);
			this->undo_patch_looking->TabIndex = 12;
			this->undo_patch_looking->Text = L"Cancel\r\n(C)";
			this->undo_patch_looking->UseVisualStyleBackColor = true;
			this->undo_patch_looking->Visible = false;
			this->undo_patch_looking->Click += gcnew System::EventHandler(this, &MyForm::undo_patch_looking_Click);
			// 
			// undo_patching
			// 
			this->undo_patching->Enabled = false;
			this->undo_patching->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->undo_patching->Location = System::Drawing::Point(145, 405);
			this->undo_patching->Name = L"undo_patching";
			this->undo_patching->Size = System::Drawing::Size(100, 49);
			this->undo_patching->TabIndex = 13;
			this->undo_patching->Text = L"Undo\r\n(U)";
			this->undo_patching->UseVisualStyleBackColor = true;
			this->undo_patching->Visible = false;
			this->undo_patching->Click += gcnew System::EventHandler(this, &MyForm::undo_patching_Click);
			// 
			// looking_patches_back
			// 
			this->looking_patches_back->Enabled = false;
			this->looking_patches_back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->looking_patches_back->Location = System::Drawing::Point(735, 405);
			this->looking_patches_back->Name = L"looking_patches_back";
			this->looking_patches_back->Size = System::Drawing::Size(100, 49);
			this->looking_patches_back->TabIndex = 14;
			this->looking_patches_back->Text = L"Back\r\n(A)";
			this->looking_patches_back->UseVisualStyleBackColor = true;
			this->looking_patches_back->Visible = false;
			this->looking_patches_back->Click += gcnew System::EventHandler(this, &MyForm::looking_patches_back_Click);
			// 
			// looking_patches_next
			// 
			this->looking_patches_next->Enabled = false;
			this->looking_patches_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->looking_patches_next->Location = System::Drawing::Point(859, 405);
			this->looking_patches_next->Name = L"looking_patches_next";
			this->looking_patches_next->Size = System::Drawing::Size(100, 49);
			this->looking_patches_next->TabIndex = 15;
			this->looking_patches_next->Text = L"Next\r\n(D)";
			this->looking_patches_next->UseVisualStyleBackColor = true;
			this->looking_patches_next->Visible = false;
			this->looking_patches_next->Click += gcnew System::EventHandler(this, &MyForm::looking_patches_next_Click);
			// 
			// player1_blanket
			// 
			this->player1_blanket->AutoSize = true;
			this->player1_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player1_blanket->Location = System::Drawing::Point(141, 103);
			this->player1_blanket->Name = L"player1_blanket";
			this->player1_blanket->Size = System::Drawing::Size(117, 19);
			this->player1_blanket->TabIndex = 16;
			this->player1_blanket->Text = L"player1_data";
			this->player1_blanket->Visible = false;
			// 
			// player2_blanket
			// 
			this->player2_blanket->AutoSize = true;
			this->player2_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player2_blanket->Location = System::Drawing::Point(631, 103);
			this->player2_blanket->Name = L"player2_blanket";
			this->player2_blanket->Size = System::Drawing::Size(117, 19);
			this->player2_blanket->TabIndex = 17;
			this->player2_blanket->Text = L"player2_data";
			this->player2_blanket->Visible = false;
			// 
			// patching_blanket
			// 
			this->patching_blanket->AutoSize = true;
			this->patching_blanket->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->patching_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->patching_blanket->Location = System::Drawing::Point(246, 100);
			this->patching_blanket->Name = L"patching_blanket";
			this->patching_blanket->Size = System::Drawing::Size(181, 28);
			this->patching_blanket->TabIndex = 18;
			this->patching_blanket->Text = L"which blanket";
			this->patching_blanket->Visible = false;
			// 
			// game_seeds_list_label
			// 
			this->game_seeds_list_label->AutoSize = true;
			this->game_seeds_list_label->Enabled = false;
			this->game_seeds_list_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->game_seeds_list_label->Location = System::Drawing::Point(142, 74);
			this->game_seeds_list_label->Name = L"game_seeds_list_label";
			this->game_seeds_list_label->Size = System::Drawing::Size(44, 16);
			this->game_seeds_list_label->TabIndex = 19;
			this->game_seeds_list_label->Text = L"Seed:";
			this->game_seeds_list_label->Visible = false;
			this->game_seeds_list_label->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::game_seeds_list_label_MouseClick);
			// 
			// selected_patch_matching
			// 
			this->selected_patch_matching->AutoSize = true;
			this->selected_patch_matching->BackColor = System::Drawing::Color::Transparent;
			this->selected_patch_matching->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selected_patch_matching->ForeColor = System::Drawing::Color::Red;
			this->selected_patch_matching->Location = System::Drawing::Point(8, 144);
			this->selected_patch_matching->Name = L"selected_patch_matching";
			this->selected_patch_matching->Size = System::Drawing::Size(194, 28);
			this->selected_patch_matching->TabIndex = 20;
			this->selected_patch_matching->Text = L"selected_patch";
			this->selected_patch_matching->Visible = false;
			// 
			// patch1_map
			// 
			this->patch1_map->AutoSize = true;
			this->patch1_map->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->patch1_map->Location = System::Drawing::Point(228, 156);
			this->patch1_map->Name = L"patch1_map";
			this->patch1_map->Size = System::Drawing::Size(67, 13);
			this->patch1_map->TabIndex = 21;
			this->patch1_map->Text = L"patch1_map";
			this->patch1_map->Visible = false;
			// 
			// patch2_map
			// 
			this->patch2_map->AutoSize = true;
			this->patch2_map->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->patch2_map->Location = System::Drawing::Point(447, 155);
			this->patch2_map->Name = L"patch2_map";
			this->patch2_map->Size = System::Drawing::Size(67, 13);
			this->patch2_map->TabIndex = 22;
			this->patch2_map->Text = L"patch2_map";
			this->patch2_map->Visible = false;
			// 
			// patch3_map
			// 
			this->patch3_map->AutoSize = true;
			this->patch3_map->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->patch3_map->Location = System::Drawing::Point(663, 155);
			this->patch3_map->Name = L"patch3_map";
			this->patch3_map->Size = System::Drawing::Size(67, 13);
			this->patch3_map->TabIndex = 23;
			this->patch3_map->Text = L"patch3_map";
			this->patch3_map->Visible = false;
			// 
			// player_turn
			// 
			this->player_turn->AutoSize = true;
			this->player_turn->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player_turn->Location = System::Drawing::Point(356, 16);
			this->player_turn->Name = L"player_turn";
			this->player_turn->Size = System::Drawing::Size(108, 19);
			this->player_turn->TabIndex = 24;
			this->player_turn->Text = L"player turn";
			this->player_turn->Visible = false;
			// 
			// additional_info
			// 
			this->additional_info->AutoSize = true;
			this->additional_info->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->additional_info->Location = System::Drawing::Point(10, 9);
			this->additional_info->Name = L"additional_info";
			this->additional_info->Size = System::Drawing::Size(205, 26);
			this->additional_info->TabIndex = 25;
			this->additional_info->Text = L"Click set game to set up new game\r\nor click  stats to see stats";
			// 
			// play_with_seed
			// 
			this->play_with_seed->Enabled = false;
			this->play_with_seed->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->play_with_seed->Location = System::Drawing::Point(430, 405);
			this->play_with_seed->Name = L"play_with_seed";
			this->play_with_seed->Size = System::Drawing::Size(119, 49);
			this->play_with_seed->TabIndex = 26;
			this->play_with_seed->Text = L"Play with this seed";
			this->play_with_seed->UseVisualStyleBackColor = true;
			this->play_with_seed->Visible = false;
			this->play_with_seed->Click += gcnew System::EventHandler(this, &MyForm::play_with_seed_Click);
			// 
			// player1_ai_choice
			// 
			this->player1_ai_choice->AutoSize = true;
			this->player1_ai_choice->Enabled = false;
			this->player1_ai_choice->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player1_ai_choice->Location = System::Drawing::Point(251, 46);
			this->player1_ai_choice->Name = L"player1_ai_choice";
			this->player1_ai_choice->Size = System::Drawing::Size(118, 23);
			this->player1_ai_choice->TabIndex = 27;
			this->player1_ai_choice->Text = L"Player1 AI";
			this->player1_ai_choice->UseVisualStyleBackColor = true;
			this->player1_ai_choice->Visible = false;
			// 
			// player2_ai_choice
			// 
			this->player2_ai_choice->AutoSize = true;
			this->player2_ai_choice->Enabled = false;
			this->player2_ai_choice->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->player2_ai_choice->Location = System::Drawing::Point(635, 46);
			this->player2_ai_choice->Name = L"player2_ai_choice";
			this->player2_ai_choice->Size = System::Drawing::Size(118, 23);
			this->player2_ai_choice->TabIndex = 28;
			this->player2_ai_choice->Text = L"Player2 AI";
			this->player2_ai_choice->UseVisualStyleBackColor = true;
			this->player2_ai_choice->Visible = false;
			// 
			// start_button
			// 
			this->start_button->Enabled = false;
			this->start_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start_button->Location = System::Drawing::Point(414, 196);
			this->start_button->Name = L"start_button";
			this->start_button->Size = System::Drawing::Size(151, 55);
			this->start_button->TabIndex = 29;
			this->start_button->Text = L"Start game";
			this->start_button->UseVisualStyleBackColor = true;
			this->start_button->Visible = false;
			this->start_button->Click += gcnew System::EventHandler(this, &MyForm::start_button_Click);
			// 
			// player_1_greedy_no_man
			// 
			this->player_1_greedy_no_man->AutoSize = true;
			this->player_1_greedy_no_man->Location = System::Drawing::Point(6, 19);
			this->player_1_greedy_no_man->Name = L"player_1_greedy_no_man";
			this->player_1_greedy_no_man->Size = System::Drawing::Size(97, 17);
			this->player_1_greedy_no_man->TabIndex = 30;
			this->player_1_greedy_no_man->TabStop = true;
			this->player_1_greedy_no_man->Text = L"Greedy no man";
			this->player_1_greedy_no_man->UseVisualStyleBackColor = true;
			// 
			// player_2_greedy_no_man
			// 
			this->player_2_greedy_no_man->AutoSize = true;
			this->player_2_greedy_no_man->Location = System::Drawing::Point(6, 19);
			this->player_2_greedy_no_man->Name = L"player_2_greedy_no_man";
			this->player_2_greedy_no_man->Size = System::Drawing::Size(97, 17);
			this->player_2_greedy_no_man->TabIndex = 31;
			this->player_2_greedy_no_man->TabStop = true;
			this->player_2_greedy_no_man->Text = L"Greedy no man";
			this->player_2_greedy_no_man->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->player_1_frequency_ai);
			this->groupBox1->Controls->Add(this->player_1_random_select);
			this->groupBox1->Controls->Add(this->player_1_random_ai);
			this->groupBox1->Controls->Add(this->player_1_monte_carlo);
			this->groupBox1->Controls->Add(this->player_1_min_max_free);
			this->groupBox1->Controls->Add(this->player_1_min_max_man);
			this->groupBox1->Controls->Add(this->player_1_min_max_no_man);
			this->groupBox1->Controls->Add(this->player_1_greedy_man);
			this->groupBox1->Controls->Add(this->player_1_greedy_no_man);
			this->groupBox1->Location = System::Drawing::Point(251, 80);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(113, 232);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Visible = false;
			// 
			// player_1_frequency_ai
			// 
			this->player_1_frequency_ai->AutoSize = true;
			this->player_1_frequency_ai->Location = System::Drawing::Point(6, 200);
			this->player_1_frequency_ai->Name = L"player_1_frequency_ai";
			this->player_1_frequency_ai->Size = System::Drawing::Size(75, 17);
			this->player_1_frequency_ai->TabIndex = 38;
			this->player_1_frequency_ai->TabStop = true;
			this->player_1_frequency_ai->Text = L"Frequency";
			this->player_1_frequency_ai->UseVisualStyleBackColor = true;
			// 
			// player_1_random_select
			// 
			this->player_1_random_select->AutoSize = true;
			this->player_1_random_select->Location = System::Drawing::Point(6, 177);
			this->player_1_random_select->Name = L"player_1_random_select";
			this->player_1_random_select->Size = System::Drawing::Size(96, 17);
			this->player_1_random_select->TabIndex = 37;
			this->player_1_random_select->TabStop = true;
			this->player_1_random_select->Text = L"Random select";
			this->player_1_random_select->UseVisualStyleBackColor = true;
			// 
			// player_1_random_ai
			// 
			this->player_1_random_ai->AutoSize = true;
			this->player_1_random_ai->Location = System::Drawing::Point(6, 154);
			this->player_1_random_ai->Name = L"player_1_random_ai";
			this->player_1_random_ai->Size = System::Drawing::Size(65, 17);
			this->player_1_random_ai->TabIndex = 36;
			this->player_1_random_ai->TabStop = true;
			this->player_1_random_ai->Text = L"Random";
			this->player_1_random_ai->UseVisualStyleBackColor = true;
			// 
			// player_1_monte_carlo
			// 
			this->player_1_monte_carlo->AutoSize = true;
			this->player_1_monte_carlo->Location = System::Drawing::Point(6, 131);
			this->player_1_monte_carlo->Name = L"player_1_monte_carlo";
			this->player_1_monte_carlo->Size = System::Drawing::Size(81, 17);
			this->player_1_monte_carlo->TabIndex = 35;
			this->player_1_monte_carlo->TabStop = true;
			this->player_1_monte_carlo->Text = L"Montecarlo ";
			this->player_1_monte_carlo->UseVisualStyleBackColor = true;
			// 
			// player_1_min_max_free
			// 
			this->player_1_min_max_free->AutoSize = true;
			this->player_1_min_max_free->Location = System::Drawing::Point(6, 107);
			this->player_1_min_max_free->Name = L"player_1_min_max_free";
			this->player_1_min_max_free->Size = System::Drawing::Size(94, 17);
			this->player_1_min_max_free->TabIndex = 34;
			this->player_1_min_max_free->TabStop = true;
			this->player_1_min_max_free->Text = L"MinMax space";
			this->player_1_min_max_free->UseVisualStyleBackColor = true;
			// 
			// player_1_min_max_man
			// 
			this->player_1_min_max_man->AutoSize = true;
			this->player_1_min_max_man->Location = System::Drawing::Point(6, 86);
			this->player_1_min_max_man->Name = L"player_1_min_max_man";
			this->player_1_min_max_man->Size = System::Drawing::Size(85, 17);
			this->player_1_min_max_man->TabIndex = 33;
			this->player_1_min_max_man->TabStop = true;
			this->player_1_min_max_man->Text = L"MinMax man";
			this->player_1_min_max_man->UseVisualStyleBackColor = true;
			// 
			// player_1_min_max_no_man
			// 
			this->player_1_min_max_no_man->AutoSize = true;
			this->player_1_min_max_no_man->Location = System::Drawing::Point(6, 64);
			this->player_1_min_max_no_man->Name = L"player_1_min_max_no_man";
			this->player_1_min_max_no_man->Size = System::Drawing::Size(62, 17);
			this->player_1_min_max_no_man->TabIndex = 32;
			this->player_1_min_max_no_man->TabStop = true;
			this->player_1_min_max_no_man->Text = L"MinMax";
			this->player_1_min_max_no_man->UseVisualStyleBackColor = true;
			// 
			// player_1_greedy_man
			// 
			this->player_1_greedy_man->AutoSize = true;
			this->player_1_greedy_man->Location = System::Drawing::Point(6, 43);
			this->player_1_greedy_man->Name = L"player_1_greedy_man";
			this->player_1_greedy_man->Size = System::Drawing::Size(82, 17);
			this->player_1_greedy_man->TabIndex = 31;
			this->player_1_greedy_man->TabStop = true;
			this->player_1_greedy_man->Text = L"Greedy man";
			this->player_1_greedy_man->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->player_2_frequency_ai);
			this->groupBox2->Controls->Add(this->player_2_random_select);
			this->groupBox2->Controls->Add(this->player_2_random_ai);
			this->groupBox2->Controls->Add(this->player_2_monte_carlo);
			this->groupBox2->Controls->Add(this->player_2_min_max_free);
			this->groupBox2->Controls->Add(this->player_2_min_max_man);
			this->groupBox2->Controls->Add(this->player_2_min_max_no_man);
			this->groupBox2->Controls->Add(this->player_2_greedy_man);
			this->groupBox2->Controls->Add(this->player_2_greedy_no_man);
			this->groupBox2->Location = System::Drawing::Point(635, 80);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(126, 232);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			this->groupBox2->Visible = false;
			// 
			// player_2_frequency_ai
			// 
			this->player_2_frequency_ai->AutoSize = true;
			this->player_2_frequency_ai->Location = System::Drawing::Point(6, 200);
			this->player_2_frequency_ai->Name = L"player_2_frequency_ai";
			this->player_2_frequency_ai->Size = System::Drawing::Size(75, 17);
			this->player_2_frequency_ai->TabIndex = 39;
			this->player_2_frequency_ai->TabStop = true;
			this->player_2_frequency_ai->Text = L"Frequency";
			this->player_2_frequency_ai->UseVisualStyleBackColor = true;
			// 
			// player_2_random_select
			// 
			this->player_2_random_select->AutoSize = true;
			this->player_2_random_select->Location = System::Drawing::Point(6, 177);
			this->player_2_random_select->Name = L"player_2_random_select";
			this->player_2_random_select->Size = System::Drawing::Size(96, 17);
			this->player_2_random_select->TabIndex = 38;
			this->player_2_random_select->TabStop = true;
			this->player_2_random_select->Text = L"Random select";
			this->player_2_random_select->UseVisualStyleBackColor = true;
			// 
			// player_2_random_ai
			// 
			this->player_2_random_ai->AutoSize = true;
			this->player_2_random_ai->Location = System::Drawing::Point(6, 154);
			this->player_2_random_ai->Name = L"player_2_random_ai";
			this->player_2_random_ai->Size = System::Drawing::Size(65, 17);
			this->player_2_random_ai->TabIndex = 37;
			this->player_2_random_ai->TabStop = true;
			this->player_2_random_ai->Text = L"Random";
			this->player_2_random_ai->UseVisualStyleBackColor = true;
			// 
			// player_2_monte_carlo
			// 
			this->player_2_monte_carlo->AutoSize = true;
			this->player_2_monte_carlo->Location = System::Drawing::Point(6, 131);
			this->player_2_monte_carlo->Name = L"player_2_monte_carlo";
			this->player_2_monte_carlo->Size = System::Drawing::Size(78, 17);
			this->player_2_monte_carlo->TabIndex = 36;
			this->player_2_monte_carlo->TabStop = true;
			this->player_2_monte_carlo->Text = L"Montecarlo";
			this->player_2_monte_carlo->UseVisualStyleBackColor = true;
			// 
			// player_2_min_max_free
			// 
			this->player_2_min_max_free->AutoSize = true;
			this->player_2_min_max_free->Location = System::Drawing::Point(6, 107);
			this->player_2_min_max_free->Name = L"player_2_min_max_free";
			this->player_2_min_max_free->Size = System::Drawing::Size(94, 17);
			this->player_2_min_max_free->TabIndex = 35;
			this->player_2_min_max_free->TabStop = true;
			this->player_2_min_max_free->Text = L"MinMax space";
			this->player_2_min_max_free->UseVisualStyleBackColor = true;
			// 
			// player_2_min_max_man
			// 
			this->player_2_min_max_man->AutoSize = true;
			this->player_2_min_max_man->Location = System::Drawing::Point(6, 86);
			this->player_2_min_max_man->Name = L"player_2_min_max_man";
			this->player_2_min_max_man->Size = System::Drawing::Size(85, 17);
			this->player_2_min_max_man->TabIndex = 34;
			this->player_2_min_max_man->TabStop = true;
			this->player_2_min_max_man->Text = L"MinMax man";
			this->player_2_min_max_man->UseVisualStyleBackColor = true;
			// 
			// player_2_min_max_no_man
			// 
			this->player_2_min_max_no_man->AutoSize = true;
			this->player_2_min_max_no_man->Location = System::Drawing::Point(6, 64);
			this->player_2_min_max_no_man->Name = L"player_2_min_max_no_man";
			this->player_2_min_max_no_man->Size = System::Drawing::Size(62, 17);
			this->player_2_min_max_no_man->TabIndex = 33;
			this->player_2_min_max_no_man->TabStop = true;
			this->player_2_min_max_no_man->Text = L"MinMax";
			this->player_2_min_max_no_man->UseVisualStyleBackColor = true;
			// 
			// player_2_greedy_man
			// 
			this->player_2_greedy_man->AutoSize = true;
			this->player_2_greedy_man->Location = System::Drawing::Point(6, 43);
			this->player_2_greedy_man->Name = L"player_2_greedy_man";
			this->player_2_greedy_man->Size = System::Drawing::Size(82, 17);
			this->player_2_greedy_man->TabIndex = 32;
			this->player_2_greedy_man->TabStop = true;
			this->player_2_greedy_man->Text = L"Greedy man";
			this->player_2_greedy_man->UseVisualStyleBackColor = true;
			// 
			// simulate_100_games
			// 
			this->simulate_100_games->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->simulate_100_games->Location = System::Drawing::Point(414, 287);
			this->simulate_100_games->Name = L"simulate_100_games";
			this->simulate_100_games->Size = System::Drawing::Size(151, 55);
			this->simulate_100_games->TabIndex = 34;
			this->simulate_100_games->Text = L"Simulate ganes";
			this->simulate_100_games->UseVisualStyleBackColor = true;
			this->simulate_100_games->Visible = false;
			this->simulate_100_games->Click += gcnew System::EventHandler(this, &MyForm::simulate_100_games_Click);
			// 
			// game_looking_back
			// 
			this->game_looking_back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->game_looking_back->Location = System::Drawing::Point(736, 405);
			this->game_looking_back->Name = L"game_looking_back";
			this->game_looking_back->Size = System::Drawing::Size(100, 49);
			this->game_looking_back->TabIndex = 35;
			this->game_looking_back->Text = L"Back\r\n";
			this->game_looking_back->UseVisualStyleBackColor = true;
			this->game_looking_back->Visible = false;
			this->game_looking_back->Click += gcnew System::EventHandler(this, &MyForm::game_looking_back_Click);
			// 
			// game_looking_next
			// 
			this->game_looking_next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->game_looking_next->Location = System::Drawing::Point(859, 405);
			this->game_looking_next->Name = L"game_looking_next";
			this->game_looking_next->Size = System::Drawing::Size(100, 49);
			this->game_looking_next->TabIndex = 36;
			this->game_looking_next->Text = L"Next";
			this->game_looking_next->UseVisualStyleBackColor = true;
			this->game_looking_next->Visible = false;
			this->game_looking_next->Click += gcnew System::EventHandler(this, &MyForm::game_looking_next_Click);
			// 
			// simulation_result
			// 
			this->simulation_result->AutoSize = true;
			this->simulation_result->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->simulation_result->Location = System::Drawing::Point(285, 348);
			this->simulation_result->Name = L"simulation_result";
			this->simulation_result->Size = System::Drawing::Size(162, 19);
			this->simulation_result->TabIndex = 37;
			this->simulation_result->Text = L"Simulation result";
			this->simulation_result->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(996, 475);
			this->Controls->Add(this->simulation_result);
			this->Controls->Add(this->game_looking_next);
			this->Controls->Add(this->game_looking_back);
			this->Controls->Add(this->simulate_100_games);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->start_button);
			this->Controls->Add(this->player2_ai_choice);
			this->Controls->Add(this->player1_ai_choice);
			this->Controls->Add(this->play_with_seed);
			this->Controls->Add(this->additional_info);
			this->Controls->Add(this->player_turn);
			this->Controls->Add(this->patch3_map);
			this->Controls->Add(this->patch2_map);
			this->Controls->Add(this->patch1_map);
			this->Controls->Add(this->selected_patch_matching);
			this->Controls->Add(this->game_seeds_list_label);
			this->Controls->Add(this->patching_blanket);
			this->Controls->Add(this->player2_blanket);
			this->Controls->Add(this->player1_blanket);
			this->Controls->Add(this->looking_patches_next);
			this->Controls->Add(this->looking_patches_back);
			this->Controls->Add(this->undo_patching);
			this->Controls->Add(this->undo_patch_looking);
			this->Controls->Add(this->select_thrd_patch);
			this->Controls->Add(this->select_snd_patch);
			this->Controls->Add(this->select_fst_patch);
			this->Controls->Add(this->look_at_patches_button);
			this->Controls->Add(this->start_patching_button);
			this->Controls->Add(this->skip_time_knobs_button);
			this->Controls->Add(this->back_to_menu_button);
			this->Controls->Add(this->stats_button);
			this->Controls->Add(this->end_game_button);
			this->Controls->Add(this->set_button);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"Patchwork";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//exit game
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}
		   //player game action: start of patching cycle
	private: System::Void start_patching_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide action selection buttons
		this->start_patching_button->Visible = false;
		this->start_patching_button->Enabled = false;
		//this->skip_time_knobs_button->Visible = false;
		//this->skip_time_knobs_button->Enabled = false;
		this->look_at_patches_button->Visible = false;
		this->look_at_patches_button->Enabled = false;

		//now minimalization

		//this->player1_blanket->Visible = false;
		//this->player2_blanket->Visible = false;

		//Proper buttons visible
		this->select_fst_patch->Visible = true;
		this->select_fst_patch->Enabled = true;
		this->select_snd_patch->Visible = true;
		this->select_snd_patch->Enabled = true;
		this->select_thrd_patch->Visible = true;
		this->select_thrd_patch->Enabled = true;
		this->undo_patching->Visible = true;
		this->undo_patching->Enabled = true;
		this->patch1_map->Visible = true;
		this->patch2_map->Visible = true;
		this->patch3_map->Visible = true;
		//hide buttons, if the player lack options
		if (GAME.game_logic.get_playable_patches(GAME.actual_player).size() < 3) {
			this->select_thrd_patch->Visible = false;
			this->select_thrd_patch->Enabled = false;
			this->patch3_map->Visible = false;
		}
		if (GAME.game_logic.get_playable_patches(GAME.actual_player).size() < 2) {
			this->select_snd_patch->Visible = false;
			this->select_snd_patch->Enabled = false;
			this->patch2_map->Visible = false;
		}
		if (GAME.game_logic.get_playable_patches(GAME.actual_player).size() < 1) {
			this->select_fst_patch->Visible = false;
			this->select_fst_patch->Enabled = false;
			this->patch1_map->Visible = false;
		}
		//minimize patching to corrner
		move_during_selection();

		//here add patch fetching and displaying
		show_posible_patches();
		GAME.invert = false;
		GAME.orientation = 'n';
		GAME.x_pos = 0;
		GAME.y_pos = 0;
		std::string add_info_string = "Select your patch, you have " +
			std::to_string(GAME.game_logic.get_knobs(GAME.actual_player)) + " Knobs and " +
			std::to_string(GAME.game_logic.get_time(GAME.actual_player)) + " Time.";
		this->additional_info->Text = gcnew System::String(add_info_string.c_str());
	}
		   //game settings page
	private: System::Void set_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Stats, start and end button hide
		this->set_button->Visible = false;
		this->set_button->Enabled = false;
		this->end_game_button->Visible = false;
		this->end_game_button->Enabled = false;
		this->stats_button->Visible = false;
		this->stats_button->Enabled = false;
		//Action and menu buttons visible
		this->simulate_100_games->Visible = true;
		this->player1_ai_choice->Visible = true;
		this->player1_ai_choice->Enabled = true;
		this->player2_ai_choice->Visible = true;
		this->player2_ai_choice->Enabled = true;
		this->groupBox1->Visible = true;
		this->groupBox2->Visible = true;
		this->start_button->Enabled = true;
		this->start_button->Visible = true;
		this->back_to_menu_button->Visible = true;
		this->back_to_menu_button->Enabled = true;


		//Here add new game start
		GAME.new_game();
		this->additional_info->Text = "Select the AI.";

	}
		   //hide all possible visible buttons and return to menu
	private: System::Void back_to_menu_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((!this->player1_blanket->Visible && !this->patching_blanket->Visible) || (this->player1_blanket->Visible && GAME.game_logic.game_end()) ||
			this->play_with_seed->Visible) {
			//Hide all other buttons
			this->simulation_result->Visible = false;
			this->back_to_menu_button->Visible = false;
			this->back_to_menu_button->Enabled = false;
			this->undo_patching->Visible = false;
			this->undo_patching->Enabled = false;
			this->player1_blanket->Visible = false;
			this->player2_blanket->Visible = false;
			this->game_seeds_list_label->Visible = false;
			this->game_seeds_list_label->Enabled = false;
			this->selected_patch_matching->Visible = false;
			this->player_turn->Visible = false;
			this->play_with_seed->Visible = false;
			this->play_with_seed->Enabled = false;
			this->start_button->Visible = false;
			this->start_button->Enabled = false;
			this->simulate_100_games->Visible = false;
			this->player1_ai_choice->Visible = false;
			this->player1_ai_choice->Enabled = false;
			this->player2_ai_choice->Visible = false;
			this->player2_ai_choice->Enabled = false;
			this->groupBox1->Visible = false;
			this->groupBox2->Visible = false;
			this->game_looking_back->Visible = false;
			this->game_looking_next->Visible = false;
			//Menu buttons
			this->set_button->Visible = true;
			this->set_button->Enabled = true;
			this->end_game_button->Visible = true;
			this->end_game_button->Enabled = true;
			this->stats_button->Visible = true;
			this->stats_button->Enabled = true;

			this->additional_info->Text = "Click set game to set upS new game \nor click  stats to see stats.";
			unmove_menu_undo_trigger();
		}
		else {
			//Get the Undo button
			this->undo_patching->Visible = true;
			this->undo_patching->Enabled = true;
			//Hide game
			this->skip_time_knobs_button->Visible = false;
			this->start_patching_button->Visible = false;
			this->look_at_patches_button->Visible = false;
			this->select_fst_patch->Visible = false;
			this->select_snd_patch->Visible = false;
			this->select_thrd_patch->Visible = false;
			this->undo_patch_looking->Visible = false;
			this->looking_patches_back->Visible = false;
			this->looking_patches_next->Visible = false;
			this->player1_blanket->Visible = false;
			this->player2_blanket->Visible = false;
			this->patching_blanket->Visible = false;
			this->selected_patch_matching->Visible = false;
			this->patch1_map->Visible = false;
			this->patch2_map->Visible = false;
			this->patch3_map->Visible = false;
			move_menu_undo_trigger();
			this->player_turn->Text = "Are you sure to end the game and return back to menu?\nPress Menu to go back to menu\nPress Cancel to go back to game";



		}
	}
		   //player game action: skip time for knobs
	private: System::Void skip_time_knobs_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//tell the game to skip time for current palyer
		GAME.game_logic.spend_time_knobs(GAME.actual_player);
		//Hide possible buttons of selecting patch
		this->select_fst_patch->Visible = false;
		this->select_fst_patch->Enabled = false;
		this->select_snd_patch->Visible = false;
		this->select_snd_patch->Enabled = false;
		this->select_thrd_patch->Visible = false;
		this->select_thrd_patch->Enabled = false;
		this->undo_patching->Visible = false;
		this->undo_patching->Enabled = false;
		this->patching_blanket->Visible = false;
		this->selected_patch_matching->Visible = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//progress the game
		unmove_during_selection();
		game_progress(false);
	}
		   //return back to base game options
	private: System::Void undo_patching_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hide possible buttons of selecting patch
		this->select_fst_patch->Visible = false;
		this->select_fst_patch->Enabled = false;
		this->select_snd_patch->Visible = false;
		this->select_snd_patch->Enabled = false;
		this->select_thrd_patch->Visible = false;
		this->select_thrd_patch->Enabled = false;
		this->undo_patching->Visible = false;
		this->undo_patching->Enabled = false;
		this->patching_blanket->Visible = false;
		this->selected_patch_matching->Visible = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//Base game
		this->player1_blanket->Visible = true;
		this->player2_blanket->Visible = true;
		this->back_to_menu_button->Visible = true;
		this->back_to_menu_button->Enabled = true;
		this->skip_time_knobs_button->Visible = true;
		this->skip_time_knobs_button->Enabled = true;
		this->start_patching_button->Visible = true;
		this->start_patching_button->Enabled = true;
		this->look_at_patches_button->Visible = true;
		this->look_at_patches_button->Enabled = true;


		//revert color
		this->patch1_map->ForeColor = System::Drawing::Color::Black;
		this->patch2_map->ForeColor = System::Drawing::Color::Black;
		this->patch3_map->ForeColor = System::Drawing::Color::Black;
		//Here properly drop input
		unmove_during_selection();
		unmove_menu_undo_trigger();
		show_players_data();
		this->additional_info->Text = "Welcome to patchwork, \npress skip to skip time, \nor start patching.";
		get_actual_player();
		free_1x1_patch_player();
		bonus_added();
	}
		   //Selection of patch choosing
	private: System::Void select_fst_patch_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide the patch selection
		this->select_fst_patch->Visible = false;
		this->select_fst_patch->Enabled = false;
		this->select_snd_patch->Visible = false;
		this->select_snd_patch->Enabled = false;
		this->select_thrd_patch->Visible = false;
		this->select_thrd_patch->Enabled = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//patching start no skip
		this->skip_time_knobs_button->Visible = false;
		//revert map placement

		this->player1_blanket->Visible = false;
		this->player2_blanket->Visible = false;
		unmove_during_selection();
		//revert color
		this->patch1_map->ForeColor = System::Drawing::Color::Black;
		this->patch2_map->ForeColor = System::Drawing::Color::Black;
		this->patch3_map->ForeColor = System::Drawing::Color::Black;
		//make visible patching blanket and selected patch
		this->patching_blanket->Visible = true;
		this->selected_patch_matching->Visible = true;
		//Here add selecting 1st patch
		selected_patch(0);
		show_patching_player();
		show_selected_patch();
		place_label_on_blanket();
		this->additional_info->Text = "Use j and k to rotate patch.\nUse i for patch inverting. \nTo move patch use w s a d. \nTo finaly patch press p for patch.\nIf the patch is green patch place is good.";

	}
	private: System::Void select_snd_patch_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide the patch selection
		this->select_fst_patch->Visible = false;
		this->select_fst_patch->Enabled = false;
		this->select_snd_patch->Visible = false;
		this->select_snd_patch->Enabled = false;
		this->select_thrd_patch->Visible = false;
		this->select_thrd_patch->Enabled = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//patching start no skip
		this->skip_time_knobs_button->Visible = false;
		//revert map placement
		this->player1_blanket->Visible = false;
		this->player2_blanket->Visible = false;
		unmove_during_selection();
		//revert color
		this->patch1_map->ForeColor = System::Drawing::Color::Black;
		this->patch2_map->ForeColor = System::Drawing::Color::Black;
		this->patch3_map->ForeColor = System::Drawing::Color::Black;
		//make visible patching blanket and selected patch
		this->patching_blanket->Visible = true;
		this->selected_patch_matching->Visible = true;
		//Here add selecting 2nd patch
		selected_patch(1);
		show_patching_player();
		show_selected_patch();
		place_label_on_blanket();
		this->additional_info->Text = "Use j and k to rotate patch.\nUse i for patch inverting. \nTo move patch use w s a d. \nTo finaly patch press p for patch.\nIf the patch is green patch place is good.";

	}
	private: System::Void select_thrd_patch_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide the patch selection
		this->select_fst_patch->Visible = false;
		this->select_fst_patch->Enabled = false;
		this->select_snd_patch->Visible = false;
		this->select_snd_patch->Enabled = false;
		this->select_thrd_patch->Visible = false;
		this->select_thrd_patch->Enabled = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//patching start no skip
		this->skip_time_knobs_button->Visible = false;
		//revert map placement
		this->player1_blanket->Visible = false;
		this->player2_blanket->Visible = false;
		unmove_during_selection();
		//revert color
		this->patch1_map->ForeColor = System::Drawing::Color::Black;
		this->patch2_map->ForeColor = System::Drawing::Color::Black;
		this->patch3_map->ForeColor = System::Drawing::Color::Black;
		//make visible patching blanket and selected patch
		this->patching_blanket->Visible = true;
		this->selected_patch_matching->Visible = true;
		//Here add selecting 3rd patch
		selected_patch(2);
		show_patching_player();
		show_selected_patch();
		place_label_on_blanket();
		this->additional_info->Text = "Use j and k to rotate patch.\nUse i for patch inverting. \nTo move patch use w s a d. \nTo finaly patch press p for patch.\nIf the patch is green patch place is good.";

	}
		   //Display the played game seeds for further examination
	private: System::Void stats_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hide main menu
		this->set_button->Visible = false;
		this->set_button->Enabled = false;
		this->end_game_button->Visible = false;
		this->end_game_button->Enabled = false;
		this->stats_button->Visible = false;
		this->stats_button->Enabled = false;
		this->player1_ai_choice->Visible = false;
		this->player1_ai_choice->Enabled = false;
		this->player2_ai_choice->Visible = false;
		this->player2_ai_choice->Enabled = false;
		this->groupBox1->Visible = false;
		this->groupBox2->Visible = false;
		//make visible menu
		this->back_to_menu_button->Visible = true;
		this->back_to_menu_button->Enabled = true;
		this->game_seeds_list_label->Visible = true;
		this->game_seeds_list_label->Enabled = true;
		//start looking from 0
		GAME.game_look_index = 0;
		GAME.num_games = GAME.get_save_game_seeds().size();

		//Add looking at seed and geting input
		if (GAME.num_games > NUM_GAMES_PAGE)
			this->game_looking_next->Visible = true;
		show_seeds();
		this->additional_info->Text = "Here are past games seeds.\nClick on the seed to see the result of game.";
	}
		   //display patches left in game
	private: System::Void look_at_patches_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//Hide action buttons
		this->skip_time_knobs_button->Visible = false;
		this->skip_time_knobs_button->Enabled = false;
		this->start_patching_button->Visible = false;
		this->start_patching_button->Enabled = false;
		this->look_at_patches_button->Visible = false;
		this->look_at_patches_button->Enabled = false;
		this->player1_blanket->Visible = false;
		this->player2_blanket->Visible = false;
		this->back_to_menu_button->Visible = false;
		//add buttons for looking at patches
		this->looking_patches_back->Visible = true;
		this->looking_patches_back->Enabled = true;
		this->looking_patches_next->Visible = true;
		this->looking_patches_next->Enabled = true;
		this->undo_patch_looking->Visible = true;
		this->undo_patch_looking->Enabled = true;

		//get patches in order
		GAME.patch_look_index = 0;
		show_three_patches();
		this->additional_info->Text = "Use Next and Back to look at different patches";
	}
		   //return to base game options
	private: System::Void undo_patch_looking_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide buttons for looking at patches
		this->looking_patches_back->Visible = false;
		this->looking_patches_back->Enabled = false;
		this->looking_patches_next->Visible = false;
		this->looking_patches_next->Enabled = false;
		this->undo_patch_looking->Visible = false;
		this->undo_patch_looking->Enabled = false;
		this->patch1_map->Visible = false;
		this->patch2_map->Visible = false;
		this->patch3_map->Visible = false;
		//add back the action buttons
		this->player1_blanket->Visible = true;
		this->player2_blanket->Visible = true;
		this->skip_time_knobs_button->Visible = true;
		this->skip_time_knobs_button->Enabled = true;
		this->start_patching_button->Visible = true;
		this->start_patching_button->Enabled = true;
		this->look_at_patches_button->Visible = true;
		this->look_at_patches_button->Enabled = true;
		this->back_to_menu_button->Visible = true;

		//hide possible patches on screen
		show_players_data();
		this->additional_info->Text = "Welcome to patchwork, \npress skip to skip time, \nor start patching.";
		free_1x1_patch_player();

	}
		   //display previous 3 patches
	private: System::Void looking_patches_back_Click(System::Object^ sender, System::EventArgs^ e) {
		//load next set of patches
		GAME.patch_look_index -= 3;
		if (GAME.patch_look_index < 0) {
			GAME.patch_look_index = (GAME.game_logic.get_actual_patches().size() - 1) - ((GAME.game_logic.get_actual_patches().size() - 1) % 3);
			if (GAME.patch_look_index < 0) {
				GAME.patch_look_index = 0;
			}
		}
		show_three_patches();

	}
		   //display next 3 patches
	private: System::Void looking_patches_next_Click(System::Object^ sender, System::EventArgs^ e) {
		//load next set of patches
		GAME.patch_look_index += 3;
		if (GAME.patch_look_index >= (int)GAME.game_logic.get_actual_patches().size()) {
			GAME.patch_look_index = 0;
		}
		show_three_patches();
	}
		   //show state of the game
	private: System::Void show_players_data() {
		//Gather data
		auto player1_blanket_ = GAME.game_logic.get_blanket(1).get_blanket_map();
		auto player2_blanket_ = GAME.game_logic.get_blanket(2).get_blanket_map();
		auto player1_time = GAME.game_logic.get_time(1);
		auto player2_time = GAME.game_logic.get_time(2);
		auto player1_points = GAME.game_logic.get_actual_point_tally().first;
		auto player2_points = GAME.game_logic.get_actual_point_tally().second;
		auto player1_knobs = GAME.game_logic.get_knobs(1);
		auto player2_knobs = GAME.game_logic.get_knobs(2);
		auto player1_bonus_knobs = GAME.game_logic.get_blanket(1).return_bonus_knobs();
		auto player2_bonus_knobs = GAME.game_logic.get_blanket(2).return_bonus_knobs();
		//create standart string and store the player data to it
		std::string player1_info = ((GAME.active_AI_player1) ? GAME.computer_AI_player1->get_name() : "") +
			"Player" + std::to_string(1) + "\n" + "Points: " + std::to_string(player1_points) +
			" Bonus knobs: " + std::to_string(player1_bonus_knobs) + "\n" +
			"Time: " + std::to_string(player1_time) + " Knobs: " + std::to_string(player1_knobs) + "\n";
		for (auto&& blanket_vector : player1_blanket_) {
			for (auto&& individual_int : blanket_vector) {
				if (individual_int > 0) {
					player1_info += "[X]";
				}
				else {
					player1_info += "[ ]";
				}
			}
			player1_info += "\n";
		}
		//create system string from standart string and store it in label
		this->player1_blanket->Text = gcnew System::String(player1_info.c_str());

		std::string player2_info = ((GAME.active_AI_player2) ? GAME.computer_AI_player2->get_name() : "") +
			"Player" + std::to_string(2) + "\n" + "Points: " + std::to_string(player2_points) +
			" Bonus knobs: " + std::to_string(player2_bonus_knobs) + "\n" +
			"Time: " + std::to_string(player2_time) + " Knobs: " + std::to_string(player2_knobs) + "\n";

		for (auto&& blanket_vector : player2_blanket_) {
			for (auto&& individual_int : blanket_vector) {
				if (individual_int > 0) {
					player2_info += "[X]";
				}
				else {
					player2_info += "[ ]";
				}
			}
			player2_info += "\n";
		}
		this->player2_blanket->Text = gcnew System::String(player2_info.c_str());
	}
		   //show the seeds of saved games
	private: System::Void show_seeds() {
		//gather the saved seeds
		auto game_seeds = GAME.get_save_game_seeds();
		//create standart string
		std::string game_seeds_label_ = "";
		int i = GAME.game_look_index * NUM_GAMES_PAGE;
		while (i < (GAME.game_look_index + 1) * NUM_GAMES_PAGE && i < (int)game_seeds.size()) {
			auto&& seed = game_seeds[i];
			game_seeds_label_ += "Game " + std::to_string(i + 1) + " Seed: " + seed + "\n";
			i++;
		}
		//cretae system string to be stored in label
		this->game_seeds_list_label->Text = gcnew System::String(game_seeds_label_.c_str());
	}
		   //store the selected patch
	private: System::Void selected_patch(int index) {
		if (index < (int)GAME.game_logic.get_playable_patches(GAME.actual_player).size()) {
			GAME.input_patch = GAME.game_logic.get_playable_patches(GAME.actual_player)[index];
		}
	}
		   //set the player who is on turn and special positions, if ai, make all ai plays
	private: System::Void get_actual_player() {
		//set string and get the bonus places
		std::string player_turn_and_info = "";
		std::vector<int> bonus_knob_pos = std::vector<int>(std::begin(BASE_KNOB_POS), std::end(BASE_KNOB_POS));
		std::vector<int> bonus_patch_pos = std::vector<int>(std::begin(BASE_SPECIAL_POS), std::end(BASE_SPECIAL_POS));
		//get whoes turn is it
		if (GAME.game_logic.whos_turn()) {
			GAME.actual_player = 1;
			player_turn_and_info = "Player1's turn\n";
		}
		else {
			GAME.actual_player = 2;
			player_turn_and_info = "Player2's turn\n";
		}
		//Bonus knobs positions
		player_turn_and_info += "Bonus knobs positions: ";
		for (auto&& knob_pos : bonus_knob_pos) {
			player_turn_and_info += std::to_string(knob_pos) + ",";
		}
		//remove the last ,
		player_turn_and_info.pop_back();
		player_turn_and_info += "\n";
		//bonus patch positions
		player_turn_and_info += "Bonus patch positions: ";
		for (auto&& patch_pos : bonus_patch_pos) {
			player_turn_and_info += std::to_string(patch_pos) + ",";
		}
		player_turn_and_info.pop_back();
		//set the text
		this->player_turn->Text = gcnew System::String(player_turn_and_info.c_str());

		//Place for potential AI Play
		//works for 2 players, special patch is not implemented yet

		//bool if AI moved
		bool something_done = false;
		while ((GAME.actual_player == 1 && GAME.active_AI_player1) || (GAME.actual_player == 2 && GAME.active_AI_player2)) {
			something_done = true;
			if (GAME.actual_player == 1 && GAME.active_AI_player1) {
				auto move = GAME.computer_AI_player1->make_move(GAME.game_logic.current_game_state(GAME.actual_player));
				GAME.game_logic.compact_action_evaluation(move);
				GAME.actual_player = (GAME.game_logic.whos_turn()) ? 1 : 2;
				GAME.actual_player = (GAME.game_logic.game_end()) ? 0 : GAME.actual_player;
			}
			else {
				auto move = GAME.computer_AI_player2->make_move(GAME.game_logic.current_game_state(GAME.actual_player));
				GAME.game_logic.compact_action_evaluation(move);
				GAME.actual_player = (GAME.game_logic.whos_turn()) ? 1 : 2;
				GAME.actual_player = (GAME.game_logic.game_end()) ? 0 : GAME.actual_player;
			}
		}
		if (something_done) { //if ai moved update the game based on the data
			game_progress(true);
		}



	}
		   //show patches that player can choose
	private: System::Void show_posible_patches() {
		//get the patches
		auto&& patch_vector = GAME.game_logic.get_playable_patches(GAME.actual_player);
		auto&& player_knob_count = GAME.game_logic.get_knobs(GAME.actual_player);
		//based on vector size, prepare the patch info
		if (patch_vector.size() > 0) {
			std::string patch1_info = "Time: " + std::to_string(patch_vector[0].get_time_cost()) + " Knobs: " +
				std::to_string(patch_vector[0].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patch_vector[0].get_bonus_knobs()) + "\n" + "\n";
			//go through patch 
			for (auto&& vector_bools : patch_vector[0].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch1_info += "[X]"; }
					else { patch1_info += "   "; }
				}
				patch1_info += "\n";
			}
			//store the info
			this->patch1_map->Text = gcnew System::String(patch1_info.c_str());

			//display if patch good
			if (player_knob_count < patch_vector[0].get_knobs_cost()) {
				this->patch1_map->ForeColor = System::Drawing::Color::Red;
				this->select_fst_patch->Visible = false;
				this->select_fst_patch->Enabled = false;
			}
			else {
				this->patch1_map->ForeColor = System::Drawing::Color::Green;
			}
		}
		if (patch_vector.size() > 1) {
			std::string patch2_info = "Time: " + std::to_string(patch_vector[1].get_time_cost()) + " Knobs: " +
				std::to_string(patch_vector[1].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patch_vector[1].get_bonus_knobs()) + "\n" + "\n";
			for (auto&& vector_bools : patch_vector[1].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch2_info += "[X]"; }
					else { patch2_info += "   "; }
				}
				patch2_info += "\n";
			}
			this->patch2_map->Text = gcnew System::String(patch2_info.c_str());

			if (player_knob_count < patch_vector[1].get_knobs_cost()) {
				this->patch2_map->ForeColor = System::Drawing::Color::Red;
				this->select_snd_patch->Visible = false;
				this->select_snd_patch->Enabled = false;
			}
			else {
				this->patch2_map->ForeColor = System::Drawing::Color::Green;
			}
		}
		if (patch_vector.size() > 2) {
			std::string patch3_info = "Time: " + std::to_string(patch_vector[2].get_time_cost()) + " Knobs: " +
				std::to_string(patch_vector[2].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patch_vector[2].get_bonus_knobs()) + "\n" + "\n";
			for (auto&& vector_bools : patch_vector[2].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch3_info += "[X]"; }
					else { patch3_info += "   "; }
				}
				patch3_info += "\n";
			}
			this->patch3_map->Text = gcnew System::String(patch3_info.c_str());

			if (player_knob_count < patch_vector[2].get_knobs_cost()) {
				this->patch3_map->ForeColor = System::Drawing::Color::Red;
				this->select_thrd_patch->Visible = false;
				this->select_thrd_patch->Enabled = false;
			}
			else {
				this->patch3_map->ForeColor = System::Drawing::Color::Green;
			}
		}
	}
		   //show the patch player has selected
	private: System::Void show_selected_patch() {
		//get the map and store it
		std::string input_patch_map = "";
		auto patch_map = GAME.input_patch.oriented_map(GAME.orientation, GAME.invert);
		//get the player map
		auto player_blanket_map = GAME.game_logic.get_blanket(GAME.actual_player).get_blanket_map();
		//set the color to gree to signal no problems
		this->selected_patch_matching->ForeColor = System::Drawing::Color::Green;
		//go through the patch and display the patch
		for (size_t i = 0; i < patch_map.size(); i++) {
			for (size_t j = 0; j < patch_map[0].size(); j++) {
				if (patch_map[i][j]) {
					input_patch_map += "[P]";
					//look if there are conflicts, if there are display as red
					if (GAME.y_pos + i >= 0 && GAME.y_pos + i < BLANKET_SIZE && GAME.x_pos + j >= 0 && GAME.x_pos + j < BLANKET_SIZE) {
						if (player_blanket_map[GAME.y_pos + i][GAME.x_pos + j] > 0) {
							this->selected_patch_matching->ForeColor = System::Drawing::Color::Red;
						}
					}
					//some position out of blanket
					else {
						this->selected_patch_matching->ForeColor = System::Drawing::Color::Red;
					}
				}
				//patch is not at this point
				else {
					//if in blanket, show the curr patch index in that position
					if (GAME.y_pos + i >= 0 && GAME.y_pos + i < BLANKET_SIZE && GAME.x_pos + j >= 0 && GAME.x_pos + j < BLANKET_SIZE) {
						//base on number, to generate proper offset
						if (player_blanket_map[GAME.y_pos + i][GAME.x_pos + j] > 0) {
							input_patch_map += "[X]";
						}
						else {
							input_patch_map += "[ ]";
						}
					}
					//to display proper patch placement
					else {
						input_patch_map += "   ";
					}
				}

			}
			input_patch_map += "\n";
		}
		this->selected_patch_matching->Text = gcnew System::String(input_patch_map.c_str());
	}
		   //show the blanket player is patching
	private: System::Void show_patching_player() {
		std::string blanket_player = "";
		//go through the blanket and display the indexes
		for (auto&& vector_int : GAME.game_logic.get_blanket(GAME.actual_player).get_blanket_map()) {
			for (auto&& indiv_int : vector_int) {
				if (indiv_int > 0) {
					blanket_player += "[X]";
				}
				else {
					blanket_player += "[ ]";
				}
			}
			blanket_player += "\n";
		}
		this->patching_blanket->Text = gcnew System::String(blanket_player.c_str());
	}
		   //keyboard input to form to patch the blanket
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//must be while patching
		if (this->selected_patch_matching->Visible == true) {
			//translation input from w s a d, boundry checks
			if (e->KeyCode == System::Windows::Forms::Keys::W) {
				GAME.y_pos -= 1;
				if (GAME.y_pos < 0) { GAME.y_pos = 0; }
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::S) {
				GAME.y_pos += 1;
				if (GAME.y_pos > 8) { GAME.y_pos = 8; }
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::A) {
				GAME.x_pos -= 1;
				if (GAME.x_pos < 0) { GAME.x_pos = 0; }
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::D) {
				GAME.x_pos += 1;
				if (GAME.x_pos > 8) { GAME.x_pos = 8; }
			}
			//rotation input with j k
			else if (e->KeyCode == System::Windows::Forms::Keys::J) {
				switch (GAME.orientation)
				{
				case 'n':
					GAME.orientation = 'e';
					break;
				case 'e':
					GAME.orientation = 's';
					break;
				case 's':
					GAME.orientation = 'w';
					break;
				case 'w':
					GAME.orientation = 'n';
					break;
				}
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::K) {
				switch (GAME.orientation)
				{
				case 'n':
					GAME.orientation = 'w';
					break;
				case 'e':
					GAME.orientation = 'n';
					break;
				case 's':
					GAME.orientation = 'e';
					break;
				case 'w':
					GAME.orientation = 's';
					break;
				}
			}
			//inversion
			else if (e->KeyCode == System::Windows::Forms::Keys::I) {
				if (GAME.invert) { GAME.invert = false; }
				else { GAME.invert = true; }
			}
			//the patching itself done with key P		
			else if (e->KeyCode == System::Windows::Forms::Keys::P) {
				//try patch and go back to action selection
				GAME.game_logic.patch_blanket(GAME.actual_player, GAME.input_patch, GAME.y_pos, GAME.x_pos, GAME.orientation, GAME.invert);

				this->undo_patching->Visible = false;
				this->undo_patching->Enabled = false;
				this->patching_blanket->Visible = false;
				this->selected_patch_matching->Visible = false;

				this->player1_blanket->Visible = true;
				this->player2_blanket->Visible = true;

				game_progress(false);

			}
			//If the game hasn't ended display
			if (!GAME.game_logic.game_end()) {
				place_label_on_blanket();
				show_selected_patch();
			}

		}
		else {
			if (e->KeyCode == System::Windows::Forms::Keys::P && this->start_patching_button->Visible) {
				start_patching_button->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::S && this->skip_time_knobs_button->Visible) {
				skip_time_knobs_button->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::U && this->undo_patching->Visible && this->undo_patching->Text->Contains("Undo")) {
				undo_patching->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::C && this->undo_patching->Visible && this->undo_patching->Text->Contains("Cancel")) {
				undo_patching->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::C && this->undo_patch_looking->Visible) {
				undo_patch_looking->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::F1 && this->select_fst_patch->Visible) {
				select_fst_patch->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::F2 && this->select_snd_patch->Visible) {
				select_snd_patch->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::F3 && this->select_thrd_patch->Visible) {
				select_thrd_patch->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::M && this->back_to_menu_button->Visible) {
				back_to_menu_button->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::L && this->look_at_patches_button->Visible) {
				look_at_patches_button->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::D && this->looking_patches_next->Visible) {
				looking_patches_next->PerformClick();
			}
			else if (e->KeyCode == System::Windows::Forms::Keys::A && this->looking_patches_back->Visible) {
				looking_patches_back->PerformClick();
			}
		}
	}
		   //place the patch on blanket visualy
	private: System::Void place_label_on_blanket() {
		//get the blanket position and size
		int offset = 5;
		auto x_lock = this->patching_blanket->Location.X;
		auto y_lock = this->patching_blanket->Location.Y;
		auto x_size = this->patching_blanket->Size.Width - offset;
		auto y_size = this->patching_blanket->Size.Height;
		//get the offset for patch from player input position
		int x_off = (x_size / BLANKET_SIZE) * GAME.x_pos;
		int y_off = (y_size / BLANKET_SIZE) * GAME.y_pos;
		//locate the patch on given point
		this->selected_patch_matching->Location = System::Drawing::Point(x_lock + x_off, y_lock + y_off);

		this->selected_patch_matching->BackColor = System::Drawing::Color::Transparent;
		//bring the patch to front
		this->selected_patch_matching->BringToFront();

	}
		   //after end annouce who won
	private: System::Void who_won() {
		//who has more points
		if (GAME.game_logic.who_won() && GAME.game_logic.get_actual_point_tally().first != GAME.game_logic.get_actual_point_tally().second) {
			this->player_turn->Text = gcnew System::String((((GAME.active_AI_player1) ? GAME.computer_AI_player1->get_name() : "") + "Player1 won").c_str());
		}
		else if (!GAME.game_logic.who_won() && GAME.game_logic.get_actual_point_tally().first != GAME.game_logic.get_actual_point_tally().second) {
			this->player_turn->Text = gcnew System::String((((GAME.active_AI_player2) ? GAME.computer_AI_player2->get_name() : "") + "Player2 won").c_str());
		}
		//points equal, who was first at the end
		else {
			if (GAME.game_logic.who_won()) {
				this->player_turn->Text = gcnew System::String((((GAME.active_AI_player2) ? GAME.computer_AI_player2->get_name() : "") + "Player2 won on time").c_str());
			}
			else {
				this->player_turn->Text = gcnew System::String((((GAME.active_AI_player1) ? GAME.computer_AI_player1->get_name() : "") + "Player1 won on time").c_str());
			}
		}
	}
		   //display patches to player
	private: System::Void show_three_patches() {
		//get the patches
		auto patches = GAME.game_logic.get_actual_patches();
		//base on size, make labels visible
		if (GAME.patch_look_index < (int)patches.size()) {
			//gather the info about patch
			this->patch1_map->Visible = true;
			std::string patch1_info = "Time: " + std::to_string(patches[GAME.patch_look_index].get_time_cost()) + " Knobs: " +
				std::to_string(patches[GAME.patch_look_index].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patches[GAME.patch_look_index].get_bonus_knobs()) + " Distance from pos: " +
				std::to_string(GAME.patch_look_index) + "\n" + "\n";
			//go through patch and store the info
			for (auto&& vector_bools : patches[GAME.patch_look_index].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch1_info += "[X]"; }
					else { patch1_info += "   "; }
				}
				patch1_info += "\n";
			}
			this->patch1_map->Text = gcnew System::String(patch1_info.c_str());
		}
		else {
			this->patch1_map->Visible = false;
		}
		if (GAME.patch_look_index + 1 < (int)patches.size()) {
			this->patch2_map->Visible = true;
			std::string patch2_info = "Time: " + std::to_string(patches[GAME.patch_look_index + 1].get_time_cost()) + " Knobs: " +
				std::to_string(patches[GAME.patch_look_index + 1].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patches[GAME.patch_look_index + 1].get_bonus_knobs()) + " Distance from pos: " +
				std::to_string(GAME.patch_look_index + 1) + "\n" + "\n";
			for (auto&& vector_bools : patches[GAME.patch_look_index + 1].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch2_info += "[X]"; }
					else { patch2_info += "   "; }
				}
				patch2_info += "\n";
			}
			this->patch2_map->Text = gcnew System::String(patch2_info.c_str());
		}
		else {
			this->patch2_map->Visible = false;
		}
		if (GAME.patch_look_index + 2 < (int)patches.size()) {
			this->patch3_map->Visible = true;
			std::string patch3_info = "Time: " + std::to_string(patches[GAME.patch_look_index + 2].get_time_cost()) + " Knobs: " +
				std::to_string(patches[GAME.patch_look_index + 2].get_knobs_cost()) + "\n" + "Bonus: " +
				std::to_string(patches[GAME.patch_look_index + 2].get_bonus_knobs()) + " Distance from pos: " +
				std::to_string(GAME.patch_look_index + 2) + "\n" + "\n";
			for (auto&& vector_bools : patches[GAME.patch_look_index + 2].oriented_map('n', false)) {
				for (auto&& indiv_bool : vector_bools) {
					if (indiv_bool) { patch3_info += "[X]"; }
					else { patch3_info += "   "; }
				}
				patch3_info += "\n";
			}
			this->patch3_map->Text = gcnew System::String(patch3_info.c_str());
		}
		else {
			this->patch3_map->Visible = false;
		}

	}
		   // Retrive the game that the user has clicked on and display it.
	private: System::Void game_seeds_list_label_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//hide list
		this->game_seeds_list_label->Visible = false;
		this->game_seeds_list_label->Enabled = false;
		this->game_looking_back->Visible = false;
		this->game_looking_next->Visible = false;
		//to display results
		this->player1_blanket->Visible = true;
		this->player2_blanket->Visible = true;
		this->player_turn->Visible = true; //display header info
		//button for new game
		this->play_with_seed->Visible = true;
		this->play_with_seed->Enabled = true;
		//get the click location, get the label size and location
		auto y_click = e->Location.Y;
		auto y_point = this->game_seeds_list_label->Location.Y;
		auto y_hight = this->game_seeds_list_label->Size.Height;
		//num of games
		auto game_per_page = GAME.num_games;
		//no games, return
		if (game_per_page == 0)
			return;
		else if (game_per_page > NUM_GAMES_PAGE)
			game_per_page = NUM_GAMES_PAGE;
		//games, find the margin where player need to click
		int margin = y_hight / game_per_page;
		int game_index = 0;
		//find on which game player clicked
		for (int i = 0; i < (int)game_per_page; i++) {
			if (y_click < ((i + 1) * margin)) {
				game_index = i;
				break;
			}
		}
		//Adding the page factor
		game_index += GAME.game_look_index * NUM_GAMES_PAGE;
		//get the filestream and data from it
		std::ifstream file(SAVE_FILE);
		std::string line;
		int i = 0;
		//go through seeds until on set game
		while (std::getline(file, line) && i <= game_index) {
			bool add = true;
			//chceck the line by char
			for (auto&& line_char : line) {
				if (!isdigit(line_char)) { //if some char is not digit, can't be seed
					add = false;
				}
			}
			if (add && line != "") { //if no problems were found add to seed vector
				if (game_index == i) {
					break;
				}
				i++;
			}
		}
		//get the header info
		std::string header_info = "Game " + std::to_string(game_index + 1) + " Seed: " + line + "\n";
		//store the info into seed for possible new game
		GAME.stored_seed = std::stoi(line);
		//who won
		std::getline(file, line);
		header_info += line + "\n";
		std::getline(file, line);
		header_info += "Taken patch order: ";
		//print patch order
		int j = 0;
		//print by individual standart
		std::stringstream patches_line = std::stringstream(line);
		std::string invd_patch;
		//go through patches
		while (std::getline(patches_line, invd_patch, ',')) {
			//new line based on number of patches
			if (j != 0 && j % 15 == 0) {
				header_info += "\n";
			}
			header_info += invd_patch + ",";
			j += 1;
		}
		//player information
		this->player_turn->Text = gcnew System::String(header_info.c_str());
		std::getline(file, line);
		std::string player1_info = line + "\n";
		std::getline(file, line);
		player1_info += "Points: ";
		player1_info += line + "\n";
		for (int i = 0; i < BLANKET_SIZE; i++) {
			std::getline(file, line);
			player1_info += line + "\n";
		}
		this->player1_blanket->Text = gcnew System::String(player1_info.c_str());

		std::getline(file, line);
		std::string player2_info = line + "\n";
		std::getline(file, line);
		player2_info += "Points: ";
		player2_info += line + "\n";
		for (int i = 0; i < BLANKET_SIZE; i++) {
			std::getline(file, line);
			player2_info += line + "\n";
		}
		this->player2_blanket->Text = gcnew System::String(player2_info.c_str());
		this->additional_info->Text = "Here are the results of this game.\nClick the button to play new game with the same seed.";


	}
		   //new game with seed stored in stats viewing
	private: System::Void play_with_seed_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide new game button
		this->play_with_seed->Visible = false;
		this->play_with_seed->Enabled = false;
		//hide the stats
		this->player1_blanket->Visible = false;
		this->player2_blanket->Visible = false;
		this->player_turn->Visible = false;

		this->start_button->Visible = true;
		this->start_button->Enabled = true;
		this->player1_ai_choice->Visible = true;
		this->player1_ai_choice->Enabled = true;
		this->player2_ai_choice->Visible = true;
		this->player2_ai_choice->Enabled = true;
		this->groupBox1->Visible = true;
		this->groupBox2->Visible = true;
		this->back_to_menu_button->Visible = true;
		this->back_to_menu_button->Enabled = true;
		//create new game with seed
		auto seed = GAME.stored_seed;
		GAME.new_game();
		GAME.game_logic = Game_handling(1, seed);
		this->additional_info->Text = "Select the AI.";



	}

		   //free 1x1 patch is to be placed
	private: System::Void free_1x1_patch_player() {
		//is there a free patch?
		if (GAME.game_logic.free_1x1_patch(GAME.actual_player)) {
			//get the proper text
			switch (GAME.actual_player) {
			case 1:
				this->player_turn->Text = "Player1 have recieved special patch";
				break;
			case 2:
				this->player_turn->Text = "Player2 have recieved special patch";
				break;
			default:
				break;
			}
			//hide the skip button
			this->skip_time_knobs_button->Visible = false;
			this->skip_time_knobs_button->Enabled = false;
		}
	}
		   //display if bonus knobs were added.
	private: System::Void bonus_added() {
		//zero idicates that no bonus knobs were added
		if (GAME.game_logic.added_curr_val() != 0) {
			//based on the flag num
			switch (GAME.game_logic.added_curr_val()) {
			case 1:
				this->player_turn->Text = "Added bonus knobs to Player1\n" + this->player_turn->Text;
				break;
			case 2:
				this->player_turn->Text = "Added bonus knobs to Player2\n" + this->player_turn->Text;
				break;
			default:
				break;
			}
			GAME.game_logic.set_added_to_zero();
		}
	}

		   //change button position based on player
	private: System::Void player_specific_control() {
		hide_AI_choices();
		//for who is this done
		switch (GAME.actual_player)
		{
		case 1: {
			//find the form size with offset for proper center
			auto&& x_form_size = this->ClientSize.Width + this->back_to_menu_button->Location.X + this->back_to_menu_button->Size.Width;
			//key location to base the move
			auto&& x_pos_patching = this->start_patching_button->Location.X;
			//if to move
			if (x_pos_patching > x_form_size / 2) {
				//new location with same offset from the found center
				auto&& x_point_patching = (x_form_size / 2) - (this->ClientSize.Width - x_pos_patching);
				//y location is the same
				auto&& y_point_patching = this->undo_patching->Location.Y;
				//set the new location
				this->start_patching_button->Location = System::Drawing::Point(x_point_patching, y_point_patching);
				//same for other button
				auto&& x_point_skip = (x_form_size / 2) - (this->ClientSize.Width - this->skip_time_knobs_button->Location.X);
				this->skip_time_knobs_button->Location = System::Drawing::Point(x_point_skip, y_point_patching);
				auto&& x_point_look_patch = (x_form_size / 2) - (this->ClientSize.Width - this->look_at_patches_button->Location.X);
				this->look_at_patches_button->Location = System::Drawing::Point(x_point_look_patch, y_point_patching);

			}
			break;
		}
		case 2: {
			//find form size with offset for proper center
			auto&& x_form_size = this->ClientSize.Width + this->back_to_menu_button->Location.X + this->back_to_menu_button->Size.Width;
			//key location to base the move
			auto&& x_pos_patching = this->start_patching_button->Location.X;
			//if to move
			if (x_pos_patching < x_form_size / 2) {
				//keep the same offset as from the found center
				auto&& x_point_patching = this->ClientSize.Width - (x_form_size / 2 - x_pos_patching);
				//keep the same y location
				auto&& y_point_patching = this->undo_patching->Location.Y;
				this->start_patching_button->Location = System::Drawing::Point(x_point_patching, y_point_patching);
				//same for other buttons
				auto&& x_point_skip = this->ClientSize.Width - (x_form_size / 2 - this->skip_time_knobs_button->Location.X);
				this->skip_time_knobs_button->Location = System::Drawing::Point(x_point_skip, y_point_patching);
				auto&& x_point_look_patch = this->ClientSize.Width - (x_form_size / 2 - this->look_at_patches_button->Location.X);
				this->look_at_patches_button->Location = System::Drawing::Point(x_point_look_patch, y_point_patching);

			}
			break;
		}
		}
	}
		   //if current player is ai, hide buttons
	private: System::Void hide_AI_choices() {
		if (GAME.active_AI_player1 && GAME.actual_player == 1) {
			this->start_patching_button->Visible = false;
			this->start_patching_button->Enabled = false;
			this->skip_time_knobs_button->Visible = false;
			this->skip_time_knobs_button->Enabled = false;
			this->look_at_patches_button->Visible = false;
			this->look_at_patches_button->Enabled = false;
		}
		else if (GAME.active_AI_player2 && GAME.actual_player == 2) {
			this->start_patching_button->Visible = false;
			this->start_patching_button->Enabled = false;
			this->skip_time_knobs_button->Visible = false;
			this->skip_time_knobs_button->Enabled = false;
			this->look_at_patches_button->Visible = false;
			this->look_at_patches_button->Enabled = false;
		}
	}
		   //flag if ai is turned on, if turned on, get proper AI
	private: System::Void is_AI_on() {
		if (this->player1_ai_choice->Checked) {
			GAME.active_AI_player1 = true;
			if (this->player_1_greedy_man->Checked) {
				GAME.set_AI(greedy_space_man, 1);
			}
			else if (this->player_1_min_max_no_man->Checked) {
				GAME.set_AI(min_max_no_space_man, 1);
			}
			else if (this->player_1_min_max_man->Checked) {
				GAME.set_AI(min_max_space_man, 1);
			}
			else if (this->player_1_greedy_no_man->Checked) {
				GAME.set_AI(greedy_no_space_man, 1);
			}
			else if (this->player_1_min_max_free->Checked) {
				GAME.set_AI(min_max_free_space, 1);
			}
			else if (this->player_1_monte_carlo->Checked) {
				GAME.set_AI(monte_carlo_free_space, 1);
			}
			else if (this->player_1_random_ai->Checked) {
				GAME.set_AI(random_ai, 1);
			}
			else if (this->player_1_random_select->Checked) {
				GAME.set_AI(just_random_select_ai, 1);
			}
			else if (this->player_1_frequency_ai->Checked) {
				GAME.set_AI(frequency_ai, 1);
			}
			else
				GAME.set_AI(greedy_space_man, 1);
		}
		else {
			GAME.active_AI_player1 = false;
		}
		if (this->player2_ai_choice->Checked) {
			GAME.active_AI_player2 = true;
			if (this->player_2_greedy_man->Checked) {
				GAME.set_AI(greedy_space_man, 2);
			}
			else if (this->player_2_min_max_no_man->Checked) {
				GAME.set_AI(min_max_no_space_man, 2);
			}
			else if (this->player_2_min_max_man->Checked) {
				GAME.set_AI(min_max_space_man, 2);
			}
			else if (this->player_2_greedy_no_man->Checked) {
				GAME.set_AI(greedy_no_space_man, 2);
			}
			else if (this->player_2_min_max_free->Checked) {
				GAME.set_AI(min_max_free_space, 2);
			}
			else if (this->player_2_monte_carlo->Checked) {
				GAME.set_AI(monte_carlo_free_space, 2);
			}
			else if (this->player_2_random_ai->Checked) {
				GAME.set_AI(random_ai, 2);
			}
			else if (this->player_2_random_select->Checked) {
				GAME.set_AI(just_random_select_ai, 2);
			}
			else if (this->player_2_frequency_ai->Checked) {
				GAME.set_AI(frequency_ai, 2);
			}
			else
				GAME.set_AI(greedy_space_man, 2);
		}
		else {
			GAME.active_AI_player2 = false;
		}


	}

		   //progress the game 
	private: System::Void game_progress(bool skip) {
		//based on where was it called
		if (skip) { //skip time for knobs or ai, don't need to hide unless end of the game
			if (GAME.game_logic.game_end()) { //game end show who won
				show_players_data();
				GAME.save_game();
				who_won();
				this->additional_info->Text = "Congratulations.";
				this->skip_time_knobs_button->Visible = false;
				this->skip_time_knobs_button->Enabled = false;
				this->start_patching_button->Visible = false;
				this->start_patching_button->Enabled = false;
				this->look_at_patches_button->Visible = false;
				this->look_at_patches_button->Enabled = false;
			}
			else {
				get_actual_player();
				player_specific_control();
				show_players_data();
				free_1x1_patch_player();
				bonus_added();

			}
		}
		else {
			if (GAME.game_logic.game_end()) {
				show_players_data(); //Here ended without showing player data, 
				GAME.save_game();
				who_won();
				this->additional_info->Text = "Congratulations.";
				this->skip_time_knobs_button->Visible = false;
				this->skip_time_knobs_button->Enabled = false;
				this->start_patching_button->Visible = false;
				this->start_patching_button->Enabled = false;
				this->look_at_patches_button->Visible = false;
				this->look_at_patches_button->Enabled = false;
			}
			else {
				this->skip_time_knobs_button->Visible = true;
				this->skip_time_knobs_button->Enabled = true;
				this->start_patching_button->Visible = true;
				this->start_patching_button->Enabled = true;
				this->look_at_patches_button->Visible = true;
				this->look_at_patches_button->Enabled = true;
				this->additional_info->Text = "Welcome to patchwork, \npress skip to skip time, \nor start patching.";
				get_actual_player();
				player_specific_control();
				show_players_data();
				free_1x1_patch_player();
				bonus_added();

			}
		}
	}

		   //Prety blank surfice with only ai options
	private: System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//hide yourself and ai
		this->simulation_result->Visible = false;
		this->simulate_100_games->Visible = false;
		this->start_button->Visible = false;
		this->start_button->Enabled = false;
		this->player1_ai_choice->Visible = false;
		this->player1_ai_choice->Enabled = false;
		this->player2_ai_choice->Visible = false;
		this->player2_ai_choice->Enabled = false;
		this->groupBox1->Visible = false;
		this->groupBox2->Visible = false;
		//show the game options
		this->player1_blanket->Visible = true;
		this->player2_blanket->Visible = true;
		this->player_turn->Visible = true;
		this->start_patching_button->Visible = true;
		this->start_patching_button->Enabled = true;
		this->skip_time_knobs_button->Visible = true;
		this->skip_time_knobs_button->Enabled = true;
		this->back_to_menu_button->Visible = true;
		this->back_to_menu_button->Enabled = true;
		this->look_at_patches_button->Visible = true;
		this->look_at_patches_button->Enabled = true;
		//game settings
		is_AI_on();
		show_players_data();
		get_actual_player();
		player_specific_control();
		this->additional_info->Text = "Welcome to patchwork, \npress skip to skip time, \nor start patching";
		free_1x1_patch_player();
		bonus_added();
	}

		   //Move players Blankets to side.
	private: System::Void move_during_selection() {
		this->player1_blanket->Location = System::Drawing::Point(10, 55);
		this->player1_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->player2_blanket->Location = System::Drawing::Point(10, 225);
		this->player2_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

	}
		   //Unmove players Blankets to original place.
	private: System::Void unmove_during_selection() {
		this->player1_blanket->Location = System::Drawing::Point(141, 103);
		this->player1_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->player2_blanket->Location = System::Drawing::Point(631, 103);
		this->player2_blanket->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));

	}
		   //Move the menu and undo buttons to center
	private: System::Void move_menu_undo_trigger() {
		this->back_to_menu_button->Location = System::Drawing::Point(228, 289);
		this->undo_patching->Location = System::Drawing::Point(666, 289);
		this->undo_patching->Text = "Cancel\n(C)";
	}
		   //Unmove the menu and undo buttons to original position
	private: System::Void unmove_menu_undo_trigger() {
		this->back_to_menu_button->Location = System::Drawing::Point(13, 405);
		this->undo_patching->Location = System::Drawing::Point(145, 405);
		this->undo_patching->Text = "Undo\n(U)";
	}
		   //Simulate games between AIs if activated.
	private: System::Void simulate_100_games_Click(System::Object^ sender, System::EventArgs^ e) {
		//Check that the AIs are turned on
		if (this->player1_ai_choice->Checked && this->player2_ai_choice->Checked) {
			//Cound players wins
			int player_1_wins = 0;
			int player_2_wins = 0;
			//Hide button so that user may not request more simulations.
			this->simulate_100_games->Visible = false;
			//Simulate 100 games
			for (int i = 0; i < NUM_GENERATE_GAMES; i++) {
				GAME.new_game();
				is_AI_on();
				while (!GAME.game_logic.game_end()) {
					GAME.actual_player = (GAME.game_logic.whos_turn()) ? 1 : 2;
					if (GAME.actual_player == 1) {
						auto move = GAME.computer_AI_player1->make_move(GAME.game_logic.current_game_state(GAME.actual_player));
						GAME.game_logic.compact_action_evaluation(move);
					}
					else {
						auto move = GAME.computer_AI_player2->make_move(GAME.game_logic.current_game_state(GAME.actual_player));
						GAME.game_logic.compact_action_evaluation(move);

					}
					GAME.actual_player = (GAME.game_logic.whos_turn()) ? 1 : 2;
				}
				if (GAME.game_logic.who_won())
					player_1_wins++;
				else
					player_2_wins++;
				GAME.save_game();
			}
			this->simulate_100_games->Visible = true;
			//write down the results
			this->simulation_result->Text = gcnew System::String((GAME.computer_AI_player1->get_name() + "Player1 wins: " + std::to_string(player_1_wins) + " " +
				GAME.computer_AI_player2->get_name() + "Player2 wins: " + std::to_string(player_2_wins)).c_str());
			//Center the result
			int displace = this->simulation_result->Width / 2;
			int y_pos = this->simulation_result->Location.Y;
			int x_pos = this->simulate_100_games->Location.X + this->simulate_100_games->Width / 2;
			this->simulation_result->Location = System::Drawing::Point(x_pos - displace, y_pos);
			//display
			this->simulation_result->Visible = true;
			GAME.new_game();

		}
	}
		   //Move the index forward, from which are results looked on
	private: System::Void game_looking_next_Click(System::Object^ sender, System::EventArgs^ e) {
		GAME.game_look_index += 1;
		if (GAME.num_games <= NUM_GAMES_PAGE * (GAME.game_look_index + 1))
			this->game_looking_next->Visible = false;
		this->game_looking_back->Visible = true;
		show_seeds();
	}
		   //Move the index backward, from which are results looked on
	private: System::Void game_looking_back_Click(System::Object^ sender, System::EventArgs^ e) {
		GAME.game_look_index -= 1;
		if (GAME.game_look_index == 0)
			this->game_looking_back->Visible = false;
		this->game_looking_next->Visible = true;
		show_seeds();
	}
	};
}