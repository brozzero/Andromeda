//
// Created by manuel on 03/09/18.
//

#include "Preview.h"
#include "Model.h"
#include "Controller.h"
#include "View.h"

Preview::Preview(Model* m, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) :model(m), wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );


    MainSizer = new wxBoxSizer( wxVERTICAL );

    Instruction = new wxStaticText( this, wxID_ANY, wxT("Please, choose your photos"), wxDefaultPosition, wxDefaultSize, 0 );
    Instruction->Wrap( -1 );
    Instruction->SetFont( wxFont( 10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT, false, wxEmptyString ) );
    Instruction->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );

    MainSizer->Add( Instruction, 0, wxALL, 18 );

    PickerButton = new wxFilePickerCtrl( this, wxID_ANY, wxT(" "), wxT("Select a file"), wxT("*.jpeg"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST|wxFLP_USE_TEXTCTRL );
    PickerButton->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

    MainSizer->Add( PickerButton, 0, wxALL|wxEXPAND, 5 );

    Panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* ButtonsSizer;
    ButtonsSizer = new wxBoxSizer( wxHORIZONTAL );

    next_photo_button = new wxButton( Panel, wxID_ANY, wxT("Upload Photo"), wxDefaultPosition, wxDefaultSize, 0 );
    next_photo_button->SetMinSize( wxSize( 180,100 ) );

    ButtonsSizer->Add( next_photo_button, 0, wxALL, 5 );

    start_button = new wxButton( Panel, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
    start_button->SetDefault();
    start_button->SetMinSize( wxSize( 185,100 ) );

    ButtonsSizer->Add( start_button, 0, wxALL, 5 );


    Panel->SetSizer( ButtonsSizer );
    Panel->Layout();
    ButtonsSizer->Fit( Panel );
    MainSizer->Add( Panel, 1, wxEXPAND | wxALL, 5 );


    this->SetSizer( MainSizer );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    next_photo_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Preview::upload ), NULL, this );
    start_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Preview::start ), NULL, this );
}

Preview::~Preview()
{
    // Disconnect Events
    next_photo_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Preview::upload ), NULL, this );
    start_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Preview::start ), NULL, this );

}

void Preview::upload(wxCommandEvent &event) {

    wxString value=PickerButton->GetTextCtrlValue();
    model->getPlaylist()->push_back(value);

}

void Preview::start(wxCommandEvent &event) {
    model->setDirectory(model->getPlaylist()->front());
    model->setSize(model->getPlaylist()->size());

    delete this;
}



