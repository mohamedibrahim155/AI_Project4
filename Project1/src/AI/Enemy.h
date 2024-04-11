#pragma once
#include "State/BaseEnemyState.h"
#include "../PhysX/PhysXObject.h"
class Enemy : public PhysXObject
{
public:
	Enemy();

	void DrawProperties() override;
	void SceneDraw() override;
	void Render() override;

	void Start() override;
	void Update(float deltaTime) override;
	void OnDestroy() override;

	void OnTriggerEnter(PhysXObject* otherObject) override;
	void OnTriggerStay(PhysXObject* otherObject) override {};
	void OnTriggerExit(PhysXObject* otherObject) override;

	void OnCollisionEnter(PhysXObject* otherObject, CollisionInfo& collisionInfo) override {};
	void OnCollisionStay(PhysXObject* otherObject) override {};
	void OnCollisionExit(PhysXObject* otherObject) override {};



private:

};

