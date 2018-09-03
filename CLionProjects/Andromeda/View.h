//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_VIEW_H
#define ANDROMEDA_VIEW_H

#include <wx/timer.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include "Controller.h"


class View : public wxFrame, public Observer
{
private:
    Controller* controller;
    Model* model;
    wxBoxSizer* View_sizer;

protected:
    wxStaticBitmap* Image;
    wxTextCtrl* Counter;
    wxPanel* Button_panel;
    wxButton* back_button;
    wxButton* play_button;
    wxButton* stop_button;
    wxButton* next_button;
    wxTimer timer;



    // Virtual event handlers, overide them in your derived class
    virtual void onPreviousButtonClick( wxCommandEvent& event ) ;
    virtual void OnPlayButtonClick( wxCommandEvent& event ) ;
    virtual void OnPauseButtonClick( wxCommandEvent& event );
    virtual void OnNextButtonClick( wxCommandEvent& event );
    virtual void OnNextButtonClick( wxTimerEvent& event );
    virtual void update();


public:

    View(Model* model ,Controller* c, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 495,364 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~View();

};



#endif //ANDROMEDA_VIEW_H
