/***************************************************************
 * Name:      TESTUJApp.cpp
 * Purpose:   Code for Application Class
 * Author:    MM (--)
 * Created:   2015-01-10
 * Copyright: MM (--)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "TESTUJApp.h"
#include "TESTUJMain.h"

IMPLEMENT_APP(TESTUJApp);

bool TESTUJApp::OnInit()
{
    TESTUJFrame* frame = new TESTUJFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
