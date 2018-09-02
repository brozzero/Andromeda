//
// Created by manuel on 02/09/18.
//

#ifndef ANDROMEDA_IMAGE_H
#define ANDROMEDA_IMAGE_H

#include <string>

class Image {
public:
    Image(int date, const std::string &name);

private:
    int date;
    std::string name;

};


#endif //ANDROMEDA_IMAGE_H
