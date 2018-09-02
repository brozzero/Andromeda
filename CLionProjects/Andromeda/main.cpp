#include <iostream>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>

#endif

#include "View.h"

class MyApp: public wxApp{
public:
    virtual bool OnInit();


};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    Image* img1=new Image(24,"test1");
    Image* img2=new Image(25,"test2");
    std::vector <Image*> test;
    test.push_back(img1);
    test.push_back(img2);
    std::cout<<test.size()<<std::endl;


    Model* model= new Model(test);
    auto controller=new Controller(model);
    auto view=new View (model,controller,NULL);
    view->Show(true);
    return true;
}