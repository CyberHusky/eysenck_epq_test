/***************************************************************
 * Name:      Eysenck_EPQMain.h
 * Purpose:   Defines Application Frame
 * Author:    Gordieiev Artem (gordieiev.artem@gmail.com)
 * Created:   2018-03-27
 * Copyright: Gordieiev Artem (https://github.com/)
 * License:
 **************************************************************/

#ifndef EYSENCK_EPQMAIN_H
#define EYSENCK_EPQMAIN_H

//(*Headers(Eysenck_EPQFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
//*)

class Eysenck_EPQFrame: public wxFrame
{
    public:

        Eysenck_EPQFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Eysenck_EPQFrame();

    private:

        //(*Handlers(Eysenck_EPQFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void Draw_qw_func(bool);
        void OnClose(wxCloseEvent& event);
        void OnSaveResults(wxCommandEvent& event);
        void OnTextCtrl2TextEnter(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(Eysenck_EPQFrame)
        static const long ID_STATICTEXT4;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_PANEL2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT5;
        static const long ID_STATICBITMAP1;
        static const long ID_PANEL1;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idSaveFile;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Eysenck_EPQFrame)
        wxTextCtrl* TextCtrl3;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText1;
        wxPanel* Panel2;
        wxStaticText* StaticText3;
        wxMenuItem* MenuItem3;
        wxPanel* Panel3;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxStaticBitmap* StaticBitmap1;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // EYSENCK_EPQMAIN_H
