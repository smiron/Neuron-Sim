#pragma once

#ifndef NETWORKPARAMETERS_H
#define NETWORKPARAMETERS_H

#include <iostream>

class NetworkParameters
{
public:
	NetworkParameters();
    virtual ~NetworkParameters();

	void Print();

    int		Iterations;
    int		GapLatency;
    int		NumOfNeurons;
    int		NumOfSynapses;
    float	ActivationThreshold;
	int		InputNeurons;
};

#endif // NETWORKPARAMETERS_H