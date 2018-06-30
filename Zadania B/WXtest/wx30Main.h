/***************************************************************
 * Name:      WXtestMain.h
 * Purpose:   Defines Application Frame
 * Author:    MM (--)
 * Created:   2015-01-10
 * Copyright: MM (--)
 * License:
 **************************************************************/

#ifndef WXTESTMAIN_H
#define WXTESTMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx30App.h"

class WXtestFrame: public wxFrame
{
    public:
        WXtestFrame(wxFrame *frame, const wxString& title);
        ~WXtestFrame();
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


#endif // WXTESTMAIN_H
