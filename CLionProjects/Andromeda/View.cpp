//
// Created by manuel on 01/09/18.
//

#include "View.h"

View::View(Model* model,Controller* c, wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) :model(model), controller(c),wxFrame( parent, id, title, pos, size, style )
{
    model->subscribe(this);
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* View_sizer;
    View_sizer = new wxBoxSizer( wxVERTICAL );

    Image = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("/home/manuel/Scaricati/index.jpeg"), wxBITMAP_TYPE_ANY ), wxPoint( -1,-1 ), wxDefaultSize, 0 );
    Image->SetMaxSize( wxSize( -1,300 ) );

    View_sizer->Add( Image, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
    wxString wxIntString= wxString::Format(wxT("%i/%i"),model->getCont(),model->getSize());
    Counter = new wxTextCtrl( this, wxID_ANY,wxIntString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    Counter->SetMaxSize( wxSize( 50,20 ) );

    View_sizer->Add( Counter, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

    Button_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* Button_sizer;
    Button_sizer = new wxBoxSizer( wxHORIZONTAL );

    back_button = new wxButton( Button_panel, wxID_ANY, wxT("Previous"), wxDefaultPosition, wxDefaultSize, 0 );
    Button_sizer->Add( back_button, 0, wxALL, 5 );

    play_button = new wxButton( Button_panel, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
    Button_sizer->Add( play_button, 0, wxALL, 5 );

    stop_button = new wxButton( Button_panel, wxID_ANY, wxT("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
    Button_sizer->Add( stop_button, 0, wxALL, 5 );

    next_button = new wxButton( Button_panel, wxID_ANY, wxT("Next"), wxDefaultPosition, wxDefaultSize, 0 );
    Button_sizer->Add( next_button, 0, wxALL, 5 );


    Button_panel->SetSizer( Button_sizer );
    Button_panel->Layout();
    Button_sizer->Fit( Button_panel );
    View_sizer->Add( Button_panel, 1, wxEXPAND | wxALL, 5 );


    this->SetSizer( View_sizer );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    back_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::onPreviousButtonClick), NULL, this );
    play_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnPlayButtonClick) , NULL, this );
    stop_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnPauseButtonClick), NULL, this );
    next_button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnNextButtonClick), NULL, this );
}

View::~View()
{
    // Disconnect Events
    back_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::onPreviousButtonClick ), NULL, this );
    play_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnPlayButtonClick ), NULL, this );
    stop_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnPauseButtonClick ), NULL, this );
    next_button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( View::OnNextButtonClick ), NULL, this );
    model->unsubscribe(this);
}

void View::onPreviousButtonClick(wxCommandEvent &event) {
    controller->indietro();

}

void View::OnPlayButtonClick(wxCommandEvent &event) {
    controller->play();

}

void View::OnPauseButtonClick(wxCommandEvent &event) {
    controller->stop();
}

void View::OnNextButtonClick(wxCommandEvent &event) {
    controller->avanti();

}

void View::update() {
int value = model->getCont();
    wxString wxIntString= wxString::Format(wxT("%i/%i"),value,model->getSize());
    Counter->ChangeValue(wxIntString);

}

