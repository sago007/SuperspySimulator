#pragma once

//Includes

//Custom Includes
#include "Engine.h"
#include "GameState.h"

using namespace Engine2D;

namespace Platformer
{

	class Bonus : public MenuState
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

		SDL_Texture* frame;

		int current;

	};

}
