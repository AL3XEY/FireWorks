#ifndef SCRIPTMODE_H
#define SCRIPTMODE_H

#include <src\Modes\DemoMode.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>

class ScriptMode : public DemoMode
{
public:
	ScriptMode(std::string filename);
	~ScriptMode();

	void update();
};

#endif