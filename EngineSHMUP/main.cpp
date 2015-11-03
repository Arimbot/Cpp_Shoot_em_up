#include "Engine.h"

int main(int argc, char* argv[]) {
	Engine* engine = Engine::GetInstance();

	NYTimer loopTimer;
	loopTimer.start();

	long int currentTime = 0,
		deltaTime = 0,
		lastTime = 0;

	while ( engine->IsRunning() ){
		currentTime = loopTimer.getElapsedMs();
		deltaTime = lastTime - currentTime;
		lastTime = currentTime;

		engine->Events(deltaTime);

		engine->Render(deltaTime);
	}

	engine->DeleteInstance();

	return EXIT_SUCCESS;
}