#ifndef ENGINE_HPP
#define ENGINE_HPP

class engine {
public:
	engine();
	~engine();
	void log(const char* msg);
    void error(const char* error, int errCode=0, bool fatal=false);
};

#endif // ENGINE_HPP
