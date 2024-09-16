#include "Server.h"
#include <iostream>
#include <string>


void Server::run()
{
	std::thread communicatorTh(&Communicator::startHandleRequests, &m_communicator);
	communicatorTh.detach();


	std::string command = "";
	while (true)
	{
		std::cin >> command;
		if (command == "Hello") std::cout << "Hello client!";
		else if (command == "EXIT") exit(1);
	}

}



Server::Server()
	:m_communicator(Communicator::getInstance())
{
}
