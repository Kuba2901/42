#ifndef PIPEX_H
# define PIPEX_H

typedef enum s_bool
{
  false,
  true
} t_bool;

typedef struct s_pipex {
  int	    in_fd;
  int	    out_fd;
  t_bool  here_doc;
  t_bool  input_invalid;
  char    **cmd_paths;
  char    ***cmd_args;
  int	    cmd_count;
} t_pipex;
#endif
