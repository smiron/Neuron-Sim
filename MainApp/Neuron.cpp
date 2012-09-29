#include "StdAfx.h"
#include "Neuron.h"

void Neuron::ActivateAxon()
{
    list<Synapse*>::iterator iterator;

    for (iterator = this -> m_synapses -> begin(); iterator != this -> m_synapses -> end(); ++iterator)
    {
		Synapse* synapse = (Synapse*)*iterator;
        synapse -> Activate(this -> m_impulseValue);
    }

    //---------TO-DO---------------
    this -> m_chargeValue = 0;
    //-----------------------------
}

// neuron receives charge from dendrite (synapse) by using this function
void Neuron::ReceiveCharge(float value)
{
    this -> m_chargeValue += value;
}

void Neuron::AddSynapse(const Synapse &newSynapse)
{
    this -> m_synapses -> push_back((Synapse*)&newSynapse);
}

bool Neuron::Update()
{
    bool ret = false;

    // determine if we activate the neuron
    if (this -> m_chargeValue >= this -> m_parameters -> ActivationThreshold)
    {
        this -> ActivateAxon();
        ret = true;
    }
    else
    {
        // decay the charge value
        this -> Rest();
    }

    return ret;
}

void Neuron::Rest()
{
    //---------TO-DO---------------
    this -> m_chargeValue = this -> m_chargeValue - 0.1;
    if(this -> m_chargeValue <= 0)
    {
        this -> m_chargeValue = 0;
    }
    //-----------------------------
}

void Neuron::Initialize(const NetworkParameters &networkParameters, const float impulseValue)
{
    this -> m_parameters = &networkParameters;
    this -> m_impulseValue = impulseValue;
	
	this -> m_isInitialized = true;
}

const bool Neuron::get_IsInitialized()
{
	return this -> m_isInitialized;
}

const NetworkParameters* Neuron::get_NetworkParameters()
{
	return this -> m_parameters;
}

const float Neuron::get_ImpulseValue()
{
	return this -> m_impulseValue;
}

const float Neuron::get_ChargeValue()
{
	return this -> m_chargeValue;
}

const int Neuron::get_Id()
{
	return this -> m_id;
}

Neuron::Neuron(const int id)
    :m_id(id)
{
	m_synapses = new list<Synapse*>();
}

Neuron::Neuron(const int id, const NetworkParameters &networkParameters, const float impulseValue)
    :m_id(id),
	m_parameters(&networkParameters),
    m_impulseValue(impulseValue),
    m_chargeValue(0),
	m_isInitialized(true)
{
	m_synapses = new list<Synapse*>();
}

Neuron::~Neuron()
{
    //dtor
}
