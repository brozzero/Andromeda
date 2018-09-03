//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_MODEL_H
#define ANDROMEDA_MODEL_H


#include <vector>
#include <list>
#include <wx/chartype.h>
#include <wx/memory.h>
#include "Subject.h"
#include "Image.h"

class Model:public Subject {
private:
    //container di immagini
    std::vector<wxString> playlist;
    int size, cont;
    std::list<Observer*> observers;
    wxString directory;
public:
    const wxString &getDirectory() const;

    void setDirectory( wxString &directory);


public:
    Model();

    int getSize() const;

    int getCont() const;

    std::vector<wxString>* getPlaylist() ;

    void setCont(int cont);

    virtual void  notify ();
    virtual void  subscribe(Observer* observer);
    virtual void  unsubscribe(Observer* observer);

    virtual ~Model();

    void setSize(int size);


};


#endif //ANDROMEDA_MODEL_H
