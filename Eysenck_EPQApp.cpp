/***************************************************************
 * Name:      Eysenck_EPQApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Gordieiev Artem (gordieiev.artem@gmail.com)
 * Created:   2018-03-27
 * Copyright: Gordieiev Artem (https://github.com/)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Eysenck_EPQApp.h"

//(*AppHeaders
#include "Eysenck_EPQMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Eysenck_EPQApp);

bool Eysenck_EPQApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Eysenck_EPQFrame* Frame = new Eysenck_EPQFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
