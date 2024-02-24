#pragma once
#include "raylib.h"
#ifndef CAKE_H
#define CAKE_H

extern Texture2D cakeSprite;
extern Rectangle cakeFrameRect;
extern Rectangle cakeCollider;
extern unsigned int totalCakeFrames;
extern Vector2 cakePosition;
Rectangle getCakeFrameRect();
Texture2D getCakeSprite();
Vector2 getCakePosition();
void setCakePosition(float x, float y);

Rectangle getCakeCollider();
#endif