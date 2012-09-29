#pragma once

#ifndef NEURONCONNECTIVITYFILE_H
#define NEURONCONNECTIVITYFILE_H

#include <string>
#include "NeuronConnectivityBase.h"

using std::string;

class NeuronConnectivityFile : public NeuronConnectivityBase
{
public:
	NeuronConnectivityFile(string fileLocation);
	~NeuronConnectivityFile(void);

	void Load();
};

#endif // NEURONCONNECTIVITYFILE_H