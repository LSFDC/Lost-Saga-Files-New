
#pragma once

#define MAGIC_TOKEN_FSM		-1

class FSM
{
public:
	FSM();

public:
	void InitState();
	void UpdateState();

public:
	bool IsFirst();	
	int GetState();
	void SetState(int iState);

protected:
	int m_iState;

};
