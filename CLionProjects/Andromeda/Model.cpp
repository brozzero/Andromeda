//
// Created by manuel on 01/09/18.
//

#include "Model.h"

Model::Model() {
    size= playlist.size();
    cont=0;
}

int Model::getSize() const {

    return size;
}

void Model::setSize(int size) {
    Model::size = size;
}

int Model::getCont() const {
    return cont;
}

void Model::setCont(int cont) {
    Model::cont = cont;
    notify();
}

void Model::notify() {


    for (auto observer:observers){
        observer->update();
    }

}

void Model::subscribe(Observer* observer) {
    observers.push_back(observer);

}

void Model::unsubscribe(Observer *observer) {
    observers.remove(observer);

}

Model::~Model() {
    playlist.clear();
    for (auto o:observers){
        delete[] o;
    }
    observers.clear();

}

  std::vector<wxString>* Model::getPlaylist()  {
    return &playlist;
}

const wxString &Model::getDirectory() const {
    return directory;
}

void Model::setDirectory( wxString &directory) {
    Model::directory = directory;
    notify();
}
