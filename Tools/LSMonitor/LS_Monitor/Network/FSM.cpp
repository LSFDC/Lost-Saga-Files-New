
#include "../stdafx.h"
#include "FSM.h"

FSM::FSM()
{
	InitState();
}

void FSM::InitState()
{
	m_iState = MAGIC_TOKEN_FSM;
}

bool FSM::IsFirst()
{
	if( MAGIC_TOKEN_FSM == m_iState )
		return true;

	return false;
}

int FSM::GetState()
{
	return m_iState;
}

void FSM::SetState(int iState)
{
	m_iState = iState;
}

void FSM::UpdateState()
{
	if( !IsFirst() )
	{
		m_iState = ( (~m_iState) + 5371 ) * 31;
		m_iState = m_iState ^ ( m_iState >> 16);

		if( m_iState < 0 )
			m_iState = -m_iState;
	}
}

