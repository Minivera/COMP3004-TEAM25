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
    return onSkin;
}

void electrode::changeState(){
    if(onSkin == true){
        onSkin = false;
    }
    else{
        onSkin = true;
    }
}


