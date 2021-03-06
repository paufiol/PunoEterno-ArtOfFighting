#include "Globals.h"
#include "Application.h"
#include "ModuleSceneLee.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleUI.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "ModuleSceneEnd.h"
#include "ModuleFonts.h"



ModuleSceneLee::ModuleSceneLee()
{
	background = { 0, 0, 538, 240 };
	/*App->scene_splash->printFont = { 0,919,421,16 };*/

}

ModuleSceneLee::~ModuleSceneLee()
{}

// Load assets
bool ModuleSceneLee::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	App->player->p1Won = false;
	App->player->p2Won = false;
	App->audio->PlayMusic("RESOURCES/MUSIC_FXS/MUSIC/FIGHT_SONG/Ryuhaku_Todoh.ogg", -1);
	graphics = App->textures->Load("RESOURCES/Karuta.png");
	/*App->scene_splash->printFontBM= App->fonts->Load("UI_AOF.png", "abcdefghijklmn�opqrstuvwxyz?!._", App->scene_splash->printFont, 1);*/

	App->UI->Enable();
	App->player->Enable();
	App->player2->Enable();
	return ret;
}

// Load assets
bool ModuleSceneLee::CleanUp()
{

	App->audio->StopMusic();
	SDL_DestroyTexture(graphics);
	LOG("Unloading Lee stage");
	App->player->Disable();
	App->player2->Disable();
	App->UI->Disable();
	return true;
}

// Update: draw background
update_status ModuleSceneLee::Update()
{

	App->render->Blit(graphics, 0, 0, &background, 0.75f);
	if (App->player->p1Won)
	{
		printWinner = { 595,420,116,40 };
		App->render->Blit(App->UI->graphics, 100, 70, &printWinner, 0.75f, false, false);
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		{
			App->fade->FadeToBlack((Module*)App->scene_lee, (Module*)App->scene_end, 3.0f);
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		{
			App->fade->FadeToBlack((Module*)App->scene_lee, (Module*)App->scene_end, 3.0f);
		}

	}
	if (App->player->p2Won)
	{
		printWinner = { 725,420,120,40 };
		App->render->Blit(App->UI->graphics, 100, 70, &printWinner, 0.75f, false, false);
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		{
			App->fade->FadeToBlack((Module*)App->scene_lee, (Module*)App->scene_end, 3.0f);
		}
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		{
			App->fade->FadeToBlack((Module*)App->scene_lee, (Module*)App->scene_end, 3.0f);
		}

	}



	return UPDATE_CONTINUE;
}