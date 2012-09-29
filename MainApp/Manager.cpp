#include "StdAfx.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>

#include "Manager.h"
#include "Neuron.h"

using namespace std;

void Manager::Initialize(NetworkParameters *networkParameters, string* fileSynapseConnections)
{
    m_networkParameters = networkParameters;

    m_networkParameters -> Print();

    cout << "Creating Random Neuron Network ..." << endl;

	// create neurons
    this -> m_neurons = new vector<Neuron*>();
	for (int neuronId = 0; neuronId < m_networkParameters -> NumOfNeurons; neuronId++)
	{
		this -> m_neurons -> push_back(new Neuron((const int)neuronId, (const NetworkParameters)*m_networkParameters, 1));
	}
	
	cout << "Created neurons." << endl;

    // create synapses
	m_synapses -> clear();
	if (fileSynapseConnections == NULL)
	{
		CreateRandomSynapses();
	}
	else
	{
		CreateSpecificSynapses(*fileSynapseConnections);
	}
}

void Manager::CreateRandomSynapses()
{
    for (int i = 0; i < m_networkParameters -> NumOfSynapses; i++)
    {
		int preSynapticNeuronIndex = rand() % m_networkParameters -> NumOfNeurons;
		int postSynapticNeuronIndex = rand() % m_networkParameters -> NumOfNeurons;
		
        Neuron *preSynapticNeuron = m_neurons -> at(preSynapticNeuronIndex);
        Neuron *postSynapticNeuron = m_neurons -> at(postSynapticNeuronIndex);

        Synapse *synapse = new Synapse(m_networkParameters, postSynapticNeuron);
		this -> m_synapses -> push_back(synapse);

        preSynapticNeuron -> AddSynapse(*synapse);
    }

    cout << "Created Synapses." << endl;

    cout << "Done." << endl;
    cout << endl;
}

void Manager::CreateSpecificSynapses(string fileSynapseConnections)
{
	ifstream connectioonsFile(fileSynapseConnections);

	if(connectioonsFile.is_open())
	{
		string line;

		while(connectioonsFile.good())
		{
			getline(connectioonsFile, line);

			std::string::const_iterator pos = std::find(line.begin(), line.end(), ' ');

			string preSynapticNeuronIdString(line.begin(), pos);
			string postSynapticNeuronIdString(pos + 1, line.end());

			int preSynapticNeuronId = atoi(preSynapticNeuronIdString.c_str());
			int postSynapticNeuronId = atoi(postSynapticNeuronIdString.c_str());

			Neuron *preSynapticNeuron = m_neurons -> at(preSynapticNeuronId);
			Neuron *postSynapticNeuron = m_neurons -> at(postSynapticNeuronId);

			Synapse *synapse = new Synapse(m_networkParameters, postSynapticNeuron);
			this -> m_synapses -> push_back(synapse);

			preSynapticNeuron -> AddSynapse(*synapse);
		}

		connectioonsFile.close();
	}
}

void Manager::Run()
{
    cout << "Neuron-Sim Started" << endl;

    for(int iteration = 0; iteration < m_networkParameters -> Iterations; iteration++)
    {
        UpdateInput();
        vector<Neuron*> neuronsFired = UpdateNeurons();
        UpdateSynapses();
		
		cout << "Iteration " << iteration << endl;
		cout << neuronsFired.size() << endl;
		for (unsigned int i = 0; i < neuronsFired.size(); ++i)
		{
			cout << "Id: " << neuronsFired.at(i) -> get_Id() << endl;
		}
		
		cout << "---------------------------------------" << endl;
    }

    cout << "Neuron-Sim Finished" << endl;
}

void Manager::UpdateInput()
{
	for (int i = 0; i < this -> m_networkParameters -> InputNeurons; ++i)
	{
		Neuron *neuron = m_neurons -> at(i);
		neuron -> ReceiveCharge(1);
	}
}

vector<Neuron*> Manager::UpdateNeurons()
{
    list<Neuron*> result;
    vector<Neuron*>::iterator iterator;

    for (iterator = m_neurons -> begin(); iterator != m_neurons -> end(); ++iterator)
    {
        // current neuron
        Neuron *neuron = (Neuron*)*iterator;

        bool neuronFired = neuron -> Update();

        if (neuronFired == true)
        {
            result.push_back(neuron);
        }
    }

    return std::vector<Neuron*>(result.begin(), result.end());
}

void Manager::UpdateSynapses()
{
    vector<Synapse*>::iterator iterator;

    for (iterator = this -> m_synapses -> begin(); iterator != this -> m_synapses -> end(); ++iterator)
    {
		Synapse *synapse = ((Synapse*)*iterator);
        synapse -> Update();
    }
}

Manager::Manager()
{
    this -> m_synapses = new vector<Synapse*>();
}

Manager::~Manager()
{
    //dtor
}

