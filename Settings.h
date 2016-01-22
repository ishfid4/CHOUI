//
// Created by ishfid on 1/21/16.
//

#ifndef CHOUI_SETTINGS_H
#define CHOUI_SETTINGS_H

#include <iostream>


class Settings {
public:
    Settings(std::string pth);
    ~Settings();
    void load();

    std::string path;
    int x, y;
    u_int hz;
};


#endif //CHOUI_SETTINGS_H
