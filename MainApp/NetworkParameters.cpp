#include "StdAfx.h"

#include <iostream>
#include "NetworkParameters.h"

using namespace std;

NetworkParameters::NetworkParameters(void)
{
	Iterations = 10;
    GapLatency = 2;
    NumOfNeurons = 3;
    NumOfSynapses = 3;
    ActivationThreshold = 0.5;
	InputNeurons = 1;
}


NetworkParameters::~NetworkParameters(void)
{
}

void NetworkParameters::Print()
{
    cout << "Network Parameters:" << endl;
    cout << "Iterations: " << Iterations << endl;
    cout << "GapLatency: " << GapLatency << endl;
    cout << "NumOfNeurons: " << NumOfNeurons << endl;
    cout << "NumOfSynapses: " << NumOfSynapses << endl;
    cout << "ActivationThreshold: " << ActivationThreshold << endl;

    cout << endl;
}
