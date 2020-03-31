#include "electrode.h"

electrode* electrode::_instance = nullptr;

electrode::electrode(){}

electrode* electrode::Instance(){
    if(_instance == nullptr){
        _instance = new electrode;
    }
    _instance->onSkin = true;
    return _instance;
}
bool electrode::getState(){
    return _instance->onSkin;
}

void electrode::changeState(){
    if(_instance->onSkin == true){
        _instance->onSkin = false;
    }
    else{
        _instance->onSkin = true;
    }
}


