#pragma once

//Includes

//Custom Includes
#include "GameState.h"

using namespace Engine2D;

#define BESTIARY_NAME_X 320
#define BESTIARY_NAME_Y 32

#define BESTIARY_DISCOVERED_X 320
#define BESTIARY_DISCOVERED_Y 64

#define BESTIARY_DESC_X 128
#define BESTIARY_DESC_START_Y 136
#define BESTIARY_DESC_FONT_STEP 32

#define BESTIARY_DRAW_X 32
#define BESTIARY_DRAW_Y 32

#define BESTIARY_ANIMATION_DURATION 2000

namespace Platformer
{

	struct Entry
	{

		std::string name;
		std::string discovered;
		
		std::vector<std::string> lines;

		Spritesheet sheet;

		std::string type;
		int required;

	};

	class Bestiary : public MenuState
	{

	//Methods

	public:

		Bestiary();
		~Bestiary();

		void Initialize(int argc, char* argv[]) override;
		void LoadContent(int argc, char* argv[]) override;

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		void Pause() override;
		void Unpause() override;
		bool UnpauseCondition() override;

		void Shutdown() override;

	protected:

		void RenderText(std::string text, Vector2 loc);

	//Data

	public:

	protected:

		std::vector<Entry*> entries;

		SDL_Color textColor = {};
		int currentEntry = 0;

		double lastSwitch = 0;

		SDL_Texture* lock = nullptr;

	};

}