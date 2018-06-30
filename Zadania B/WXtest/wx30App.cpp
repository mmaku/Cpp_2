/***************************************************************
 * Name:      WXtestApp.cpp
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

#include "wx30App.h"
#include "wx30Main.h"

IMPLEMENT_APP(WXtestApp);

bool WXtestApp::OnInit()
{
    WXtestFrame* frame = new WXtestFrame(0L, _("wxWidgets Application Template"));

    frame->Show();

    return true;
}
