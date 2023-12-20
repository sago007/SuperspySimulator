#pragma once

//Includes
#include <vector>

//Custom Includes
#include "GameObject.h"
#include "Attack.h"
#include "Enemy.h"

#define TIME_CODE "T"
#define COUNT_CODE "C"
#define GLOBAL_COUNT_CODE "GC"

namespace Platformer
{

	class Condition
	{

	//Methods

	public:

		virtual ~Condition();

		virtual bool Pass(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime) = 0;

		static Condition* ConditionFactory(std::istream* file, std::string id);

		virtual void Spawn();

		virtual void Pause();
		virtual void Unpause();
		double PauseTime(double time);

		virtual bool Active();

	protected:

	//Data

	public:

	protected:

		bool active = true;

		bool paused = false;
		double pauseTime = 0.0;

	};

	class AndCondition : public Condition
	{

	//Methods

	public:

		AndCondition(Condition* p, Condition* q);
		~AndCondition();

		bool Pass(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime) override;

		void Spawn() override;

		void Pause() override;
		void Unpause() override;

		bool Active() override;

	protected:

	//Data

	public:

	protected:

		Condition* p = nullptr;
		Condition* q = nullptr;

	};

	class TimeCondition : public Condition
	{

	//Methods

	public:

		TimeCondition(double t);
		~TimeCondition();

		bool Pass(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime) override;

		void Unpause() override;

	protected:

	//Data

	public:

	protected:

		double time = 0.0;
		double lastSpawn = 0.0;

	};

	class CountCondition : public Condition
	{

	//Methods

	public:

		CountCondition(int m, std::string id);
		~CountCondition();

		bool Pass(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime) override;

	protected:

	//Data

	public:

	protected:

		std::string id;

		int max = 0;

	};

	class GlobalCountCondition : public Condition
	{

	//Methods

	public:

		GlobalCountCondition(int m);
		~GlobalCountCondition();

		bool Pass(std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime) override;

		void Spawn() override;

	protected:

	//Data

	public:

	protected:

		int max = 0;

		int count = 0;

	};

	class Spawner : public GameObject
	{

	//Methods

	public:

		Spawner();
		Spawner(float x, float y, float w, float h);
		virtual ~Spawner();

		void Start(std::map<std::string, Enemy*> master, std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime);
		void Update(std::map<std::string, Enemy*> master, std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime);
		
		void Spawn(std::map<std::string, Enemy*> master, std::vector<GameEntity*>& entities, std::vector<Attack*>& attacks, float deltaTime);

		void SetCodes(std::vector<std::string> codes);
		void SetId(std::string id);
		void SetCondition(Condition* condition);

		void Pause() override;
		void Unpause() override;

		static Spawner* SpawnerFactory(std::istream* file);

	protected:

	//Data

	public:

	protected:

		double lastSpawn = 0.0;

		std::vector<std::string> codes;
		std::string id;

		int currentIndex = 0;

		Condition* condition = nullptr;

	};

}