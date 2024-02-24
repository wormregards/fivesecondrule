#pragma once
#include "raylib.h"
#ifndef CAMERA_H
#define CAMERA_H

extern Camera2D camera;
Camera2D getCamera(Vector2 camPos);
static void setCameraTarget(Vector2 camPos);

#endif
