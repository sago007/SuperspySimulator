#pragma once

//Includes

//Custom Includes
#include "Vector2.h"
#include "GameState.h"
#include "Player.h"
#include "Level.h"
#include "UI.h"
#include "Items.h"

using namespace Engine2D;
 
#define SCREEN_SHAKE_HURT 5

#define FRAMES_IN_WALL_MAX 1
#define MOVEMENT_MAX 50

#define DEBUG_FPS_X 576
#define DEBUG_FPS_Y 320
#define DEBUG_FRAME_COUNTER 600

namespace Platformer
{

	struct PauseText;

	class Platformer : public GameState
	{

	//Methods

	public:

		Platformer();
		~Platformer();

		void Initialize(int argc, char* argv[]) override;
		void LoadContent(int argc, char* argv[]) override;

		void Start() override;

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		void Pause() override;
		void Unpause() override;
		bool UnpauseCondition() override;

		void Shutdown() override;

		void RegisterAttack(Attack* a);
		void RegisterEntity(GameEntity* e);
		void RegisterBlock(std::string b);
		void AddItem(Item* i);
		void AddToInventory(Item* i);

		bool SearchType(std::string t);

		bool Blocked(std::string b);

		void TriggerRespawn();
		void TriggerDoor(std::string level, int spawnIndex);
		void TriggerExit();
		void TriggerGameOver();
		void TriggerPauseText(PauseText* t);

	protected:

		void LoadLevel(std::string levelName, int spawnIndex);

		void RemoveEntities();
		void RemoveAttacks();

		void UpdatePlayer(float deltaTime);
		void BoundCamera();

		void UpdateAttacks(float deltaTime);

		void DebugRender(float deltaTime);

	//Data

	public:

	protected:

		Vector2 world;

		Player* player = nullptr;
		
		Level* level = nullptr;
		std::string currentLevel;
		int spawn = 0;

		std::vector<GameEntity*> entities;
		std::vector<Attack*> attacks;
		std::vector<Item*> items;
		std::vector<std::string> blocked;

		bool pauseKeyUp = false;

		int framesInWall = 0;

		PauseText* pauseText = nullptr;

	};
	
}
