#include "../header/cake.h"
#include "../assets/cakeSprite.h"

Texture2D cakeSprite;
Rectangle cakeFrameRect;
Rectangle cakeCollider;
Vector2 cakePosition;
unsigned int totalCakeFrames = 1;
Texture2D getCakeSprite() {
	Image cakeImage = {
	   .data = CAKESPRITE_DATA,
		.width = CAKESPRITE_WIDTH,
		.height = CAKESPRITE_HEIGHT,
		.format = CAKESPRITE_FORMAT,
		.mipmaps = 1
	};

	Texture2D cakeTexture = LoadTextureFromImage(cakeImage);
	cakePosition.x = 100.0f;
	cakePosition.y = 0.0f;

	cakeCollider.x = cakePosition.x;
	cakeCollider.y = cakePosition.y;
	cakeCollider.width = 60;
	cakeCollider.height = 60;

	return cakeTexture;
}

Rectangle getCakeFrameRect() {
	Rectangle cakeRect = { 0.0f, 0.0f, CAKESPRITE_WIDTH / totalCakeFrames, CAKESPRITE_HEIGHT };
	return cakeRect;
}

Vector2 getCakePosition() {
	return cakePosition;
}

void setCakePosition(float x, float y) {
	// cake pos
	cakePosition.x = x;
	cakePosition.y = y;
}

Rectangle getCakeCollider() {
	// cake collider
	cakeCollider.x = cakePosition.x + 15;
	cakeCollider.y = cakePosition.y + 15;
	return cakeCollider;
}