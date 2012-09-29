#include "StdAfx.h"
#include "Synapse.h"

void Synapse::Activate(float impulseValue)
{
    this -> m_currentGapLatency = this -> m_parameters -> GapLatency;
    this -> m_currentGapValue = impulseValue;
}

void Synapse::Update()
{
    if (this -> m_currentGapLatency == 1)
    {
        this -> m_postSynapticNeuron -> ReceiveCharge(m_currentGapValue * m_synapseStrength);
    }

    if (this -> m_currentGapLatency > 0)
    {
        this -> m_currentGapLatency -= 1;
    }
}

void Synapse::NotifyPostSynapticNeuronActivation()
{

}

Synapse& Synapse::operator=(const Synapse &rhs)
{
    this -> m_currentGapLatency = rhs.m_currentGapLatency;
    this -> m_currentGapValue = rhs.m_currentGapValue;
    this -> m_synapseStrength = rhs.m_synapseStrength;

    return *this;
}

bool Synapse::operator==(const Synapse &rhx) const
{
    return
        this -> m_currentGapLatency == rhx.m_currentGapLatency
        && this -> m_currentGapValue == rhx.m_currentGapValue
        && this -> m_synapseStrength == rhx.m_synapseStrength;

}

bool Synapse::operator<(const Synapse &rhs) const
{
    if(this -> m_currentGapLatency == rhs.m_currentGapLatency
       && this -> m_currentGapValue == rhs.m_currentGapValue
       && this -> m_synapseStrength < rhs.m_synapseStrength)
       {
           return true;
       }

    if(this -> m_currentGapLatency == rhs.m_currentGapLatency
       && this -> m_currentGapValue < rhs.m_currentGapValue)
       {
           return true;
       }

    if(this -> m_currentGapLatency < rhs.m_currentGapLatency)
       {
           return true;
       }

    return false;
}

bool Synapse::get_IsInitialized()
{
	return this -> m_isInitialized;
}

NetworkParameters* Synapse::get_NetworkParameters()
{
	return this -> m_parameters;
}

Neuron* Synapse::get_PostSynapticNeuron()
{
	return this -> m_postSynapticNeuron;
}

Synapse::Synapse()
{
	this -> m_isInitialized = false;
}

Synapse::Synapse(NetworkParameters *parameters, Neuron *postSynapticNeuron)
    :m_parameters(parameters),
     m_postSynapticNeuron(postSynapticNeuron)
{
    this -> m_isInitialized = true;
}

Synapse::Synapse(const Synapse& copyIn)
{
    this -> m_parameters = copyIn.m_parameters;
    this -> m_postSynapticNeuron = copyIn.m_postSynapticNeuron;

    this -> m_currentGapLatency = copyIn.m_currentGapLatency;
    this -> m_currentGapValue = copyIn.m_currentGapValue;
    this -> m_synapseStrength = copyIn.m_synapseStrength;
}

Synapse::~Synapse()
{
    //dtor
}
