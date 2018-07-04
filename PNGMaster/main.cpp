#include "pngmaster.h"
#include <iostream>
using namespace std;

int main(){
    PNGMaster new_pic(250,250);
    PNGMaster arr[3] = {PNGMaster(1,1),PNGMaster(1,1),PNGMaster(1,1)};
    arr[1] = new_pic;
    return 0;
}
