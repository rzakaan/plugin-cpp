#include "SamplePlugin.h"
#include <iostream>

bool SamplePlugin::execute() {
    std::cout << "SamplePlugin execute" << std::endl;
    return true; 
}

// Export the factory function for creating the plugin instance
extern "C" PluginInterface* createPlugin() {
    return new SamplePlugin;
}

// Export the function for cleaning up the plugin instance
extern "C" void destroyPlugin(PluginInterface* plugin) {
    delete plugin;
}
