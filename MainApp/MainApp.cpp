// MainApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <conio.h>

#include "Neuron.h"
#include "NetworkParameters.h"
#include "Manager.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	// initialize and print network parameters
    NetworkParameters *networkParameters = new NetworkParameters();

    Manager manager;
	manager.Initialize(networkParameters, new std::string("../MainApp/Connections.txt"));
	//manager.Initialize(networkParameters);

    manager.Run();
	
	vector<Neuron*>::iterator neuronIterator;

	for (neuronIterator = manager.m_neurons -> begin(); neuronIterator != manager.m_neurons -> end(); ++neuronIterator)
	{
		Neuron *neuron = ((Neuron*)*neuronIterator);
		
		cout << "Neuron Id: " << neuron -> get_Id() << " charge: " << neuron -> get_ChargeValue() << endl;
	}

	getch();

	return 0;
}

