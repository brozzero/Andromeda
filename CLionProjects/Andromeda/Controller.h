//
// Created by manuel on 01/09/18.
//

#ifndef ANDROMEDA_CONTROLLER_H
#define ANDROMEDA_CONTROLLER_H


#include "Model.h"

class Controller {
private:
    Model* model;
public:
    explicit Controller(Model* m);
    void avanti();
    void indietro();
    void play(){};
    void stop(){};

};


#endif //ANDROMEDA_CONTROLLER_H
