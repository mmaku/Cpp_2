/***************************************************************
 * Name:      wx30Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2014-01-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wx30Main.h"

#include <sstream>

#include "arithm.hpp"

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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

BEGIN_EVENT_TABLE(wx30Frame, wxFrame)
    EVT_CLOSE(wx30Frame::OnClose)
    EVT_MENU(idMenuQuit, wx30Frame::OnQuit)
    EVT_MENU(idMenuAbout, wx30Frame::OnAbout)

    EVT_BUTTON(0, wx30Frame::OnButton)
    EVT_BUTTON(1, wx30Frame::OnButton)
    EVT_BUTTON(2, wx30Frame::OnButton)
    EVT_BUTTON(3, wx30Frame::OnButton)
    EVT_BUTTON(4, wx30Frame::OnButton)
    EVT_BUTTON(5, wx30Frame::OnButton)
    EVT_BUTTON(6, wx30Frame::OnButton)
    EVT_BUTTON(7, wx30Frame::OnButton)
    EVT_BUTTON(8, wx30Frame::OnButton)
    EVT_BUTTON(9, wx30Frame::OnButton)
END_EVENT_TABLE()

wx30Frame::wx30Frame(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Calculator"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

    wxPanel* panel = new wxPanel(this);

    wxBoxSizer* vsizer = new wxBoxSizer(wxVERTICAL);
//wxBoxSizer* hsizer = new wxBoxSizer(wxHORIZONTAL);

    display_ = new wxTextCtrl(panel,wxID_ANY);
    display_->SetEditable(false); //tutaj blokuje sie mozliwosc edycji z zewnatrz

    vsizer -> Add(display_,wxSizerFlags(0).Expand());

    gs_ = new wxGridSizer(5,4,0,0); //siatka, te zera to odstepy h i v

    wxButton* button_0 = new wxButton(panel,0,wxString::FromUTF8("0"));//,wxDefaultPosition,wxDefaultSize,0,wxDefaultValidator,"0");
    wxButton* button_7 = new wxButton(panel,7,wxString::FromUTF8("7"));//konstruktor buttona, aby przeniesc dodatkowe info, np string?
    wxButton* button_8 = new wxButton(panel,8,wxString::FromUTF8("8"));
    wxButton* button_9 = new wxButton(panel,9,wxString::FromUTF8("9"));
    wxButton* button_6 = new wxButton(panel,6,wxString::FromUTF8("6"));
    wxButton* button_5 = new wxButton(panel,5,wxString::FromUTF8("5"));
    wxButton* button_4 = new wxButton(panel,4,wxString::FromUTF8("4"));
    wxButton* button_3 = new wxButton(panel,3,wxString::FromUTF8("3"));
    wxButton* button_2 = new wxButton(panel,2,wxString::FromUTF8("2"));
    wxButton* button_1 = new wxButton(panel,1,wxString::FromUTF8("1"));

    wxButton* clear_evr = new wxButton(panel,wxID_ANY,wxString::FromUTF8("CE"));
    clear_evr->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        display_->Clear();
        arithmetics="";
    });

    wxButton* clearC = new wxButton(panel,wxID_ANY,wxString::FromUTF8("C"));
    clearC->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        if(!arithmetics.empty())
        {
            arithmetics.erase(arithmetics.end()-1);
            display_->Clear();
            *display_<<arithmetics;
        }
    });

    wxButton* empty_1 = new wxButton(panel,wxID_ANY,wxString::FromUTF8("A"));
    empty_1->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        display_->Clear();
        *display_<<arithmetics;
    });

    wxButton* empty_2 = new wxButton(panel,wxID_ANY,wxString::FromUTF8(""));
    empty_2->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
    });

    wxButton* slash = new wxButton(panel,wxID_ANY,wxString::FromUTF8("/"));
    slash->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        arithmetics+="/";
        *display_<<"/";
    });

    wxButton* multi = new wxButton(panel,wxID_ANY,wxString::FromUTF8("*"));
    multi->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        arithmetics+="*";
        *display_<<"*";
    });

    wxButton* minusM = new wxButton(panel,wxID_ANY,wxString::FromUTF8("-"));
    minusM->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        arithmetics+="-";
        *display_<<"-";
    });

    wxButton* plusP = new wxButton(panel,wxID_ANY,wxString::FromUTF8("+"));
    plusP->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        arithmetics+="+";
        *display_<<"+";
    });

    wxButton* dot = new wxButton(panel,wxID_ANY,wxString::FromUTF8("."));
    dot->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        arithmetics+=".";
        *display_<<".";
    });

    wxButton* equalE = new wxButton(panel,wxID_ANY,wxString::FromUTF8("="));
    equalE->Bind(wxEVT_BUTTON, [=](wxCommandEvent&)
    {
        display_->Clear();
        std::string result = Arithmetics(arithmetics);
        arithmetics.clear();
        arithmetics+=result;
        *display_<<result;
    });

    gs_->Add(clear_evr, 0, wxEXPAND);
    gs_->Add(clearC, 0, wxEXPAND);
    gs_->Add(empty_1, 0, wxEXPAND);
    gs_->Add(empty_2, 0, wxEXPAND);
    gs_->Add(button_7, 0, wxEXPAND);
    gs_->Add(button_8, 0, wxEXPAND);
    gs_->Add(button_9, 0, wxEXPAND);
    gs_->Add(slash, 0, wxEXPAND);
    gs_->Add(button_4, 0, wxEXPAND);
    gs_->Add(button_5, 0, wxEXPAND);
    gs_->Add(button_6, 0, wxEXPAND);
    gs_->Add(multi, 0, wxEXPAND);
    gs_->Add(button_1, 0, wxEXPAND);
    gs_->Add(button_2, 0, wxEXPAND);
    gs_->Add(button_3, 0, wxEXPAND);
    gs_->Add(minusM, 0, wxEXPAND);
    gs_->Add(button_0, 0, wxEXPAND);
    gs_->Add(dot, 0, wxEXPAND);
    gs_->Add(equalE, 0, wxEXPAND);
    gs_->Add(plusP, 0, wxEXPAND);

    vsizer->Add(gs_, 1, wxEXPAND);

    panel -> SetSizer(vsizer);
    vsizer -> SetSizeHints(this); //okienko jest dopasowane do minimalnych rozmiarow
}

wx30Frame::~wx30Frame()
{}

void wx30Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wx30Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void wx30Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Calculator"));
}

void wx30Frame::OnButton(wxCommandEvent &event)
{
    std::ostringstream ss;
    ss << event.GetId();

    arithmetics+=ss.str(); //jak w evencie odwolac sie do buttona?
    *display_<<event.GetId(); //jakies uogolnienie na GetString z buttona?
}
