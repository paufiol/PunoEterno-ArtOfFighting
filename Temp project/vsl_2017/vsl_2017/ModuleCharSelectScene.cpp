#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCharSelectScene.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "ModuleFonts.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleCharSelectScene::ModuleCharSelectScene()
{
	// Background / sky
	background.x = 15;
	background.y = 0;
	background.w = 320;
	background.h = 240;

	rArt = { 5,0,96,80 };
}

ModuleCharSelectScene::~ModuleCharSelectScene()
{}

// Load assets
bool ModuleCharSelectScene::Start()
{
	LOG("Loading Selector scene");
	graphics = App->textures->Load("UI_AOF.png");

	printFont = { 4,870, 318 ,13 };
	font_start = App->fonts->Load("UI_AOF.png", "abcdefghijklmnopqrstuvwxyz", printFont, 1);

	if (App->player->IsEnabled() == true) App->player->Disable();
	return true;
}

// UnLoad assets
bool ModuleCharSelectScene::CleanUp()
{
	SDL_DestroyTexture(graphics);
	LOG("Unloading Selector scene");

	return true;
}

// Update: draw background
update_status ModuleCharSelectScene::Update()
{
	// Draw everything --------------------------------------

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{

		App->fade->FadeToBlack((Module*)App->scene_splash, (Module*)App->scene_karuta, 2.0f);

	}
	return UPDATE_CONTINUE;
}