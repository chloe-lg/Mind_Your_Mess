#include "Camera.h"
#include "Globals.h"

Camera::Camera(float _scrollSpeed) {
    scrollSpeed = _scrollSpeed;
    cameraY = LEVEL_HEIGHT - PLAYABLE_HEIGHT / 2.f;
    target = nullptr;

    view.setSize({ PLAYABLE_WIDTH, PLAYABLE_HEIGHT });
    view.setCenter({ PLAYABLE_WIDTH / 2.f, cameraY });
    view.setViewport(sf::FloatRect({ PLAYABLE_X / WIN_WIDTH, 0.f }, { PLAYABLE_WIDTH / WIN_WIDTH, 1.f }));
}

void Camera::update(float dt) {
    cameraY -= scrollSpeed * dt;

    if (target != nullptr) {
        float playerCenterY = target->getPos().y + target->getSize().y / 2.f;
        float targetCameraY = playerCenterY + PLAYABLE_HEIGHT * 0.15f;

        if (targetCameraY < cameraY) {
            cameraY += (targetCameraY - cameraY) * 2.2f * dt;
        }
    }

    view.setCenter({ PLAYABLE_WIDTH / 2.f, cameraY });
}

bool Camera::isCaught(GameObject* object) {
    float bottomOfScreen = cameraY + PLAYABLE_HEIGHT / 2.f;
    return object->getPos().y + object->getSize().y >= bottomOfScreen;
}

sf::View& Camera::getView() {
    return view;
}
