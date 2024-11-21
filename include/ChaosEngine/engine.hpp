#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
	Engine();
	~Engine();
	void log(string msg);
	void warn(string msg);
	void error(string error, int errCode=0, bool fatal=false);
};

#endif // ENGINE_HPP
