#pragma once

class PluginInterface {
public:
    /*
    virtual ~PluginInteface() = default;
    virtual bool attach();
    virtual bool detach();
    */
    virtual ~PluginInterface() = default;
    virtual bool execute() = 0;
};
