#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	temp;

	i = 8;
	temp = c;
	while (i > 0)
	{
		i--;
		temp = c >> i;
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}
void	handle_read_receipt(int signal)
{
	(void)signal;
	ft_printf("Received bit\n");
}
int main(int argc, char *argv[])
{
	pid_t		server_pid;
	const char	*message;
	int			i;
	
	signal(SIGUSR1, handle_read_receipt);
	signal(SIGUSR2, handle_read_receipt);
	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(server_pid, message[i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
