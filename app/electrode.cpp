#include "electrode.h"

electrode* electrode::_instance = nullptr;

electrode::electrode(){}

electrode* electrode::Instance(){
    if(_instance == nullptr){
        _instance = new electrode;
        _instance->onSkin = false; //initialized electrode state to false
    }
    return _instance; //return single instance of electrode
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


