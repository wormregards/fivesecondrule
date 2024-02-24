#include "../header/camera.h"

Camera2D camera;
Camera2D getCamera(Vector2 camPos) {
	camera.target = camPos;
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	return camera;
}
static void setCameraTarget(Vector2 camPos) {
	camera.target = camPos;
	camera.offset = (Vector2){ GetScreenWidth() / 2, GetScreenHeight() / 2 };
}