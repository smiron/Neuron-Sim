#pragma once

#ifndef SYNAPSE_H
#define SYNAPSE_H

#include "NetworkParameters.h"
#include "Neuron.h"
#include "NetworkParameters.h"

class Synapse
{
public:
	public:
		Synapse();
        Synapse(class NetworkParameters *parameters, class Neuron *postSynapticNeuron);
        Synapse(const Synapse &);
        virtual ~Synapse();

		void Initialize(class NetworkParameters *parameters, class Neuron *postSynapticNeuron);

        void Activate(float impulseValue);
        void Update();
		
		bool get_IsInitialized();
		NetworkParameters* get_NetworkParameters();
		Neuron* get_PostSynapticNeuron();

        Synapse& operator=(const Synapse &rhs);
        bool operator==(const Synapse &rhx) const;
        bool operator<(const Synapse &rhx) const;

    private:
		bool m_isInitialized;
        // all parameters
        NetworkParameters *m_parameters;
        // neuron that received the charge
        class Neuron *m_postSynapticNeuron;
        int m_currentGapLatency;
        float m_currentGapValue;
        float m_synapseStrength;

        // function called by PostSynaptic neuron when activated (for synapse plasticity)
        void NotifyPostSynapticNeuronActivation();
};

#endif // SYNAPSE_H
