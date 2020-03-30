#include "electrode.h"

electrode::electrode(){
    onSkin = true;
}
electrode::~electrode(){
}
bool electrode::getState(){
    return onSkin;
}
void electrode::setState(bool state){
    onSkin = state;
}

void electrode::changeState(){
    if(onSkin == true){
        this->setState(false);
    }
    else{
        this->setState(true);
    }
}
