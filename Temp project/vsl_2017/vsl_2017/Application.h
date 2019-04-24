#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 16

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleSceneBar;
class ModuleSceneKaruta;
class ModuleSceneSplash;
class ModuleSceneEnd;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class ModuleAudio;
class ModuleParticles;
class ModuleCollision;
class Module;
class ModuleUI;
class ModuleFonts;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneBar* scene_bar;
	ModuleSceneKaruta* scene_karuta;
	ModuleSceneSplash *scene_splash;
	ModuleSceneEnd *scene_end;
	ModulePlayer* player;
	ModulePlayer2*  player2;
	ModuleFadeToBlack* fade;
	ModuleAudio* audio;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleUI* UI;
	ModuleFonts* fonts;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__