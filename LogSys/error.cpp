#include <ChaosEngine/engine.hpp>

void Engine::error(string error, int errCode, bool fatal){
	fatal ? cerr << "Fatal: " : cerr << "Error: ";
	cerr << error << endl;
	if(fatal){ exit(errCode); }
}
