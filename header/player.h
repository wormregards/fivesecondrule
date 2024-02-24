#pragma once
#include "raylib.h"
#ifndef PLAYER_H
#define PLAYER_H

extern Texture2D playerSprite;
extern Rectangle playerFrameRect;

extern unsigned int totalPlayerFrames;
extern Rectangle playerCollider;
extern Vector2 playerPosition;


Rectangle getPlayerFrameRect();
Texture2D getPlayerSprite();
Vector2 getPlayerPosition();
void setPlayerPosition(float x, float y);

void handlePlayerMovement(float speed, float deltaTime);
Rectangle getPlayerCollider();
struct SpriteDirection {
	bool left;
	bool right;
};
extern struct SpriteDirection spriteDirecton;

#endif