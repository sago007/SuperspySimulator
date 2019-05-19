#pragma once

//Includes
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <map>
#include <vector>

//Custom Includes
#include "AABB.h"
#include "Spritesheet.h"

namespace Engine2D
{

	class GameState
	{

	//Methods

	public:

		GameState();
		virtual ~GameState();

		virtual void Initialize(int argc, char* argv[]) = 0;
		virtual void LoadContent(int argc, char* argv[]) = 0;

		virtual void Start();

		virtual void Update(float deltaTime) = 0;
		virtual void Render(float deltaTime) = 0;

		virtual void Pause() = 0;
		virtual void Unpause() = 0;
		virtual bool UnpauseCondition() = 0;

		virtual void Shutdown() = 0;

		bool Running();
		void SetRunning(bool r);

	protected:

	//Data

	public:

	protected:

		bool running = false;

	};

	class MenuInput : public AABB
	{

	//Methods

	public:

		MenuInput(int x, int y, int w, int h);
		virtual ~MenuInput() = default;

		virtual void Update(float deltaTime) = 0;
		virtual void Render(float deltaTime) = 0;

		virtual int Value() = 0;
		virtual void SetValue(int v);

	protected:

	//Data

	public:

	protected:

	};

	class Button : public MenuInput
	{

	//Methods

	public:

		Button(int x, int y, int w, int h);
		~Button();

		void CreateFromText(TTF_Font* font, std::string text, SDL_Color color);

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		int Value();
		void SetSurface(SDL_Texture* s);

		SDL_Rect* Source();

	protected:

	//Data

	public:

	protected:

		SDL_Texture* surface = nullptr;
		SDL_Rect src = {};

		bool pressed = false;
		bool created = false;

	};

	class Slider : public MenuInput
	{

	//Methods

	public:

		Slider(int x, int y, int w, int h);

		void Update(float deltaTime) override;
		void Render(float deltaTime) override;

		int Value();
		void SetValue(int v);

		void SetSurfaces(SDL_Texture* b, SDL_Texture* s);

	protected:

	//Data

	public:

	protected:

		int val = 0;

		SDL_Texture* backgroundSurface;
		SDL_Texture* surface;

	};

	struct MenuText
	{

		std::string text;
		Vector2 pos;
		SDL_Color color = {};

	};

	class MenuState : public GameState
	{

	//Methods

	public:

		MenuState();
		virtual ~MenuState();

		virtual void Initialize(int argc, char* argv[]) = 0;
		virtual void LoadContent(int argc, char* argv[]) = 0;

		virtual void Start();

		virtual void Update(float deltaTime);
		virtual void Render(float deltaTime);

		virtual void Pause();
		virtual void Unpause();
		virtual bool UnpauseCondition();

		virtual void Shutdown();

	protected:

		void MenuFactory(std::string fileName, int volume = 0);

	//Data

	public:

	protected:

		SDL_Color background = {};

		std::map<std::string, MenuInput*> inputs;

		std::vector<SDL_Texture*> textures;

		TTF_Font* font = nullptr;
		std::vector<MenuText> text;

		Mix_Music* bgm = nullptr;

	};

	struct DrawData
	{

		Vector2 location;
		Vector2 dimensions;

		SDL_Color color = {};
		int index = 0;

		bool flip = false;
		bool sheet = false;

	};

	struct TextData
	{

		Vector2 location;
		SDL_Color color;
		SDL_Texture* text;

	};

	class SplashPage : public GameState
	{

	//Methods

	public:

		SplashPage(GameState* n);
		virtual ~SplashPage();

		virtual void Initialize(int argc, char* argv[]) override;
		virtual void LoadContent(int argc, char* argv[]) override;

		virtual void Update(float deltaTime) override;
		virtual void Render(float deltaTime) override;

		virtual void Pause() override;
		virtual void Unpause() override;
		virtual bool UnpauseCondition() override;

		virtual void Shutdown() override;

	protected:

	//Data

	public:

	protected:

		std::vector<SDL_Texture*> textures;
		std::vector<Spritesheet*> spriteSheets;
		std::vector<TextData> text;

		std::vector<DrawData> data;

		SDL_Color background;
		TTF_Font* font;

		double startTime;
		double duration;

		GameState* nextState;

	};

}