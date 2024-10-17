#include <vector>
#include "PluginInterface.h"


class PluginController {
private:
    PluginInterface* plugin;
    std::vector<PluginInterface*> plugs;

public:
    PluginController() : plugin(nullptr) {}
    ~PluginController() {
        // Clean up the loaded plugin
        if (plugin) {
            //destroyPlugin(plugin);
        }
    }

    void loadPlugin(const char* pluginPath);
    void runPlugin();
};
