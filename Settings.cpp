//
// Created by ishfid on 1/21/16.
//

#include "Settings.h"
#include <fstream>

Settings::Settings(std::string pth) {
    path = pth;
}

Settings::~Settings(){ }

void Settings::load(){
    std::fstream file;
    file.open(path);

    file>>x;
    file>>y;
    file>>hz;

    file.close();
}