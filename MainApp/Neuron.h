#pragma once

#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <list>

#include "NetworkParameters.h"
#include "Synapse.h"

using std::list;

class Neuron
{
public:
	Neuron(int id);
	Neuron(int id, const NetworkParameters &networkParameters, const float impulseValue);
	~Neuron(void);

	void Initialize(const NetworkParameters &networkParameters, const float impulseValue);
		
	const bool 					get_IsInitialized();
	const NetworkParameters* 	get_NetworkParameters();
	const float 				get_ImpulseValue();
	const float 				get_ChargeValue();
	const int					get_Id();

    // call this function to add a synapse to the current neuron
    void AddSynapse(const class Synapse &synapse);
    // neuron receives charge from dendrite (synapse) by using this function
    void ReceiveCharge(const float value);
    /*
    Neuron state update function. Should be called from the network manager.
    Returns true if neuron activates and false otherwise
    */
    bool Update();
		

private:
	// neuron id
	const int m_id;
    // neuron is initialized if we call the constructor with parameters or call the initialize function
    bool m_isInitialized;
    // all parameters
    const NetworkParameters *m_parameters;
    // value passed when activated
    float m_impulseValue;
    // Actual neuron charge
    float m_chargeValue;
    // axonal synapses
    list<Synapse*> *m_synapses;
		
    // Neuron activation function. Should be called from the Update function
    void ActivateAxon();
    // Function used to decay the charge value
    void Rest();
};

#endif // NEURON_H