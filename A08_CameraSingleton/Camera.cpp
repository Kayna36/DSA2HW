#include "Camera.h"
#include <math.h>
#include <stdio.h>

static Camera* instanceCam;

Camera::Camera()
{

}

Camera::~Camera()
{
	ReleaseInstance();
}

Camera* Camera::GetInstance()
{
	if (instanceCam == nullptr)
	{
		instanceCam = new Camera();
	}
	return instanceCam;
}

void Camera::ReleaseInstance()
{
	if (instanceCam != nullptr)
	{
		delete instanceCam;
		instanceCam = nullptr;
	}
}

matrix4 Camera::GetView(void)
{
	//m_m4View = glm::lookAt(glm::vec3(0.0f, 0.0f, 15.0f), glm::vec3(0.0f, 0.0f, 14.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	m_m4View = glm::lookAt(cam_v3Position, cam_v3Position + cam_v3Forward, cam_v3Upward);
	m_m4View *= rotationMat;
	return m_m4View;
}

matrix4 Camera::GetProjection(bool bOrtographic)
{
	if (bOrtographic) {
		m_m4Projection = glm::ortho(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	}
	else {
		m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	}
	return m_m4Projection;
}

void Camera::SetPosition(vector3 v3Position)
{
	cam_v3Position = v3Position;
}

void Camera::SetTarget(vector3 v3Target)
{
	cam_v3Target = v3Target;
}

void Camera::SetUp(vector3 v3Up)
{
	cam_v3Top = v3Up;
}

void Camera::MoveForward(float fIncrement)
{
	cam_v3Position.z += fIncrement;
}

void Camera::MoveSideways(float fIncrement)
{
	cam_v3Position.x += fIncrement;
}

void Camera::MoveVertical(float fIncrement)
{
	cam_v3Position.y += fIncrement;
}

void Camera::ChangePitch(float fIncrement)
{
	quaternion rotationChange = glm::quat(vector3(fIncrement, 0.0f, 0.0f));
	rotationMat *= glm::mat4_cast(rotationChange);
}

void Camera::ChangeRoll(float fIncrement)
{
	quaternion rotationChange = glm::quat(vector3(0.0f, 0.0f, fIncrement));
	rotationMat *= glm::mat4_cast(rotationChange);
}

void Camera::ChangeYaw(float fIncrement)
{
	quaternion rotationChange = glm::quat(vector3(0.0f, fIncrement, 0.0f));
	rotationMat *= glm::mat4_cast(rotationChange);
}
