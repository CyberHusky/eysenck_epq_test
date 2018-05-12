/***************************************************************
 * Name:      Eysenck_EPQMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Gordieiev Artem (gordieiev.artem@gmail.com)
 * Created:   2018-03-27
 * Copyright: Gordieiev Artem (https://github.com/)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Eysenck_EPQMain.h"
#include <wx/msgdlg.h>

//My includes
#include <stdio.h>
#include <wx/strconv.h>
<<<<<<< Updated upstream
#include <ctime>
=======
#include <setup.h>
>>>>>>> Stashed changes

// --- My Variables ---
#define MAX_QW          101
#define PSY_LEN_YES     13
#define PSY_LEN_NO      12
#define EXTR_LEN_YES    21
#define EXTR_LEN_NO     4
#define NEIR_LEN_YES    25
#define TRUE_LEN_YES    8
#define TRUE_LEN_NO     17

char c_qw_line[400];        // Buffer for questions
char c_status_bar[200];     // Buffer for statusbar message
char c_results_bar[1000];
int  i_button_count = 1;    // Number of current questions
//char *temperament;
bool answer_mas[101];       // Var for answers
bool ans;

char temperament[9][100] = {"Меланхолик", "Меланхолически-холерический", "Холерик", "Флегматико-меланхолический", "Нормальный", "Холерически-сангвинический", "Флегматик", "Сангвинически-флегматический", "Сангвиник"};
int temperament_num;

/*
            temperament = "Меланхолик";
            temperament = "Меланхолически-холерический";
            temperament = "Холерик";
            temperament = "Флегматико-меланхолический";
            temperament = "Нормальный";
             temperament = "Холерически-сангвинический";
            temperament = "Флегматик";
            temperament = "Сангвинически-флегматический";
            temperament = "Сангвиник";
*/

int bal_psyho       = 0;
int bal_extra_into  = 0;
int bal_neiro       = 0;
int bal_true        = 0;

int qwe_psyho_yes[]      =   {14, 23, 27, 31, 35, 47, 51, 55, 71, 85, 88, 93, 97};
int qwe_psyho_no[]       =   {2 , 6 , 9 , 11, 19, 39, 43, 59, 63, 67, 78, 100};
int qwe_extra_into_yes[] =   {1 , 5 , 10, 15, 18, 26, 34, 38, 42, 50, 54, 58, 62, 66, 70, 74, 77, 81, 90, 92, 96};
int qwe_extra_into_no[]  =   {22, 30, 46, 84};
int qwe_neiro_yes[]      =   {3 , 7 , 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 75, 79, 83, 86, 89, 94, 98};
int qwe_true_yes[]       =   {13, 21, 33, 37, 61, 73, 87, 99};
int qwe_true_no[]        =   {4,  8,  17, 25, 29, 41, 45, 49, 53, 57, 65, 69, 76, 80, 82, 91, 95};


FILE* inpf;                 // Var for Load file with questions




//(*InternalHeaders(Eysenck_EPQFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Eysenck_EPQFrame)
const long Eysenck_EPQFrame::ID_STATICTEXT4 = wxNewId();
const long Eysenck_EPQFrame::ID_PANEL3 = wxNewId();
const long Eysenck_EPQFrame::ID_STATICTEXT3 = wxNewId();
const long Eysenck_EPQFrame::ID_BUTTON2 = wxNewId();
const long Eysenck_EPQFrame::ID_BUTTON3 = wxNewId();
const long Eysenck_EPQFrame::ID_PANEL2 = wxNewId();
const long Eysenck_EPQFrame::ID_TEXTCTRL1 = wxNewId();
const long Eysenck_EPQFrame::ID_TEXTCTRL2 = wxNewId();
const long Eysenck_EPQFrame::ID_TEXTCTRL3 = wxNewId();
const long Eysenck_EPQFrame::ID_STATICTEXT1 = wxNewId();
const long Eysenck_EPQFrame::ID_STATICTEXT2 = wxNewId();
const long Eysenck_EPQFrame::ID_STATICTEXT5 = wxNewId();
const long Eysenck_EPQFrame::ID_STATICBITMAP1 = wxNewId();
const long Eysenck_EPQFrame::ID_PANEL1 = wxNewId();
const long Eysenck_EPQFrame::ID_BUTTON1 = wxNewId();
const long Eysenck_EPQFrame::idMenuQuit = wxNewId();
const long Eysenck_EPQFrame::idSaveFile = wxNewId();
const long Eysenck_EPQFrame::idMenuAbout = wxNewId();
const long Eysenck_EPQFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Eysenck_EPQFrame,wxFrame)
    //(*EventTable(Eysenck_EPQFrame)
    //*)
END_EVENT_TABLE()

Eysenck_EPQFrame::Eysenck_EPQFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Eysenck_EPQFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(619,357));
    SetBackgroundColour(wxColour(255,255,255));
    Panel3 = new wxPanel(this, ID_PANEL3, wxPoint(16,16), wxSize(592,264), wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel3->Hide();
    Panel3->SetBackgroundColour(wxColour(255,255,255));
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT4, _("Results"), wxPoint(40,32), wxSize(512,136), wxST_NO_AUTORESIZE|wxALIGN_LEFT, _T("ID_STATICTEXT4"));
    Panel2 = new wxPanel(this, ID_PANEL2, wxPoint(16,16), wxSize(592,216), wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->Hide();
    Panel2->SetBackgroundColour(wxColour(255,255,255));
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Questions is here"), wxPoint(112,24), wxSize(384,128), wxST_NO_AUTORESIZE|wxALIGN_CENTRE|wxNO_BORDER, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    Button2 = new wxButton(Panel2, ID_BUTTON2, _("Да"), wxPoint(184,160), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button3 = new wxButton(Panel2, ID_BUTTON3, _("Нет"), wxPoint(320,160), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(16,16), wxSize(592,216), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(255,255,255));
    Panel1->SetHelpText(_("11"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,56), wxSize(328,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(8,112), wxSize(176,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(8,168), wxSize(176,24), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->Disable();
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Ваше имя:"), wxPoint(8,40), wxSize(176,14), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Ваш день рождения:"), wxPoint(8,96), wxSize(176,14), 0, _T("ID_STATICTEXT2"));
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Сегодняшняя дата:"), wxPoint(8,152), wxSize(136,14), 0, _T("ID_STATICTEXT5"));
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/artem/Bitbucket2/eysenck_epq/Logo_ru.jpg")).Rescale(wxSize(152,96).GetWidth(),wxSize(152,96).GetHeight())), wxPoint(424,72), wxSize(152,96), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Далее..."), wxPoint(224,288), wxSize(128,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem3 = new wxMenuItem(Menu1, idSaveFile, _("Save as txt...\tctrl-s"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem3->Enable(false);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnButton3Click);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnTextCtrl2Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnQuit);
    Connect(idSaveFile,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnSaveResults);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Eysenck_EPQFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&Eysenck_EPQFrame::OnClose);
    //*)




    // --- Code for time ---
    time_t now = time(0);
//    char* dt = ctime(&now);
/*
    wxString date(dt, wxConvUTF8);
    TextCtrl3 -> AppendText( date );
*/
    //int i = strlen(dt);
    char s[40];
    struct tm *u;
    u = localtime(&now);
    strftime(s, 40, "%d.%m.%Y %H:%M:%S ", u);

    wxString date(s, wxConvUTF8);
    TextCtrl3 -> AppendText( date );
}

Eysenck_EPQFrame::~Eysenck_EPQFrame()
{
    //(*Destroy(Eysenck_EPQFrame)
    //*)

}

void Eysenck_EPQFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Eysenck_EPQFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = _("Program maked by Gordieiev Artem, PhD, on BIKAM department.\nSite: www.bikam.nau.edu.ua\ne-mail: gordieiev.artem@gmail.com");
    wxMessageBox(msg, _("Group recruiting..."));
}

void Eysenck_EPQFrame::OnButton1Click(wxCommandEvent& event)
{

    Panel1 -> Hide();
    Panel2 -> Show();

    Button1 -> Hide();

    //c_status_bar = "Your test has started! Questions" + (char)button_count + "of 101";

    snprintf(c_status_bar, sizeof c_status_bar, "Your test has started! Questions %i of 101", i_button_count);
    wxString foo(c_status_bar, wxConvUTF8);
    StatusBar1 -> PushStatusText(foo);

// Open file with questions

    //FILE* inpf = fopen("Tests_qw_Aizenk", "r");
    inpf = fopen("Tests_qw_Aizenk", "r");

    if (inpf == NULL)
    {
        wxString foo( _("Open file error! File is dissmissed!") ); // make a message to StatusBar
        StatusBar1 -> PushStatusText(foo);
    }

    fgets(c_qw_line, sizeof c_qw_line, inpf);

    wxString mystring(c_qw_line, wxConvUTF8);

    StaticText3 -> SetLabel(mystring);


    i_button_count++;

}




// ---- YES BUTTON ----
void Eysenck_EPQFrame::OnButton2Click(wxCommandEvent& event)
{
ans = true;
Draw_qw_func(ans);
answer_mas[i_button_count - 1] = ans;

}



// ---- NO BUTTON ----
void Eysenck_EPQFrame::OnButton3Click(wxCommandEvent& event)
{
ans = false;
Draw_qw_func(ans);
answer_mas[i_button_count - 1] = ans;

}



void Eysenck_EPQFrame::Draw_qw_func(bool ans)
{
    fgets(c_qw_line, sizeof c_qw_line, inpf);
    wxString mystring(c_qw_line, wxConvUTF8);
    StaticText3 -> SetLabel(mystring);



    snprintf(c_status_bar, sizeof c_status_bar, "Your test has started! Questions %i of 101", i_button_count);
    wxString foo(c_status_bar, wxConvUTF8);
    StatusBar1 -> PushStatusText(foo);


    if(ans == true)
    {
        // Psyho
        for (int i = 0; i < PSY_LEN_YES; i++)
        {
            if (i_button_count == qwe_psyho_yes[i])
            {
                bal_psyho++;
            }
        }


        // Extra-intro
        for (int i = 0; i < EXTR_LEN_YES; i++)
        {
            if (i_button_count == qwe_extra_into_yes[i])
            {
                bal_extra_into++;
            }
        }

        //Neiro
        for (int i = 0; i < NEIR_LEN_YES; i++)
        {
            if (i_button_count == qwe_neiro_yes[i])
            {
                bal_neiro++;
            }
        }

        //True
        for (int i = 0; i < TRUE_LEN_YES; i++)
        {
            if (i_button_count == qwe_true_yes[i])
            {
                bal_true++;
            }
        }

    }
    else
    {

        // Psyho
        for (int i = 0; i < PSY_LEN_NO; i++)
        {
            if (i_button_count == qwe_psyho_no[i])
            {
                bal_psyho++;
            }
        }

        // Extra-intro
        for (int i = 0; i < EXTR_LEN_NO; i++)
        {
            if (i_button_count == qwe_extra_into_no[i])
            {
                bal_extra_into++;
            }
        }

        // True
        for (int i = 0; i < TRUE_LEN_NO; i++)
        {
            if (i_button_count == qwe_true_no[i])
            {
                bal_true++;
            }
        }

<<<<<<< Updated upstream
    }

// -------


=======

>>>>>>> Stashed changes

    /**
    Results
    */
    if(i_button_count == MAX_QW + 1)
    {
        fclose(inpf);
        Panel2 -> Hide();
        Panel3 -> Show();


        StatusBar1 -> PushStatusText( _("Congratulation! You have passed the test!") );


        if (bal_extra_into < 7 && bal_neiro > 16)
        {
            temperament_num = 0;
            //temperament = "Меланхолик";
        }
        else if (bal_extra_into >= 7 && bal_extra_into <= 15 && bal_neiro > 16)
        {
            temperament_num = 1;
            //temperament = "Меланхолически-холерический";
        }
        else if (bal_extra_into > 15 && bal_neiro > 16)
        {
            temperament_num = 2;
            //temperament = "Холерик";
        }
        else if (bal_extra_into < 7 && bal_neiro >= 8 && bal_neiro <= 16)
        {
            temperament_num = 3;
            //temperament = "Флегматико-меланхолический";
        }
        else if (bal_extra_into >= 7 && bal_extra_into <= 15 && bal_neiro >= 8 && bal_neiro <= 16)
        {
            temperament_num = 4;
            //temperament = "Нормальный";
        }
        else if (bal_extra_into > 15 && bal_neiro >= 8 && bal_neiro <= 16)
        {
            temperament_num = 5;
            //temperament = "Холерически-сангвинический";
        }
        else if (bal_extra_into < 7 && bal_neiro < 8)
        {
            temperament_num = 6;
            //temperament = "Флегматик";
        }
        else if (bal_extra_into >= 7 && bal_extra_into <= 15 && bal_neiro < 8)
        {
            temperament_num = 7;
            //temperament = "Сангвинически-флегматический";
        }
        else if (bal_extra_into > 15 && bal_neiro < 8)
        {
            temperament_num = 8;
            //temperament = "Сангвиник";
        }




        snprintf(c_results_bar, sizeof c_results_bar,
                 "---- Ваш результат: ----\nПсихотизм: %i\nЭкстраверсия-интроверсия: %i\nНейротизм: %i\nПравдивость: %i\nТип темперамента: %s",
                 bal_psyho, bal_extra_into, bal_neiro, bal_true, temperament[temperament_num]);
        wxString foo(c_results_bar, wxConvUTF8);
        StaticText4 -> SetLabel(foo);


    }


    if (i_button_count == 8)
    {
        i_button_count = 100;
    }


    i_button_count++;

    /**
    *
    * After results
    *
    */
    MenuItem3 -> Enable(); // Enabel menu for save result into file

}



void Eysenck_EPQFrame::OnClose(wxCloseEvent& event)
{
    Close();
}



/**

--- Trash ---

*/

/*
int length_mas(int mas[])
{
    int N = sizeof(mas)/sizeof(mas[0]);
    return N;
}
*/

void Eysenck_EPQFrame::OnSaveResults(wxCommandEvent& event)
{
    /*
wxFileDialog *saveFileDialog = new wxFileDialog(this);
if (saveFileDialog->ShowModal() == wxID_OK){
wxString fileName = saveFileDialog->GetPath();
}
*/
/*
    wxFileDialog
        saveFileDialog(this, _("Save XYZ file"), "", "");
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
*/
    // save the current contents in the file;
    // this can be done with e.g. wxWidgets output streams:
    /*
    wxFileOutputStream output_stream(saveFileDialog.GetPath());
    if (!output_stream.IsOk())
    {
        wxLogError("Cannot save current contents in file '%s'.", saveFileDialog.GetPath());
        return;
    }
*/


}

void Eysenck_EPQFrame::OnTextCtrl2TextEnter(wxCommandEvent& event)
{   // Not used for now
}

void Eysenck_EPQFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
    wxString str = TextCtrl2->GetValue();
//    char *birth = str.c_str();








    //StatusBar1 -> PushStatusText(str); // for testing
}
