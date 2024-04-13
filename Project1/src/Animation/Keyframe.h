#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/easing.hpp>
#include <vector>
#include <functional>
enum class EasingType
{
	Linear,
	sineEaseIn,
	sineEaseOut,
	sineEaseInOut
};


struct PositionKeyFrame
{
	PositionKeyFrame() {};
	PositionKeyFrame(const glm::vec3& _position, float _time, EasingType _easeType = EasingType::Linear) :
		position(_position),
		time(_time),
		easeType(_easeType)
	{
	}

	glm::vec3 position{ 0 };
	EasingType easeType = EasingType::Linear;
	float time = 0;

};



struct RotationKeyFrame
{
	RotationKeyFrame() {}
	RotationKeyFrame(const glm::quat& _rotation, float _time, EasingType _easeType = EasingType::Linear) :
		rotation(_rotation),
		time(_time),
		easeType(_easeType)
	{
	}

	RotationKeyFrame(const glm::vec3& _rotation, float _time, EasingType _easeType = EasingType::Linear) :
		rotation_vec3(_rotation),
		time(_time),
		easeType(_easeType)
	{
	}

	glm::quat rotation = glm::quat(1, 0, 0, 1);
	glm::vec3 rotation_vec3 = glm::vec3(0);
	EasingType easeType = EasingType::Linear;
	float time = 0;

};



struct ScaleKeyFrame
{
	ScaleKeyFrame() {}
	ScaleKeyFrame(const glm::vec3& _scale, float _time, EasingType _easeType = EasingType::Linear) :
		scale(_scale),
		time(_time),
		easeType(_easeType)
	{
	}

	glm::vec3 scale{ 0 };
	EasingType easeType = EasingType::Linear;
	float time = 0;

};

struct ColorKeyFrame
{
	ColorKeyFrame(const glm::vec3& _color, float _time, EasingType _easeType = EasingType::Linear) :
		color(_color),
		time(_time),
		easeType(_easeType)
	{}

	glm::vec3 color;
	EasingType easeType = EasingType::Linear;
	float time;
};

struct EventKeyFrame
{
	EventKeyFrame(double _time, std::function<void()> OnEventCallback) : time(_time), callBack(OnEventCallback)
	{
	}

	double time;
	std::function<void()> callBack;
	bool isEventTriggered = false;
};