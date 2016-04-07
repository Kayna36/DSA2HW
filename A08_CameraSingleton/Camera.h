#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "RE\ReEngAppClass.h"

class Camera
{

private:
	//Matrices
	matrix4 m_m4Projection;
	matrix4 m_m4View;

	//Vectors
	vector3 cam_v3Position = glm::vec3(0.0f, 0.0f, 15.0f);
	vector3 cam_v3Target = vector3(0.0f, 0.0f, 0.0f);
	vector3 cam_v3Top = vector3(0.0f, 1.0f, 0.0f);

	vector3 cam_v3Forward = vector3(0.0f, 0.0f, -1.0f);
	vector3 cam_v3Upward = vector3(0.0f, 1.0f, 0.0f);
	vector3 cam_v3Rightward = vector3(1.0f, 0.0f, 0.0f);

	vector3 cam_v3PitchYawRoll = vector3(0.0f);

	glm::mat4 rotationMat;

public:
	Camera();
	~Camera();

	static Camera* GetInstance();
	static void ReleaseInstance();

	matrix4 GetView(void); //View Matrix
	matrix4 GetProjection(bool bOrtographic); //Projection Matrix
	void SetPosition(vector3 v3Position); //Sets the position of the camera
	void SetTarget(vector3 v3Target); //sets the target of the camera
	void SetUp(vector3 v3Up); //sets the up vector of the camera
	void MoveForward(float fIncrement); //Move the camera forward (or backwards) dep. on the view vector
	void MoveSideways(float fIncrement); //Move the camera based on the right vector dep. on the view vector
	void MoveVertical(float fIncrement);//Move the camera up/down depending on the up vector
	void ChangePitch(float fIncrement); //orient your camera (meaning the forward and up vectors) changing its angle in X
	void ChangeRoll(float fIncrement); //orient your camera (meaning the forward and up vectors) chaning its angle in Z
	void ChangeYaw(float fIncrement); //Orient your camera (meaning the forwars and up vectors) changing its angle in Y
};

#endif // !_CAMERA_H_
