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
            idMenuAbout,
            idMenuName,
            idMenuShowName
        };
        wxString name;

        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnName(wxCommandEvent& event);
        void OnShowName(wxCommandEvent& event);

        DECLARE_EVENT_TABLE()
};


#endif // wx30MAIN_H
