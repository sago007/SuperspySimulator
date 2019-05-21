#pragma once

//Includes

//Custom Includes
#include "Engine.h"
#include "GameState.h"

using namespace Engine2D;

#define RESULTS_TIME_STEP 2000
#define RESULTS_COUNT_SPEED 200
#define RESULTS_MAX_STAGE 8

namespace Platformer
{

	class ResultsScreen : public MenuState
	{

	//Methods

	public:

		ResultsScreen(int damsels, int dossiers, int info, int bonus);
		~ResultsScreen();

		void Initialize(int argc, char* argv[]) override;
		void LoadContent(int argc, char* argv[]) override;

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		void Pause() override;
		void Unpause() override;
		bool UnpauseCondition() override;

		void Shutdown() override;

		float CounterTarget();

	protected:

	//Data

	public:

	protected:

		int numDamsels, numDossiers, numInfo, levelBonus;

		double startTime;

		float counter;
		int stage = 0;

		Mix_Chunk* stageEffect;

	};

}
