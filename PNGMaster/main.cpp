#include "pngmaster.h"
#include <iostream>
using namespace std;

int main(){
    PNGMaster new_pic(250,250);
    new_pic.genPNG("My.png");
    return 0;
}
