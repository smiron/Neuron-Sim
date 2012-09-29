#include "StdAfx.h"

#include "NeuronConnectivityBase.h"
#include "NeuronConnection.h"
#include <list>

using std::list;

NeuronConnectivityBase::NeuronConnectivityBase(void)
	:m_connections(new list<NeuronConnection*>())
{
}


NeuronConnectivityBase::~NeuronConnectivityBase(void)
{
}
