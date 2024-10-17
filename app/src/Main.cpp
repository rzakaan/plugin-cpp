#include <iostream>
#include "PluginController.h"

using namespace std;

int main() {
    PluginController controller;
    controller.loadPlugin("sampleplugin");
    controller.runplugin();
    return 0;

}
