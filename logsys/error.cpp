#include <Chaos/engine.hpp>
#include <Chaos/common.hpp>

void engine::error(const char* error, int errCode, bool fatal){
	fatal ? cerr << "Fatal: " : cerr << "Error: ";
	cerr << error << "\n";
	if(fatal){ exit(errCode); }
}
