#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "NonDeNovoSplicePlugin.h"

void NonDeNovoSplicePlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void NonDeNovoSplicePlugin::run() {}

void NonDeNovoSplicePlugin::output(std::string file) {
 std::string outputfile = file;
 //olego -v -r $Model -j $Junction_db -o r1.sam $Index $Forward_fastq
myCommand += "olego";
myCommand += " -v ";
myCommand += " -r ";
myCommand += PluginManager::addPrefix(myParameters["model"]);
myCommand += " -j ";
myCommand += PluginManager::addPrefix(myParameters["junction"]);
myCommand += " --non-denovo -o " + outputfile + " ";
myCommand += PluginManager::addPrefix(myParameters["index"]);
myCommand += " ";
myCommand += PluginManager::addPrefix(myParameters["fastq"]);
 system(myCommand.c_str());
}

PluginProxy<NonDeNovoSplicePlugin> NonDeNovoSplicePluginProxy = PluginProxy<NonDeNovoSplicePlugin>("NonDeNovoSplice", PluginManager::getInstance());
