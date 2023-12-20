#pragma once

//Includes
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>

//Custom Includes
#include "Vector2.h"
#include "Spritesheet.h"
#include "Attack.h"

using namespace Engine2D;

namespace Platformer
{

	class Weapon
	{

	//Methods
	
	public:

		Weapon(GameEntity* p, float r);
		virtual ~Weapon();

		static Weapon* LoadWeapon(std::istream& file, GameEntity* p);

		void Use(std::vector<Attack*>& attacks, Vector2 direction = Vector2(1, 0));

		bool Ready();

		void Pause();
		void Unpause();

		double PauseTime(double time);

		virtual Weapon* Clone(GameEntity* p) = 0;

		virtual void Refresh() = 0;

	protected:

		virtual void Fire(std::vector<Attack*>& attacks, Vector2 direction) = 0;
		virtual void Load(std::istream& file) = 0;

		virtual void DataCopy(Weapon* weapon);

	//Data
	
	public:

	protected:

		GameEntity* parent = nullptr;

		float rateOfUse = 0;
		double lastUsed = 0.0f; 

		double pauseTime = 0.0f;
		bool paused = false;
		
		Mix_Chunk* useEffect = NULL;
		bool loadedSounds = true;

	};

	class Melee : public Weapon
	{

	//Methods

	public:

		Melee(GameEntity* p, int d, float w, float h, float lX, float lY, float rX, float rY, float r, int i);
		Melee(GameEntity* p, float r, MeleeAttack* m);
		~Melee();

		Weapon* Clone(GameEntity* p) override;

		void Refresh() override;

	protected:

		void Fire(std::vector<Attack*>& attacks, Vector2 direction) override;
		void Load(std::istream& file) override;

	//Data

	public:

	protected:

		MeleeAttack* melee;

	};

	class Projectile : public Weapon
	{
	
	//Methods
	
	public:

		Projectile(GameEntity* p, float lX, float lY, float rX, float rY, float r);
		~Projectile();

		Vector2 Offset();

		Weapon* Clone(GameEntity* p) override;

		void Refresh() override;

	protected:

		void Fire(std::vector<Attack*>& attacks, Vector2 direction) override;
		void Load(std::istream& file) override;

	//Data
	
	public:

	protected:

		Vector2 leftOffset;
		Vector2 rightOffset;

		Bullet* bullet;

	};

	class Multishot : public Weapon
	{

	//Methods

	public:

		Multishot(GameEntity* p, float lX, float lY, float rX, float rY, float r);
		~Multishot();

		Vector2 Offset();

		Weapon* Clone(GameEntity* p) override;

		void Refresh() override;

	protected:

		void Fire(std::vector<Attack*>& attacks, Vector2 direction) override;
		void Load(std::istream& file) override;

	//Data

	public:

	protected:

		Vector2 leftOffset;
		Vector2 rightOffset;

		std::vector<Bullet*> bullets;

	};

	class SpawnGun : public Weapon
	{

	//Methods

	public:

		SpawnGun(GameEntity* p, float lX, float lY, float rX, float rY, float r);
		~SpawnGun();

		Vector2 Offset();

		Weapon* Clone(GameEntity* p) override;

		void Refresh() override;

	protected:

		void Fire(std::vector<Attack*>& attacks, Vector2 direction) override;
		void Load(std::istream& file) override;

	//Data

	public:

	protected:

		Vector2 leftOffset;
		Vector2 rightOffset;

		std::string code;

	};

}
