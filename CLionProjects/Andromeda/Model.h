//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_MODEL_H
#define ANDROMEDA_MODEL_H


#include <vector>
#include <list>
#include "Subject.h"
#include "Image.h"

class Model:public Subject {
private:
    //container di immagini
    std::vector<Image*> playlist;
    int size, cont;
    std::list<Observer*> observers;


public:
    Model(const std::vector<Image *> &playlist);

    int getSize() const;

    int getCont() const;

    void setCont(int cont);

    virtual void  notify ();
    virtual void  subscribe(Observer* observer);
    virtual void  unsubscribe(Observer* observer);

    virtual ~Model();


};


#endif //ANDROMEDA_MODEL_H
