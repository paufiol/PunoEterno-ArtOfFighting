#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	position.x = 310;
	position.y = 112;


	idle.PushBack({ 0,3,70,101 }, 0, 0);
	idle.PushBack({ 75,5,69,99 }, 0, 2);
	idle.PushBack({ 159,1,70,103 }, 0, -2);

	idle.speed = 0.075f;

	// idle animation (arcade sprite sheet)
	/*idle.PushBack({ 0, 8, 66, 108 });
	idle.PushBack({ 66, 8, 67 , 108 });
	idle.PushBack({ 133, 8, 69, 108 });
	if(flip) idle.speed = 0.025f;
	if (!flip) idle.speed = 0.1f;
	*/

	//walk forward lee

	forward.PushBack({ 239,0,68,103 });
	forward.PushBack({ 322,0,58,103 });
	forward.PushBack({ 385,1,51,101 });
	forward.PushBack({ 447,1,48,102 });
	forward.PushBack({ 385,1,51,101 });
	forward.PushBack({ 322,0,58,103 });
	forward.speed = 0.9f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});

	/*forward.PushBack({ 691, 348, 56, 109 });
	forward.PushBack({ 749, 350, 65, 107 }, -10, 0);
	forward.PushBack({ 818, 348, 58, 109 });
	forward.PushBack({ 876, 350, 65, 107 }, -9, 0);*/



	/*forward.PushBack({ 874, 348, 67, 108 });*/
	if (!flip) forward.speed = 0.1f;
	if (!flip) forward.speed = 0.05f;

	//flipforward.PushBack({ 691, 348, 56, 109 }, 0, 0);
	//flipforward.PushBack({ 749, 350, 65, 107 }, 10, 0);
	//flipforward.PushBack({ 818, 348, 58, 109 }, 0, 0);
	//flipforward.PushBack({ 876, 350, 65, 107 }, 9, 0);
	///*forward.PushBack({ 874, 348, 67, 108 });*/
	//if (flip) flipforward.speed = 0.1f;
	//if (!flip) flipforward.speed = 0.05f;

	/*back.PushBack({ 577, 479, 57, 109 }, -5, 0);
	back.PushBack({ 638, 477, 52, 111 });
	back.PushBack({ 692, 479, 57, 109 }, -5, 0);
	back.PushBack({ 638, 477, 52, 111 });
	back.PushBack({ 577, 479, 57, 109 }, -5, 0);
	if (!flip) back.speed = 0.1f;
	if (flip) back.speed = 0.05f;*/

	/*back.PushBack({ 239,0,68,103 });*/
	back.PushBack({ 322,0,58,103 });
	back.PushBack({ 385,1,51,101 });
	back.PushBack({ 447,1,48,102 });
	back.PushBack({ 385,1,51,101 });
	back.PushBack({ 322,0,58,103 });
	back.speed = 0.1f;

	/*flipback.PushBack({ 577, 479, 57, 109 }, 5, 0);
	flipback.PushBack({ 638, 477, 52, 111 });
	flipback.PushBack({ 692, 479, 57, 109 }, 5, 0);
	flipback.PushBack({ 638, 477, 52, 111 });
	flipback.PushBack({ 577, 479, 57, 109 }, 5, 0);
	if (flip) flipback.speed = 0.1f;
	if (!flip) flipback.speed = 0.05f;*/

	//RYU:
	//doubleback.PushBack({ 275, 595, 59, 107 });
	//doubleback.PushBack({ 334, 596, 89, 106 }, -80, -10);
	//doubleback.PushBack({ 334, 596, 89, 106 }, 0, 0);
	//doubleback.PushBack({ 423, 596, 73, 106 }, -80, 10);
	//-----------------------------------------------------------
	//LEE:
	doubleback.PushBack({ 0, 623, 58, 94 });
	doubleback.PushBack({ 58, 623, 68, 94 });
	doubleback.PushBack({ 126, 623, 38, 94 });
	doubleback.PushBack({ 164, 623, 79, 94 });
	doubleback.PushBack({ 242, 623, 56, 94 });
	if (!flip) doubleback.speed = 0.2f;
	/*if (flip) doubleback.speed = 0.05f;*/
	doubleback.lock = true;

	doubleforward.PushBack({ 242, 623, 56, 94 });
	doubleforward.PushBack({ 164, 623, 79, 94 });
	doubleforward.PushBack({ 126, 623, 38, 94 });
	doubleforward.PushBack({ 58, 623, 68, 94 });
	doubleforward.PushBack({ 0, 623, 58, 94 });
	if (!flip) doubleforward.speed = 0.2f;
	doubleforward.lock = true;



	jumppunch.PushBack({ 277, 247, 75, 86 });
	jumppunch.PushBack({ 172, 245, 105, 89 });
	jumppunch.speed = 0.5f;
	jumppunch.lock = true;

	jumpkick.PushBack({ 541, 372,106, 72 }, 0, 30);
	jumpkick.speed = 0.5f;
	jumpkick.lock = true;

	jump.PushBack({ 697,  6, 54, 98 }, 0, -20);
	jump.PushBack({ 759, 49, 78, 53 }, 0, -20);
	jump.PushBack({ 837, 32, 38, 70 }, 0, -20);
	jump.PushBack({ 885, 64, 68, 38 }, 0, -20);
	jump.PushBack({ 958, 34, 39, 69 }, 0, -20);
	jump.PushBack({ 0, 167, 66, 38 }, 0, -20);
	jump.PushBack({ 837, 32, 38, 70 }, 0, -20);
	jump.PushBack({ 885, 64, 68, 38 }, 0, -20);
	jump.PushBack({ 958, 34, 39, 69 }, 0, -20);
	jump.PushBack({ 0, 167, 66, 38 }, 0, -20);
	jump.PushBack({ 329, 145, 68, 61 }, 0, -20);
	jump.PushBack({ 412, 112, 58, 94 }, 0, 7);
	jump.PushBack({ 485, 108, 54, 99 }, 0, -20);
	jump.PushBack({ 615, 40, 77, 62 }, 0, 35);
	jump.speed = 0.2f;

	jump.lock = true;

	punch.PushBack({ 376, 341,  69, 103 });
	punch.PushBack({ 81, 341,  104, 103 });
	punch.PushBack({ 0, 341,  74, 103 });
	punch.PushBack({ 376, 341,  69, 103 });

	/*punch.PushBack({ 485, 348,  58, 108 });*/
	if (!flip) punch.speed = 0.15f;

	punch.lock = true;


	koukenR.PushBack({ 176, 873, 66, 112 });
	koukenR.PushBack({ 242, 873, 88, 112 });
	koukenR.PushBack({ 330, 884, 85, 96 });
	koukenR.PushBack({ 415, 888, 81, 97 });
	koukenR.PushBack({ 496, 877, 102, 108 });
	koukenR.speed = 0.2f;
	koukenR.lock = true;

	//AQUI haced que de patadas

	//kick.PushBack({ 787,114,71,89 });
	//kick.PushBack({ 858, 109,73,99 });
	//kick.PushBack({ 0,227, 89, 103 });
	//kick.PushBack({ 89, 222, 83,110 });
	//kick.PushBack({ 172, 245, 105, 89 });
	//kick.PushBack({277, 247, 75, 86 });
	//kick.speed = 0.1f;
	//kick.lock = true;


	kick.PushBack({ 0, 922, 58, 102 });
	kick.PushBack({ 58, 922, 58, 102 });
	kick.PushBack({ 116, 922, 51, 102 });
	kick.PushBack({ 171, 922, 112, 102 });
	kick.PushBack({ 116, 922, 51, 102 });
	kick.PushBack({ 58, 922, 58, 102 });
	/*kick.PushBack({ 296, 922, 72, 102 });*/

	/*kick.PushBack({ 669, 235, 60, 109 });*/
	kick.speed = 0.1f;

	kick.lock = true;

	//flipkick.PushBack({ 669, 235, 60, 109 });
	//flipkick.PushBack({ 729, 235, 61, 113 });
	//flipkick.PushBack({ 790, 235, 103, 113 });
	//flipkick.PushBack({ 729, 235, 61, 113 });
	///*flipkick.PushBack({ 669, 235, 60, 109 });*/
	//flipkick.speed = 0.1f;
	//flipkick.lock = true;

	  //DONE
	crouchidle.PushBack({ 0, 482, 58, 88 }, 0, 15);
	crouchidle.PushBack({ 921, 382, 77, 62 }, 0, 41);
	/*crouchidle.PushBack({ 0, 482, 58 , 88}, 0, 15);*/
	crouchidle.speed = 0.2f;
	crouchidle.lock = false;
	crouchidle.loop = false;

	/*crouchpunch.PushBack({ 414, 42, 53, 76 }, 0, 34);
	crouchpunch.PushBack({ 469, 41, 106, 77 }, -15, 34);
	crouchpunch.speed = 0.15f;
	crouchpunch.lock = true;
*/
	crouchkick.PushBack({ 449, 382, 92, 62 }, 0, 40);
	crouchkick.PushBack({ 541, 372,106, 72 }, 0, 30);
	crouchkick.PushBack({ 650,382, 88, 78 }, 0, 40);
	crouchkick.PushBack({ 449, 383, 92, 61 }, 0, 40);
	/*crouchkick.PushBack({ 827, 397, 94, 47 },0,30);
	crouchkick.PushBack({ 921,382,80,62},0,30);
	crouchkick.PushBack({0,482,58,88 },0,30);
	crouchkick.PushBack({ 449, 382, 92, 62 },0,30);*/

	crouchkick.speed = 0.2f;
	crouchkick.lock = true;
	//RYO:
	//damaged.PushBack({ 869,751, 66 ,107 });
	//damaged.PushBack({ 935,750, 78, 138 });
	//damaged.PushBack({869, 751, 66, 107 });
	//LEE:
	damaged.PushBack({ 372,917, 63 ,107 });
	damaged.PushBack({ 435,917, 81, 107 });
	damaged.PushBack({ 514, 917, 73, 107 });
	damaged.speed = 0.25f;
	damaged.lock = true;

	//faltan volteretas

	//sacargarras.speed = 0.2f;
	//sacargarras.lock = true;

	//Spin Lee:
	sp1.PushBack({ 71,466,76,105 });
	sp1.PushBack({ 162,466, 76, 105 });
	sp1.PushBack({ 244, 466,77, 104 });
	sp1.PushBack({ 330,478, 76, 122 });
	sp1.PushBack({ 244, 466,77, 104 });

	sp1.PushBack({ 420,505,35,69 }, 0, 30);
	sp1.PushBack({ 455,505, 108, 69 }, 0, 30);
	sp1.PushBack({ 570, 505,77, 69 }, 0, 30);
	sp1.PushBack({ 650,505, 31, 69 }, 0, 30);
	sp1.PushBack({ 684, 505,76, 69 }, 0, 30);
	sp1.PushBack({ 760, 505,107, 69 }, 0, 30);
	sp1.PushBack({ 420,505,35,69 }, 0, 30);
	sp1.PushBack({ 455,505, 108, 69 }, 0, 30);
	sp1.PushBack({ 570, 505,77, 69 }, 0, 30);
	sp1.PushBack({ 650,505, 31, 69 }, 0, 30);
	sp1.PushBack({ 684, 505,76, 69 }, 0, 30);
	sp1.PushBack({ 760, 505,107, 69 }, 0, 30);
	sp1.speed = 0.2f;
	sp1.lock = true;

	charge.PushBack({ 412, 758,76, 145 }, -10, -40);
	charge.PushBack({ 488, 758,76, 145 }, -10, -40);
	charge.PushBack({ 564, 758,76, 145 }, -10, -40);
	charge.PushBack({ 640, 758,76, 145 }, -10, -40);
	charge.PushBack({ 716, 758,76, 145 }, -10, -40);
	charge.speed = 0.2f;
	charge.lock = true;

	victory.PushBack({ 0,729,76,121 }, 0, -16);
	victory.PushBack({ 330, 478, 76, 122 }, 0, -17);
	victory.PushBack({ 244, 466,76,105 });
	victory.PushBack({ 162,466,76,105 });
	victory.PushBack({ 71,466,76,105 });
	victory.speed = 0.15;
	victory.lock = true;
	victory.loop = false;

	//RYO:
	/*defeat.PushBack({ 0, 0, 66, 115 });
	defeat.PushBack({ 66, 0, 73, 115 });
	defeat.PushBack({ 144, 8, 64, 107 });
	defeat.PushBack({ 208, 29, 62, 86 });
	defeat.PushBack({ 270, 53, 58, 62 });*/

	//LEE:
	defeat.PushBack({ 625, 922, 79, 102 });
	defeat.PushBack({ 707, 922, 89, 102 });
	defeat.PushBack({ 803, 922, 91, 102 });
	defeat.PushBack({ 898, 922, 120, 102 });

	defeat.lock = true;
	defeat.loop = false;
	defeat.speed = 0.1f;

	//LEE:
	provocar.PushBack({ 578, 232, 72, 102 });
	provocar.PushBack({ 651, 232, 58, 102 });
	provocar.PushBack({ 578, 232, 72, 102 });
	provocar.PushBack({ 651, 232, 58, 102 });
	provocar.PushBack({ 578, 232, 72, 102 });
	provocar.PushBack({ 651, 232, 58, 102 });
	provocar.PushBack({ 578, 232, 72, 102 });
	provocar.PushBack({ 651, 232, 58, 102 });
	provocar.PushBack({ 578, 232, 72, 102 });
	provocar.PushBack({ 651, 232, 58, 102 });

	provocar.lock = true;
	provocar.speed = 0.2f;

	firekick.PushBack({ 172, 245, 105, 89 });
	firekick.PushBack({ 89,224, 84, 110 });
	firekick.PushBack({ 172, 245, 105, 89 });
	firekick.PushBack({ 89,224, 84, 110 });
	firekick.PushBack({ 172, 245, 105, 89 });
	firekick.PushBack({ 89,224, 84, 110 });
	firekick.PushBack({ 172, 245, 105, 89 });
	firekick.PushBack({ 921, 382, 77, 62 }, 0, 41);

	firekick.speed = 0.02f;

	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 892, 217,93,117 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 313, 717, 99, 99 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 185, 341,  117, 103 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 892, 217,93,117 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 313, 717, 99, 99 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 185, 341,  117, 103 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 892, 217,93,117 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 313, 717, 99, 99 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 185, 341,  117, 103 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 892, 217,93,117 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 313, 717, 99, 99 });
	multipunch.PushBack({ 0,345,74,9 });
	multipunch.PushBack({ 185, 341,  117, 103 });
	multipunch.PushBack({ 0,345,74,9 });

	multipunch.speed = 0.4f;
	multipunch.lock = true;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("RESOURCES/lee2.png");
	/*graphs = App->textures->Load("ryo2.png");*/
	

	hp = 100;
	stamina = 100;
	playerCollider = App->collision->AddCollider({ position.x, position.y, 57, 108 }, COLLIDER_PLAYER2, this);
	winFrame2 = {65,266,69,106 };
	return ret;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	if (this->position.x >= App->player->position.x) flip = true;
	if (this->position.x <= App->player->position.x) flip = false;
	if (flip) {
		flip_sign = -1;
		/*if (newFlip = true) {
			current_animation->SetSpeed(current_animation->speed/2);
			newFlip = false;
		}*/
		punch.SetOffset(1, -30, 0);
		punch.SetOffset(2, 0, 0);
		kick.SetOffset(3, -50, 0);
		
		//speeds
		idle.speed = 0.075f;
		jump.speed = 0.2f;
		punch.speed = 0.15;
		kick.speed = 0.1f;
	}
	if (!flip) {
		flip_sign = 1;
		/*if (newFlip = true) {
			current_animation->SetSpeed(current_animation->speed * 2);
			newFlip = false;
		}*/
		punch.SetOffset(1, 0, 0);
		punch.SetOffset(2, 0, 0);
		kick.SetOffset(3, 0, 0);

		//speeds
		idle.speed = 0.15f;
		jump.speed = 0.4f;
		punch.speed = 0.3f;
		kick.speed = 0.2f;
	}
	

	//Regeneration stamina:

	if (stamina == 100)
	{
		plusta = 0;
	}
	else
	{
		plusta++;
		if (plusta > 60)
		{
			stamina++;
			plusta = 0;
		}
	}
	//----------------------------------
	playerCollider->SetPos(position.x, position.y);
	if (flip) playerCollider->SetPos(position.x + (current_animation->GetCurrentFrame().w) - playerCollider->rect.w, position.y);

	playerCollider->rect.h = 108;
	if (block != nullptr)
	{
		if (!flip)	block->SetPos(position.x + 55, position.y + 5);
		if (flip)	block->SetPos(position.x - 10, position.y + 5);
	}

	if (current_animation == &crouchidle || current_animation == &crouchpunch || current_animation == &crouchkick)
	{
		playerCollider->SetPos(position.x, position.y + 40);
		playerCollider->rect.h = 75;
	}


	if (jumping == JUMP_NOT) {
		speed.x = 0.0f;
	}

	if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_UP) {
		//keyup[SDL_SCANCODE_D] = true;
		if (block != nullptr && flip) block->to_delete = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_UP) {
		//keyup[SDL_SCANCODE_A] = true;
		if (block != nullptr && !flip) block->to_delete = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN && keyup[SDL_SCANCODE_U] && current_animation->lock) {
		keyup[SDL_SCANCODE_U] = false;
		StoreInput(SDL_SCANCODE_U);
	}

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN && keyup[SDL_SCANCODE_O] && current_animation->lock) {
		keyup[SDL_SCANCODE_O] = false;
		StoreInput(SDL_SCANCODE_O);
	}
	
	
	

	for (int i = 0; i < 69; i++) {
		if (App->input->keyboard[i] == KEY_STATE::KEY_UP) {
			keyup[i] = true;
		}
	}

	if (App->player->playersMove) {
		if (current_animation->Finished() || current_animation->lock == false && !App->player->p1Won && !App->player->p2Won)
		{
			if (current_animation->Finished()) {
				current_animation->Reset();
				if (melee != nullptr) melee->to_delete = true;

			}
			bool leaveif = false;

			current_animation = &idle;

			if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN) {
				current_animation = &jump;
				jumping = JUMP_UP;
				speed.x = 2.5f;
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Jump.wav"));
			}

			if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_DOWN && App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN) {
				current_animation = &jump;
				jumping = JUMP_UP;
				speed.x = -2.5f;
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Jump.wav"));
			}

			if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN)
			{
				current_animation = &crouchidle;
				playerCollider->rect.h = 75;

				if (keyup[SDL_SCANCODE_K]) {
					StoreInput(SDL_SCANCODE_K);
					keyup[SDL_SCANCODE_K] = false;
				}
			}

			if (!keyup[SDL_SCANCODE_K] && (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN)
				&& keyup[SDL_SCANCODE_U] && !leaveif)
			{
				current_animation = &crouchkick;
				if (flip) melee = App->collision->AddCollider({ position.x - 50, position.y + 45, 55, 20 }, COLLIDER_PLAYER2_ATTACK, this);
				if (!flip) melee = App->collision->AddCollider({ position.x + 50, position.y + 45, 45, 20 }, COLLIDER_PLAYER2_ATTACK, this);
				leaveif = true;

				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Punch_Attack.wav"));
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Punch.wav"));

				if (keyup[SDL_SCANCODE_U]) {
					StoreInput(SDL_SCANCODE_U);
					keyup[SDL_SCANCODE_U] = false;
				}
			}

			if (!keyup[SDL_SCANCODE_K] && (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN)
				&& keyup[SDL_SCANCODE_O] && !leaveif)
			{
				current_animation = &crouchkick;
				if (flip) melee = App->collision->AddCollider({ position.x - 50, position.y + 75, 65, 35 }, COLLIDER_PLAYER1_ATTACK, this);
				if (!flip) melee = App->collision->AddCollider({ position.x + 50, position.y + 75, 65, 35 }, COLLIDER_PLAYER1_ATTACK, this);
				leaveif = true;

				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Punch_Attack.wav"));
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Kick_Groan.wav"));

				if (keyup[SDL_SCANCODE_O]) {
					StoreInput(SDL_SCANCODE_O);
					keyup[SDL_SCANCODE_O] = false;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_L] == KEY_STATE::KEY_DOWN)
			{
				current_animation = &back;


				speed.x = 2.5f;
				playerCollider->rect.h = 108;
				if (keyup[SDL_SCANCODE_L]) {
					StoreInput(SDL_SCANCODE_L);
					if (flip) { block = App->collision->AddCollider({ position.x - 20, position.y + 5, 15, 35 }, COLLIDER_WALL, this); }
					keyup[SDL_SCANCODE_L] = false;
				}
			}
			//cambiar//
			if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN)
			{
				current_animation = &forward;

				speed.x = -2.5f;
				playerCollider->rect.h = 108;
				if (keyup[SDL_SCANCODE_J]) {
					StoreInput(SDL_SCANCODE_J);
					if (!flip) { block = App->collision->AddCollider({ position.x + 60, position.y + 5, 10, 30 }, COLLIDER_WALL, this); }
					keyup[SDL_SCANCODE_J] = false;
				}
			}

			/*if (App->input->keyboard[SDL_SCANCODE_A] && App->input->keyboard[SDL_SCANCODE_A])
			{
				current_animation = &doubleback;
				speed.x = -1.5f;
				playerCollider->rect.h = 108;
				if (keyup[SDL_SCANCODE_A]) {
					StoreInput(SDL_SCANCODE_A);
					if (!flip) { block = App->collision->AddCollider({ position.x + 50, position.y + 5, 10, 30 }, COLLIDER_WALL, this); }
					keyup[SDL_SCANCODE_A] = false;
				}
			}*/

			if ((TestSpecial(SDL_SCANCODE_L, SDL_SCANCODE_L)))
			{
				current_animation = &doubleback;
				playerCollider->rect.h = 108;
				speed.x = -1.5f;
			}

			if ((TestSpecial(SDL_SCANCODE_J, SDL_SCANCODE_J)))
			{
				current_animation = &doubleforward;
				playerCollider->rect.h = 108;
				speed.x = 1.5f;
			}

			if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_DOWN) {
				current_animation = &jump;
				jumping = JUMP_UP;
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Jump.wav"));

				if (keyup[SDL_SCANCODE_I]) {
					StoreInput(SDL_SCANCODE_I);
					keyup[SDL_SCANCODE_I] = false;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_U] == KEY_STATE::KEY_DOWN && !leaveif && keyup[SDL_SCANCODE_U]) {
				current_animation = &punch;



				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Punch_Attack.wav"));
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Punch.wav"));


				if (!flip) melee = App->collision->AddCollider({ position.x + 50, position.y + 15, 40, 20 }, COLLIDER_PLAYER2_ATTACK, this, 10);
				if (flip) melee = App->collision->AddCollider({ position.x - 15, position.y + 15, 40, 20 }, COLLIDER_PLAYER2_ATTACK, this, 10);
				leaveif = true;
				if (keyup[SDL_SCANCODE_U]) {
					StoreInput(SDL_SCANCODE_U);
					keyup[SDL_SCANCODE_U] = false;
				}
			}

			if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN && !leaveif && keyup[SDL_SCANCODE_O]) {
				current_animation = &kick;

				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/FIGHT/Punch_Attack.wav"));
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Kick_Groan.wav"));

				if (!flip) melee = App->collision->AddCollider({ position.x + 50, position.y, 60, 40 }, COLLIDER_PLAYER2_ATTACK, this, 20);
				if (flip) melee = App->collision->AddCollider({ position.x + -50, position.y, 60, 40 }, COLLIDER_PLAYER2_ATTACK, this, 20);
				if (keyup[SDL_SCANCODE_O]) {
					StoreInput(SDL_SCANCODE_O);
					keyup[SDL_SCANCODE_O] = false;
				}
			}

			if ((TestSpecial(SDL_SCANCODE_O, SDL_SCANCODE_U, SDL_SCANCODE_L, SDL_SCANCODE_K) || App->input->keyboard[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN) && !leaveif && (stamina >= 15)) {
				current_animation = &koukenR;
				App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Kooken.wav"));
				App->particles->AddParticle(App->particles->kouken, position.x, position.y, COLLIDER_PLAYER2_ATTACK);
				App->audio->PlayChunk(App->audio->chunks[0]);
				stamina -= 15;
			}


		}
	}
	if (hp <= 0 && App->player->p1Won != true)
	{
		hp = 0;
		current_animation = &defeat;

		App->player->p1Won = true;
		App->player->playersMove = false;
		App->audio->PlayChunk(App->audio->LoadChunk("RESOURCES/MUSIC_FXS/FXS/RYO/RYO_VOICE_FXS/Ryo_Knocked.wav"));
		playerCollider->to_delete = true;
	}

	if (stamina <= 0)
	{
		stamina = 0;
	}


	//Jumping movement--------------------------------------------
	if (jumping != JUMP_NOT)
	{
		speed.y = (-1)*(8 + -0.5 * clock_parabolla);
		clock_parabolla++;
		playerCollider->SetPos(position.x, position.y - 33);
		playerCollider->rect.h = 70;
		if (jumping == JUMP_DOWN)
		{
			//speed.y = 3;

			if (position.y >= 112) {
				jumping = JUMP_NOT;
				position.y = 112;
				speed.y = 0;
				clock_parabolla = 0;
			}
		}
		if (jumping == JUMP_UP)
		{
			//speed.y = -3;

			if (current_animation->current_frame >= 2.5f) {
				jumping = JUMP_DOWN;
			}
		}
	}
	if (current_animation == &doubleback)
	{
		speed.x = 6.0f;
		playerCollider->SetPos(position.x, position.y + 33);
		playerCollider->rect.h = 75;
	}
	if (current_animation == &doubleforward)
	{
		speed.x = -6.0f;
		playerCollider->SetPos(position.x, position.y + 33);
		playerCollider->rect.h = 75;
	}


	//Keep character within limits-----------------------------
	position.x += speed.x;
	position.y += speed.y;
	if (position.x <= 0) {
		position.x = 0;
	}
	if (position.x + playerCollider->rect.w >= 538) {
		position.x = 538 - playerCollider->rect.w;
	}
	if (position.x <= (App->player->position.x + (App->player2->playerCollider->rect.w / 2) + App->player2->position.x + (App->player->playerCollider->rect.w / 2)) / 2 - SCREEN_WIDTH / 2) {
		position.x = (App->player->position.x + (App->player2->playerCollider->rect.w / 2) + App->player2->position.x + (App->player->playerCollider->rect.w / 2)) / 2 - SCREEN_WIDTH / 2;
	}
	if (position.x + playerCollider->rect.w >= (App->player->position.x + (App->player2->playerCollider->rect.w / 2) + App->player2->position.x + (App->player->playerCollider->rect.w / 2)) / 2 + SCREEN_WIDTH / 2) {
		position.x = (App->player->position.x + (App->player2->playerCollider->rect.w / 2) + App->player2->position.x + (App->player->playerCollider->rect.w / 2)) / 2 + SCREEN_WIDTH / 2 - playerCollider->rect.w;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();
	if (App->player->p2Won == true)
	{
		current_animation = &victory;
	}
	App->render->Blit(graphics, position.x + current_animation->GetOffset().x, position.y + current_animation->GetOffset().y, &r, 1.0f, flip);
	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* A, Collider* B) {
	if (A->type == COLLIDER_PLAYER2_ATTACK && B->type == COLLIDER_PLAYER1)//Player2 lands hit on Player1
	{
		if (current_animation != &damaged)
		{
			if (!App->player->godMode) { App->player->hp -= A->damage; }
			if (!flip) App->player->position.x += 15;
			if (flip) App->player->position.x -= 15;
			App->player->current_animation = &damaged;
		}
		App->particles->AddParticle(App->particles->hit, App->player->position.x + App->player->playerCollider->rect.w - 12, A->rect.y + A->rect.h / 2, COLLIDER_NONE, 0);
		A->to_delete = true;
	}
	if (A->type == COLLIDER_PLAYER2 && B->type == COLLIDER_PLAYER1)
	{
		if (B->rect.x >= playerCollider->rect.x)
		{
			if (current_animation == &sp1 || current_animation == &sp2 || 
				App->player->current_animation == &sp1 || App->player->current_animation == &sp2) {
				
				App->player->position.x += 4;
			}
			else App->player->position.x += 2;
		}
		//Coliding from the left
		if (B->rect.x <= playerCollider->rect.x)
		{
			if (current_animation == &sp1 || current_animation == &sp2 || App->player->current_animation == &sp1 || App->player->current_animation == &sp2) {
				App->player->position.x -= 4;
			}
			else App->player->position.x -= 2;
		}
	}
	if (A->type == COLLIDER_WALL && B->type == COLLIDER_PLAYER2_ATTACK)
	{
		position.x -= 15;
		B->to_delete = true;
	}

}

bool ModulePlayer2::TestSpecial(SDL_Scancode A, SDL_Scancode B, SDL_Scancode C, SDL_Scancode D)
{
	int interval = 500;
	int d = inputCount - 1;
	if (inputCount == 0) d = MAX_INPUTS - 1;
	if (D == SDL_SCANCODE_UNKNOWN && C == SDL_SCANCODE_UNKNOWN) {
		for (int i = inputCount; 1; i++) {
			if (i == (MAX_INPUTS)) i = 0;
			int j = i - 1;
			if (i == 0) { j = MAX_INPUTS - 1; }
			if (input[i] == A && input[j] == B) {
				if ((timeInput[i] - timeInput[j]) < interval) {

					for (int p = 0; p < MAX_INPUTS; p++) {
						input[p] = 0;
						timeInput[p] = 0;
					}
					inputCount = 0;
					return true;
				}
			}
			if (i == d) break;
		}
	}
	else if (D == SDL_SCANCODE_UNKNOWN) {
		for (int i = inputCount; 1; i++) {

			if (i == (MAX_INPUTS)) i = 0;

			int j = i - 1; int k = i - 2;


			if (i == 1) { k = MAX_INPUTS - 1; }
			if (i == 0) { k = MAX_INPUTS - 2; j = MAX_INPUTS - 1; }

			if (input[i] == A && input[j] == B && input[k] == C) {

				if ((timeInput[i] - timeInput[j]) < interval &&
					(timeInput[j] - timeInput[k]) < interval) {
					for (int p = 0; p < MAX_INPUTS; p++) {
						input[p] = 0;
						timeInput[p] = 0;
					}
					inputCount = 0;
					return true;
				}
			}
			if (i == d) break;
		}
	}
	else {
		for (int i = inputCount; 1; i++) {

			if (i == (MAX_INPUTS)) i = 0;

			int j = i - 1; int k = i - 2; int l = i - 3;

			if (i == 2) { l = MAX_INPUTS - 1; }
			if (i == 1) { l = MAX_INPUTS - 2; k = MAX_INPUTS - 1; }
			if (i == 0) { l = MAX_INPUTS - 3; k = MAX_INPUTS - 2; j = MAX_INPUTS - 1; }

			if (input[i] == A && input[j] == B &&
				input[k] == C && input[l] == D) {

				if ((timeInput[i] - timeInput[j]) < interval &&
					(timeInput[j] - timeInput[k]) < interval &&
					(timeInput[k] - timeInput[l]) < interval) {

					for (int p = 0; p < MAX_INPUTS; p++) {
						input[p] = 0;
						timeInput[p] = 0;
					}

					inputCount = 0;
					return true;

				}
			}
			if (i == d) break;
		}
	}
	return false;
}



bool ModulePlayer2::CleanUp() {

	SDL_DestroyTexture(graphics);

	if (playerCollider != nullptr) playerCollider->to_delete = true;

	return true;

}
