#include <stdio.h>
#include "../header/player.h"
#include "../header/cake.h"
#include "../header/camera.h"
#include "../header/controls.h"

static void flipSprite(Rectangle* playerRect) {
	if (spriteDirecton.left) {
		if (playerRect->width != 47.0f) {
			playerRect->width = 47.0f;
		}
	}

	if (spriteDirecton.right) {
		if (playerRect->width != -47.0f) {
			playerRect->width = -47.0f;
		}
	}
}

int main() {
	int screenWidth = 800;
	int screenHeight = 600;
	int targetFPS = 60;
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "5 Second Rule");
	SetTargetFPS(targetFPS);
	float deltaTime = GetFrameTime();
	
	Texture2D player = getPlayerSprite();
	Rectangle playerRect = getPlayerFrameRect();

	Texture2D cake = getCakeSprite();
	Rectangle cakeRect = getCakeFrameRect();

	Camera2D camera = getCamera(getPlayerPosition());
	resetControls();
	float speed = 500;
	float maxSpawnX;
	float maxSpawnY;
	bool collision = false;

	Vector2 idleAnimation = { 0, 4 };
	Vector2 walkAnimation = { 5, 8 };
	float currentFrame = 0;
	int frameCounter = 0;
	int frameSpeed = 4;
	int score = 0;
	char scoreString[20];
	Vector2 currentAnimation = idleAnimation;
	const double timeStep = 1.0 / 60.0;
	double accumulator = 0.0;
	double currentTime = GetFrameTime();

	char text[20];
	while (!WindowShouldClose()) {
		ClearBackground((Color) { 0x17, 0x17, 0x17, 0xFF });
		deltaTime = GetFrameTime();
		double newTime = GetTime();
		double frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime;

		if (accumulator >= timeStep) {
			frameCounter++;
			accumulator -= timeStep;
		}
		if (frameCounter >= (60 / frameSpeed)) {
			frameCounter = currentAnimation.x;
			// checks if the animation was already set
			// checks if any of the buttons are being pressed
			if (controls.down || controls.up || controls.left || controls.right) {
				if (currentAnimation.x != walkAnimation.x && currentAnimation.y != walkAnimation.y) {
					currentFrame = walkAnimation.x;
					currentAnimation = walkAnimation;
				}
			}
			if (!controls.down && !controls.up && !controls.left && !controls.right)
			{
				if (currentAnimation.x != idleAnimation.x && currentAnimation.y != idleAnimation.y)
				{
					currentFrame = idleAnimation.x;
					currentAnimation = idleAnimation;
				}
			}
			currentFrame++;

			if (currentFrame > currentAnimation.y) {
				currentFrame = currentAnimation.x;
			}
			playerRect.x = currentFrame * 47;
		}

		handlePlayerMovement(speed, deltaTime);
		collision = CheckCollisionRecs(getPlayerCollider(), getCakeCollider());
		if (collision) {
			maxSpawnX = GetScreenWidth() / 2;
			maxSpawnY = GetScreenHeight() / 2;
			setCakePosition(GetRandomValue(0, maxSpawnX), GetRandomValue(0, maxSpawnY));
			score += 1;
 		}

		camera.target = getPlayerPosition();
		camera.offset = (Vector2){ GetScreenWidth() / 2, GetScreenHeight() / 2 };
		flipSprite(&playerRect);

		BeginMode2D(camera);
			DrawTextureRec(cake, cakeRect, getCakePosition(), WHITE);
			DrawTextureRec(player, playerRect, getPlayerPosition(), WHITE);
		EndMode2D();
		
		snprintf(text, sizeof(text), "Score: %d", score);
		DrawText(text, 20, 20, 30, WHITE);
 
		EndDrawing();
	}
	CloseWindow();
	UnloadTexture(getPlayerSprite());
	UnloadTexture(getCakeSprite());

	return 0;
}

