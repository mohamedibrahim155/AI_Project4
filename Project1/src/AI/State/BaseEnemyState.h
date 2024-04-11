#pragma once
#include "eEnemyState.h"
class BaseEnemyState
{
public:

	virtual void StartState() = 0;
	virtual void UpdateState() = 0;
	virtual void EndState() = 0;
	virtual void OnChangeState(eEnemyState state);

};

