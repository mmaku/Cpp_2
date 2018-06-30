/***************************************************************
 * Name:      wx30Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2014-01-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef wx30MAIN_H
#define wx30MAIN_H

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx30App.h"

class wx30Frame: public wxFrame
{
public:
    wx30Frame(wxFrame *frame, const wxString& title);
    ~wx30Frame();
private:
    enum
    {
        idMenuQuit = 1000,
        idMenuAbout
    };
    void OnClose(wxCloseEvent& event);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnButton(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()

    wxTextCtrl* display_;
    wxGridSizer* gs_;
    std::string arithmetics;
};

#endif // wx30MAIN_H
