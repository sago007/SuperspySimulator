#pragma once

//Includes
#include <vector>

//Custom Includes
#include "Attack.h"
#include "UI.h"

#define ESCAPE_START_TIME 2000
#define ESCAPE_INTERVAL 1000
#define ESCAPE_TRANSPARENCY 192
#define ESCAPE_MAX_DIFFICULTY 10.0
#define ESCAPE_DURATION 1500
#define ESCAPE_BASE_DIVISION 2

namespace Platformer
{

	class Player;

	class ScriptedAction
	{

	//Methods

	public:

		ScriptedAction();
		ScriptedAction(float d);
		virtual ~ScriptedAction();

		void Start();

		virtual void Update(GameEntity* obj, std::vector<Attack*> attacks, UI* ui, float deltaTime) = 0;
		virtual void Render();

		virtual bool Active();

		virtual void HandleAnimation(float deltaTime);

		virtual std::string Type() = 0;

		void Pause();
		void Unpause();

	protected:

	//Data

	public:

	protected:

		double startTime = 0.0;
		float duration = 0.0f;

		bool paused = false;
		double pauseTime = 0.0;

	};

	class PlayerHurtAction : public ScriptedAction
	{

	//Methods

	public:

		PlayerHurtAction();
		PlayerHurtAction(int direction, float s, float d);
		~PlayerHurtAction();

		std::string Type() override;

		void Update(GameEntity* obj, std::vector<Attack*> attacks, UI* ui, float deltaTime) override;

	protected:

	//Data

	public:

	protected:

		int direction = 0;
		float speed = 1.0f;

	};

	class FallingKOAction : public ScriptedAction
	{

	//Methods

	public:

		FallingKOAction();
		FallingKOAction(float d, bool fall);
		~FallingKOAction();

		std::string Type() override;

		void Update(GameEntity* obj, std::vector<Attack*> attacks, UI* ui, float deltaTime) override;

		bool Active() override;

	public:

	protected:

	//Data

	public:

	protected:

		bool falling = false;
		bool play = false;

	};

	class HopAction : public ScriptedAction
	{

	//Methods

	public:

		HopAction(Player* p);
		HopAction(Player* p, float d);
		~HopAction();

		std::string Type() override;

		void Update(GameEntity* obj, std::vector<Attack*> attacks, UI* ui, float deltaTime) override;

		void HandleAnimation(float deltaTime) override;

	protected:

	//Data

	public:

	protected:

		bool jumpKeyUp = true;

		Player* parent = nullptr;
		bool captured = false;

	};

	class EscapeMinigame : public ScriptedAction
	{

	//Methods

	public:

		EscapeMinigame(int n, Player* p);
		EscapeMinigame(int n, Player* p, float d);
		~EscapeMinigame();

		std::string Type() override;

		void Update(GameEntity* obj, std::vector<Attack*> attacks, UI* ui, float deltaTime) override;

		void Render() override;

		bool Active() override;

		double EscapeDuration();

		static void Reset();

	protected:

		void PickButton();

	//Data

	public:

	protected:

		static int hard;
		int difficulty = 0;

		Player* parent = nullptr;

		int button = -1;

		float success = 0.0f;

		double lastButton = 0;

		SDL_Texture* base = nullptr;
		SDL_Texture* filler = nullptr;
		SDL_Texture* hair = nullptr;

	};

}