#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>

#endif

#include "View.h"
#include "Preview.h"

class MyApp: public wxApp{
public:
    virtual bool OnInit();


};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Model* model= new Model();




    auto controller=new Controller(model);
    auto view=new View (model,controller,NULL);
    view->Show(true);
    Preview* preview=new Preview(model,NULL);
    preview->Show(true);
    return true;
}