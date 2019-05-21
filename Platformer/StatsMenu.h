#pragma once

//Includes

//Custom Includes
#include "GameState.h"

using namespace Engine2D;

#define AVAILABLE_POINTS_X 512
#define AVAILABLE_POINTS_Y 80
#define REQUIRED_POINTS_X 512
#define REQUIRED_POINTS_Y 112

#define BASE_HEALTH 5

namespace Platformer
{

	class StatsMenu : public MenuState
	{

	//Methods

	public:

		void Initialize(int argc, char* argv[]) override;
		void LoadContent(int argc, char* argv[]) override;

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		void Pause() override;
		void Unpause() override;
		bool UnpauseCondition() override;

		void Shutdown() override;

	protected:

	//Data

	public:

	protected:

		int required = 0;

		int selectedX;
		int selectedY;

		SDL_Texture* selectedTexture;

	};

}