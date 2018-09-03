//
// Created by manuel on 03/09/18.
//

#ifndef ANDROMEDA_PREVIEW_H
#define ANDROMEDA_PREVIEW_H

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/filepicker.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <vector>
#include <string>
#include "View.h"

class Preview : public wxFrame
{
private:

    Model* model;
protected:
    wxStaticText* Instruction;
    wxFilePickerCtrl* PickerButton;
    wxPanel* Panel;
    wxButton* next_photo_button;
    wxButton* start_button;
    wxBoxSizer* MainSizer;

    // Virtual event handlers, overide them in your derived class
    virtual void upload( wxCommandEvent& event );
    virtual void start( wxCommandEvent& event );


public:

    Preview(Model* m, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 394,179 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~Preview();

};


#endif //ANDROMEDA_PREVIEW_H
