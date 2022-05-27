#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
 	std::string ping = "Ping";
	std::string pong = "Pong";
	while(true)
	{
		int pid = fork();
		if(pid < 0)
		{
			std::cout << "Error" << std::endl;
		}

		if(pid == 0)
		{
			sleep(1);
			std::cout << "Ping" << std::endl;
			exit(EXIT_SUCCESS);
		}

		if(pid > 0)
		{
			wait(0);
			sleep(1);
			std::cout << "Pong" << std::endl;
		}
	}
	return 0;
}
