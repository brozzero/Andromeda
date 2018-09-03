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
        auto playlist=model->getPlaylist();
        model->setDirectory(playlist->operator[](counter-1));
    }


}

void Controller::indietro() {
    int counter=model->getCont();
    if(counter!=1){
        counter--;
        model->setCont(counter);
        auto playlist=model->getPlaylist();
        model->setDirectory(playlist->operator[](counter-1));

    }
}
