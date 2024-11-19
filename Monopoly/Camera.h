#pragma once

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <glfw3.h>

class Camera
{
public:
    Camera();
    Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

    void keyControl(bool* keys, GLfloat deltaTime);
    void switchCamera(bool& isStaticCamera, bool& isFollowCamera, bool& isMainCamera, bool* keys);
    void mouseControl(GLfloat xChange, GLfloat yChange);

    glm::vec3 getCameraPosition();
    glm::vec3 getCameraDirection();
    glm::mat4 calculateViewMatrix();

    ~Camera();

private:
    glm::vec3 position;
    glm::vec3 initialPosition;  // Nueva variable para almacenar la posici�n inicial
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    GLfloat yaw;
    GLfloat pitch;

    GLfloat moveSpeed;
    GLfloat turnSpeed;

    void update();
};