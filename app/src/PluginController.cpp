#include "PluginController.h"
#include <iostream>
#include <dlfcn.h>
// For dynamic loading

void PluginController::loadPlugin(const char* pluginPath) {
    void* handle = dlopen(pluginPath, RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed load the plugin" << dlerror() << std::endl;
        return;
    }

    auto createFunc = reinterpret_cast<PluginInterface * (*)()>(dlsym(handle, "createPlugin"));
    if (!createFunc) {
        std::cerr << "Failed to get the createPlugin function: " << dlerror() << std::endl;
        dlclose(handle);
        return;
    }

    // create an instance for plugin
    plugin = createFunc();
    this->plugs.push_back(plugin);
}

void PluginController::runPlugin() {
    if (plugin) {
        plugin->execute();
    } else {
        std::cerr << "No plugin loaded." << std::endl;
    }
}