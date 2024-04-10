#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <libft.h>
#include <sys/wait.h>

#define INPUT_INVALID -1

typedef enum s_bool
{
  FALSE,
  TRUE
} t_bool;

typedef struct s_cmd_args
{
	char	*cmd;
	char	**args;
}	t_cmd_args;

typedef struct s_pipex {
  int	    	in_fd;
  int	    	out_fd;
  t_bool  		here_doc;
  t_bool  		input_invalid;
  t_cmd_args	**cmd_args;
  char			**cmd_paths;
  int			cmd_count;
  char			**envp;
} t_pipex;
#endif
