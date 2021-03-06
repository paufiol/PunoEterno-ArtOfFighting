#include "ModuleUI.h"
#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleSceneChina.h"
#include "SDL/include/SDL.h"

ModuleUI::ModuleUI()
{

	//staminatest = 100;

	for (int i = 0; i < 9; i++)
	{
		characterID[i] = i * 24;
	}
	avatar1rect = { 0,characterID[4],24,24 };
	avatar2rect = { 0,characterID[4],24,24 };
	whiterect = { 24,168,26,26 };

	printFont1 = { 0,844, 360 ,12 };
	printFont2 = { 0,861, 360 ,8 };

	Roundball.PushBack({ 49,0,15,15 });
	Roundball.PushBack({ 64,0,15,15 });
	Roundball.PushBack({ 79,0,15,15 });
	Roundball.speed = 0.1f;

}
ModuleUI::~ModuleUI()
{

}
bool ModuleUI::Start()
{
	LOG("Loading UI textures");
	graphics = App->textures->Load("RESOURCES/UI_AOF.png");
	startTime = SDL_GetTicks();
	currentsta1 = 0;
	currentsta2 = 0;
	currenthp1 = 127;
	currenthp2 = 127;
	font_start = App->fonts->Load("RESOURCES/UI_AOF.png", "abcdefghijklmn�opqrstuvwxyz0123456789.'!+,-$_", printFont1, 1);
	font_mini = App->fonts->Load("RESOURCES/UI_AOF.png", "abcdefghijklmn�opqrstuvwxyz0123456789.'!+,-$_", printFont2, 1);
	lifebar1rect = { 766,1, 127,7 };
	lifebar2rect = { 766,1, 127,7 };

	emptylb = { 765,9, 128,9 };

	printFont1 = { 0,844, 360 ,12 };
	printFont2 = { 0,861, 360 ,8 };

	staminabar1rect = { 0,233, 128,8 };
	staminabar2rect = { 0,233, 128,8 };


	return true;
}
update_status ModuleUI::Update()
{
	//Timer:

	//if (currenttime > 60) currenttime %= 60;
	if (!App->player->p1Won)
	{
		currenttime = 0;
		currenttime = (SDL_GetTicks() - startTime) / 1000;
	}

	if (currenttime >= 30)
	{
		currentTimerposX = 928 - (32 * (currenttime - 30));
		if (currenttime > 60) currentTimerposX = 928 - (32 * (60 - 30)); //si es mayor de 60 se queda en 0.
		timerrect = { currentTimerposX,792,32,24 };
		App->render->Blit(graphics, 146, 8, &timerrect, 1.0f, false, false);

	}
	if (currenttime < 30)
	{
		currentTimerposX = 928 - (32 * currenttime);
		timerrect = { currentTimerposX,816,32,24 };
		App->render->Blit(graphics, 146, 8, &timerrect, 1.0f, false, false);
	}
	if (currenttime > 60) timerrect = { 60,816,32,24 };


	//--------------------------------------------------------------------
	//Lifebars:

	App->render->Blit(graphics, 18, 16, &emptylb, 1.0f, false, false);
	App->render->Blit(graphics, 178, 16, &emptylb, 1.0f, false, false);

	if (currenthp1 > ReglaDe3(App->player->hp, 100, 127))
	{
		currenthp1 -= 1;

		lifebar1rect = { 766,1, currenthp1,7 };
	}
	if (currenthp2 > ReglaDe3(App->player2->hp, 100, 127))
	{
		currenthp2 -= 1;

		lifebar2rect = { 766,1, currenthp2,7 };
	}
	App->render->Blit(graphics, 19, 17, &lifebar1rect, 1.0f, false, false);
	App->render->Blit(graphics, 179, 17, &lifebar2rect, 1.0f, false, false);
	//--------------------------------------------------------------------
	//STAMINABARS:
	if (currentsta1 != ReglaDe3(App->player->stamina, 100, 128))
	{
		if (currentsta1 > ReglaDe3(App->player->stamina, 100, 128))
		{
			currentsta1 -= 1;
			staminabar1rect = { 128 - currentsta1 ,ColorSelector(currentsta1), 128,8 };
		}
		if (currentsta1 < ReglaDe3(App->player->stamina, 100, 128))
		{
			currentsta1 += 1;
			staminabar1rect = { 128 - currentsta1 ,ColorSelector(currentsta1), 128,8 };
		}
	}

	if (currentsta2 != ReglaDe3(App->player2->stamina, 100, 128))
	{
		if (currentsta2 > ReglaDe3(App->player2->stamina, 100, 128))
		{
			currentsta2 -= 1;
			staminabar2rect = { 0,ColorSelector(currentsta2), currentsta2,8 };
		}
		if (currentsta2 < ReglaDe3(App->player2->stamina, 100, 128))
		{
			currentsta2 += 1;
			staminabar2rect = { 0,ColorSelector(currentsta2), currentsta2,8 };
		}
	}


	App->render->Blit(graphics, 19, 24, &staminabar1rect, 1.0f, true, false);
	App->render->Blit(graphics, 178, 24, &staminabar2rect, 1.0f, false, false);

	//---------------------------------------------------------------------------
	//Pictures:
	App->render->Blit(graphics, 26, 33, &whiterect, 1.0f, false, false);
	App->render->Blit(graphics, 269, 33, &whiterect, 1.0f, false, false);
	App->render->Blit(graphics, 27, 34, &avatar1rect, 1.0f, false, false);
	App->render->Blit(graphics, 270, 34, &avatar2rect, 1.0f, true, false);
	App->fonts->BlitText(34, 3, font_start, "beat_by_0", printFont1);
	App->fonts->BlitText(210, 3, font_start, "beat_by_0", printFont1);
	App->fonts->BlitText(50, 32, font_mini, "lee", printFont2);
	App->fonts->BlitText(230, 32, font_mini, "lee", printFont2);
	//Rounds:------------------------------------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();
	current_animation = &Roundball;
	if (App->scene_china->roundP1 == 1)
	{
		App->render->Blit(graphics, 54, 40, &r, 1.0f, false, false);
	}
	if (App->scene_china->roundP1 == 2)
	{
		App->render->Blit(graphics, 70, 40, &r, 1.0f, false, false);
		App->render->Blit(graphics, 54, 40, &r, 1.0f, false, false);
	}
	if (App->scene_china->roundP2 == 1)
	{
		App->render->Blit(graphics, 250, 40, &r, 1.0f, false, false);
	}
	if (App->scene_china->roundP2 == 2)
	{
		App->render->Blit(graphics, 250, 40, &r, 1.0f, false, false);
		App->render->Blit(graphics, 220, 40, &r, 1.0f, false, false);
	}
	//-------------------------------------------------------------------------
	//App->render->DrawQuad({ 0, 0, 10, 10 }, 255, 255, 255, 255, false);
	return UPDATE_CONTINUE;
}

int ModuleUI::ReglaDe3(float newhp, float hpbase, float pixels)
{
	float res = (float)(newhp / hpbase) * pixels;
	return (int)res;
}

int ModuleUI::ColorSelector(int currentstamina)
{
	if (currentstamina < 30)
	{
		return 217;
	}

	if (currentstamina >= 30 && currentstamina < 70)
	{
		return 225;
	}

	if (currentstamina >= 70)
	{
		return 233;
	}
}

bool ModuleUI::CleanUp()
{
	if (graphics != nullptr) { 
		SDL_DestroyTexture(graphics);
		graphics = nullptr;
	}


	return true;
}