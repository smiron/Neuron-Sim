#include "StdAfx.h"
#include "NeuronConnection.h"

const int NeuronConnection::get_SourceNeuronId()
{
	return this -> m_sourceNeuronId;
}

const int NeuronConnection::get_DestinationNeuronId()
{
	return this -> m_destinationNeuronId;
}

NeuronConnection::NeuronConnection(const int sourceNeuronId, const int destinationNeuronId)
	:m_sourceNeuronId(sourceNeuronId),
	m_destinationNeuronId(destinationNeuronId)
{
}

NeuronConnection::~NeuronConnection()
{
}
