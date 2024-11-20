#include <ChaosEngine/engine.hpp>

Engine::Engine(){
	log("Starting ChaosEngine version "+string(CHAOS_VERSION));
}

Engine::~Engine(){
	log("Stoping ChaosEngine");
}
