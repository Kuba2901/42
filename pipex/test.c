// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
 
// int main()
// {
// 	int fd[2];
// 	pid_t pid;
// 	char buffer[13];
 
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	if (pid == 0)
// 	{
// 		close(fd[0]); // close the read end of the pipe
// 		write(fd[1], "Hello parent!", 13);
// 		close(fd[1]); // close the write end of the pipe
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(fd[1]); // close the write end of the pipe
// 		read(fd[0], buffer, 13);
// 		close(fd[0]); // close the read end of the pipe
// 		printf("Message from child: '%s'\n", buffer);
// 		exit(EXIT_SUCCESS);
// 	}
// }

#include <unistd.h>
#include <stdio.h>
#include <libft.h>

int main(int ac, char **av)
{
	char *args[3];
	
	char **split = ft_split(av[1], ' ');
	while (*split)
	{
		ft_p
	}
	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}

