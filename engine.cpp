#include <ChaosEngine/engine.hpp>
#include <ChaosInfo.hpp>

Engine::Engine(){
	log("Staring ChaosEngine version: " + string(CHAOS_VERSION));
}

Engine::~Engine(){
	log("Stoping ChaosEngine");
}
