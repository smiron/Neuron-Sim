#pragma once

#ifndef NEURONCONNECTION_H
#define NEURONCONNECTION_H

class NeuronConnection
{
public:
	const int get_SourceNeuronId();
	const int get_DestinationNeuronId();

	NeuronConnection(const int sourceNeuronId, const int destinationNeuronId);
	~NeuronConnection();
	
private:
	const int m_sourceNeuronId;
	const int m_destinationNeuronId;
};

#endif // NEURONCONNECTION_H