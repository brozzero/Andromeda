//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_SUBJECT_H
#define ANDROMEDA_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void notify()=0;
    virtual void subscribe(Observer* observer)=0;
    virtual void unsubscribe(Observer* observer)=0;

    virtual ~Subject();
};


#endif //ANDROMEDA_SUBJECT_H
