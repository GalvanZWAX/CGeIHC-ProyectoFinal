#include "StaticCamera.h"

StaticCamera::StaticCamera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startMoveSpeed, GLfloat startTurnSpeed)
{
    position = startPosition;
    worldUp = startUp;

    // �ngulo de rotaci�n sobre el eje X-Z (inclinaci�n vertical)
    GLfloat angleX = glm::radians(45.0f);

    // �ngulo de rotaci�n sobre el eje Y-Z (giro horizontal)
    GLfloat angleY = glm::radians(0.0f); // Ejemplo: 30 grados

    // Rotaci�n combinada utilizando ambas transformaciones
    front = glm::vec3(
        -cos(angleX) * sin(angleY),  // Componente X
        -sin(angleX),               // Componente Y
        cos(angleX) * cos(angleY)   // Componente Z
    );

    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}


glm::mat4 StaticCamera::calculateViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

glm::mat4 StaticCamera::calculateProjectionMatrix(GLfloat width, GLfloat height)
{
    // Usamos una proyecci�n ortogr�fica para mantener la c�mara isom�trica.
    GLfloat aspect = width / height;
    GLfloat orthoSize = 10.0f; // Tama�o de la vista ortogr�fica
    return glm::ortho(-orthoSize * aspect, orthoSize * aspect, -orthoSize, orthoSize, 0.1f, 100.0f);
}

glm::vec3 StaticCamera::getCameraPosition()
{
    return position;
}

glm::vec3 StaticCamera::getCameraDirection()
{
    return glm::normalize(front);
}

StaticCamera::~StaticCamera() {}
