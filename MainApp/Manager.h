#pragma once

#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

#include "NetworkParameters.h"
#include "Neuron.h"
#include "Synapse.h"

using namespace std;

class Manager
{
    public:
        Manager();
        virtual ~Manager();

        void Initialize(NetworkParameters*, string* = NULL);
        void Run();

        vector<Neuron*> *m_neurons;
        vector<Synapse*> *m_synapses;

    private:

        NetworkParameters *m_networkParameters;

        void UpdateInput();
        vector<Neuron*> UpdateNeurons();
        void UpdateSynapses();

		void CreateRandomSynapses();
		void CreateSpecificSynapses(string);
};

#endif // MANAGER_H 

