#ifndef NONDENOVOSPLICEPLUGIN_H
#define NONDENOVOSPLICEPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>

class NonDeNovoSplicePlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "NonDeNovoSplice";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;

};

#endif
