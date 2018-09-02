//
// Created by manuel on 01/09/18.
//

#include "Controller.h"

Controller::Controller(Model *m):model(m) {}

void Controller::avanti() {
    int counter=model->getCont();
    if(counter!=model->getSize()){
        counter++;
        model->setCont(counter);

    }
}

void Controller::indietro() {
    int counter=model->getCont();
    if(counter!=0){
        counter--;
        model->setCont(counter);

    }
}
