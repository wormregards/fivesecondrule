#include "../header/player.h"
#include "../assets/playerSprite.h"
#include "../header/controls.h"

Texture2D playerSprite;
Rectangle playerFrameRect;
unsigned int totalPlayerFrames = 9;
Rectangle playerCollider;
Vector2 playerPosition;
struct SpriteDirection spriteDirecton;

Texture2D getPlayerSprite() {
	Image playerImage = {
	   .data = PLAYERSPRITE_DATA,
	   .width = PLAYERSPRITE_WIDTH,
	   .height = PLAYERSPRITE_HEIGHT,
	   .format = PLAYERSPRITE_FORMAT,
	   .mipmaps = 1
	};

	playerSprite = LoadTextureFromImage(playerImage);
	playerCollider.x = playerPosition.x;
	playerCollider.y = playerPosition.y;
	playerCollider.width = PLAYERSPRITE_WIDTH / totalPlayerFrames;
	playerCollider.height = PLAYERSPRITE_HEIGHT;

	return playerSprite;
}

Rectangle getPlayerFrameRect() {
	playerFrameRect.x = 0.0f;
	playerFrameRect.y = 0.0f;

	playerFrameRect.width = PLAYERSPRITE_WIDTH / totalPlayerFrames;
	playerFrameRect.height = PLAYERSPRITE_HEIGHT;
	return playerFrameRect;
}

Vector2 getPlayerPosition() {
	return playerPosition;
}

void setPlayerPosition(float x, float y) {
	// sprite pos
	playerPosition.x = x;
	playerPosition.y = y;
}



void handlePlayerMovement(float speed, float deltaTime) {

	if (getControls().right) {
		spriteDirecton.right = true;
		spriteDirecton.left = false;
		playerPosition.x += speed * deltaTime;
		setPlayerPosition(playerPosition.x, playerPosition.y);
	}

	if (getControls().left) {
		if (playerFrameRect.width != -47.0f) {
			playerFrameRect.width = -47.0f;
		}
		spriteDirecton.right = false;
		spriteDirecton.left = true;
		playerPosition.x -= speed * deltaTime;
		setPlayerPosition(playerPosition.x, playerPosition.y);
	}

	if (getControls().up) {
		playerPosition.y -= speed * deltaTime;
		setPlayerPosition(playerPosition.x, playerPosition.y);
	}

	if (getControls().down) {
		playerPosition.y += speed * deltaTime;
		setPlayerPosition(playerPosition.x, playerPosition.y);
	}


}

Rectangle getPlayerCollider() {
	// collider pos
	playerCollider.x = playerPosition.x;
	playerCollider.y = playerPosition.y;
	return playerCollider;
}