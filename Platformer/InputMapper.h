#pragma once

//Includes

//Custom Includes
#include "Engine.h"
#include "GameState.h"

using namespace Engine2D;

#define KEY_X_OFFSET 64
#define KEY_Y_OFFSET 0

#define BLINK_DURATION 2000

namespace Platformer
{

	class InputMapper : public MenuState, KeyMapper
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

		void SetKey(SDL_Scancode key) override;

	protected:

	//Data

	public:

	protected:

		SDL_Color keyColor = {};
		int rebindKey = 0;

	};

}