//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_OBSERVER_H
#define ANDROMEDA_OBSERVER_H


class Observer {
public:
    virtual ~Observer();
virtual void update()=0;
};


#endif //ANDROMEDA_OBSERVER_H
