#pragma once

#ifndef CONNECTIVITYBASE_H
#define CONNECTIVITYBASE_H

#include "NeuronConnection.h"
#include <list>

using std::list;

class NeuronConnectivityBase
{
public:
	NeuronConnectivityBase(void);
	~NeuronConnectivityBase(void);

	virtual void Load() = 0;

private:
	list<NeuronConnection*> *m_connections;
};

#endif // CONNECTIVITYBASE_H