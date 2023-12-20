#pragma once

//Includes
#include<SDL.h>
#include <SDL_mixer.h>

//Custom Includes
#include "CollisionMap.h"
#include "Attack.h"
#include "Spawner.h"
#include "Enemy.h"
#include "Event.h"

namespace Platformer
{

	class Platformer;

	class Level : public AABB
	{

	//Methods

	public:

		Level(Platformer* p);
		Level(Platformer* p, int w, int h, std::string collision, std::string enemy_master, std::string events);
		~Level();

		void LoadLevel(std::string fileName);

		void Start();

		void Update(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime);

		Vector2 SpawnPoint(Vector2 point);
		Vector2 SpawnIndex(int i);

		void SpawnEnemy(Vector2 loc, std::string code, std::string type);

		int LockX();
		int LockY();

		void Pause();
		void Unpause();

		CollisionMap* Collision();
		Platformer* GetPlatformer();

		void EnemyDied(Vector2 loc);
		void Refill(int i);

		void AddTrigger(Trigger* t);
		void Block(std::string n);
		void RemoveGround(bool fore, int image, int location);

		void DrawBackground(Vector2 world, float deltaTime);
		void DrawForeground(Vector2 world, float deltaTime);
		void DrawUI(UI* ui, float deltaTime);
		void DebugDraw(Vector2 world, float deltaTime);

	protected:

		void LoadCollision(std::string fileName);
		void LoadMaster(std::string fileName);
		void LoadEvents(std::string fileName);
		void LoadTiles(std::string fileName);
		void LoadGround(std::string fileName);
		void LoadSpawners(std::istream* file);

	//Data

	public:

	protected:

		int width = 0;
		int height = 0;

		int lockX = 0, lockY = 0;

		CollisionMap collision;

		std::vector<Vector2> spawnPoints;

		std::map<std::string, Enemy*> master;
		std::vector<Spawner*> spawners;
		std::vector<Trigger*> triggers;

		std::map<std::string, GameEntity*> breakables;

		Mix_Music* music = nullptr;

		SDL_Texture* tileImage = nullptr;

		std::vector<Spritesheet*> backgroundSheets;
		std::vector<std::vector<Vector2>> backgroundLocations;
		std::vector<Spritesheet*> foregroundSheets;
		std::vector<std::vector<Vector2>> foregroundLocations;

		Platformer* platformer = nullptr;

		Item* enemyDrop = nullptr;
		int dropChance = 0;

		std::vector<std::pair<std::pair<std::string, std::string>, Vector2>> spawnLocations;

	};

}
