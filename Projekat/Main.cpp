#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[]){
    string file = argv[1];
    Game g("Mika", "Djoka", file);
    try {
        g.round();
    }
    catch (exception e) {
        cout << e.what();
    }
    
   
}