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
    EVT_MENU(idMenuName, wx30Frame::OnName)
    EVT_MENU(idMenuShowName, wx30Frame::OnShowName)
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

    wxMenu* userMenu = new wxMenu(_T(""));
    userMenu->Append(idMenuName, _("&Name"), _("Provide your name"));
    userMenu->AppendSeparator();
    userMenu->Append(idMenuShowName, _("&Show Name"), _("Shows you name"));
    mbar->Append(userMenu, _("&User"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


wx30Frame::~wx30Frame()
{
}

void wx30Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wx30Frame::OnQuit(wxCommandEvent &event)
{
    int answer = 0;
    if(name == "")
        answer = wxMessageBox(_("Quit program?"), _("Confirm"), wxYES_NO);
    else
        answer = wxMessageBox(name + ", do You want to quit program?", "Confirm", wxYES_NO);

    if (answer == wxYES)
        Destroy();

}

void wx30Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wx30Frame::OnShowName(wxCommandEvent &event)
{
    if(name == "")
        wxMessageBox(_("Anonymous"), _("Welcome to...!"));
    else
        wxMessageBox(name, _("Welcome anonymous!"));
}

void wx30Frame::OnName(wxCommandEvent &event)
{
    name = wxGetTextFromUser(wxT("Your name:"), wxT("Name"));

    if(name == "")
        SetStatusText(_("Hello Anonymous!"),0);
    else
        SetStatusText(_("Hello ") + name + _("!"),0);
}
