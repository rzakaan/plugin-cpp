
class PluginInterface {
public:
    /*
    virtual ~PluginInteface() = default;
    virtual bool attach();
    virtual bool detach();
    */
    virtual bool execute() = 0;
};
