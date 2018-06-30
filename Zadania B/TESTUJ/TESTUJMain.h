/***************************************************************
 * Name:      TESTUJMain.h
 * Purpose:   Defines Application Frame
 * Author:    MM (--)
 * Created:   2015-01-10
 * Copyright: MM (--)
 * License:
 **************************************************************/

#ifndef TESTUJMAIN_H
#define TESTUJMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "TESTUJApp.h"

class TESTUJFrame: public wxFrame
{
    public:
        TESTUJFrame(wxFrame *frame, const wxString& title);
        ~TESTUJFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // TESTUJMAIN_H
