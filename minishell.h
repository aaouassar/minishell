/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:23:46 by aaouassa          #+#    #+#             */
/*   Updated: 2023/06/18 17:32:16 by aaouassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
# include <sys/stat.h>
# include <sys/errno.h>

typedef struct s_argument
{
	char				*arg;
	struct s_argument	*next;
}						t_argument;


// typedef struct s_command
// {
// 	char				pipe;
// 	char				*cmnd;
// 	t_argument			*argument;
// 	struct s_command	*next;
// }						t_command;

typedef struct s_glob
{
	int		fdout;
	int		fd_in;
	int		g_exit_status;
	int		g_env;
	int		g_exp;
	char	**envp;
	char	**exp;
	char	*pwd;
	int		env;
	int 	pid;
	int		copy_fd;
	int		tmpin;
	int 	tmpout;
	int		g_child;
	int		last;
	int		j;
	
}				t_glob;
t_glob			g_glob;


typedef struct s_data
{
	char	**args;
	int		error;
	int		if_hd;
	char	*inf;
	int		*infiles;
	int		n_infiles;
	char	**outfiles;
	char	**append;
	char	**infiles;
	char	**hd;
	int		end[2];
	char	**envp;
}				t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

//struct stat	s;

void    pwd(char **av);
int		ft_putstr(char *str);
void	ft_update_pwd(void);
void	ft_update_oldpwd(void);
char	*ft_cd_home(char *path, char **args);
int		ft_cd_cmmd(char **args);
char	*ft_getenv(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char	const *s1, char	const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const	char *s);
int		ft_check_option(char *args);
int		ft_echo_cmmd(char **args);
int		ft_pwd_cmmd(void);
int		ft_env_cmmd(void);
int		ft_atoi(const char *str);
int		ft_count_args(char **args);
void	ft_numeric(char **args);
int		ft_exit_cmmd(char **args);
char	*ft_strchr(const char *s, int c);
void	*calloc(size_t count, size_t size);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void	*s, size_t	n);
void	*ft_memset(void *b, int c,	size_t len);
//------------------------------------
int		ft_export_cmmd(t_list *exec);
void	ft_new_env(t_list *exec);
void	ft_set_env(char *name, char *value);
char	*ft_join_tmp(char *tmp, char *name, char *value);
void	ft_set_expo(char *name, char *value, int exist);
int		ft_big_len(int s1, int s2);
int		ft_get_index(char *str, char c);
int		ft_exist(char *name);
char	*ft_get_name(char *str);
char	*ft_new_line(char *name, char *value);
char	**add_env(char **strs, char *arg);
//------------------------------------
int		ft_unset_cmmd(char **args);
void	ft_unset_expo(char *str);
void	ft_unset_env(char *str);
char	**ft_delete_element(char **env, int n);
void	free_loop(char **args);
int		ft_acceptable(char c);
int		ft_checkin_error(char *arg);
void	ft_error_unset(char *name);
void	ft_error_export(char *name);
char	*g_v_n(char *str);
//-----------------------------------
char	**add_env(char **strs, char *arg);
char	**create_envp(char **envp);
char	**creat_export(char **env);
void	ft_initialiser(void);
char	*g_variable(char *str);
//-----------------------------------
t_data	*init_data(char **envp);
int		ft_bulitins(t_list *exec);
int		ft_execute_bulitins(t_list *exec, int mode);
t_data	*init_data(char **envp);
//------------------------------------
void	ft_start_exec(t_list *exec);
void	child_p(t_list *exec, int *p, int copy_fd);
int		built_parent(t_list *exec);
void	ft_initialise(void);
char	*find_path(char *cmd, char **env);
void	ft_cmd_err(char *cmd);
void	open_out(t_list *exec, int i);
int		open_out1(t_list *exec, int i);
void	piping(pid_t *p);
int		err_inf(t_list *exec);
int		err_fork(void);
char	**ft_split(char const *s, char c);
void	alloc_words(char const *s, char c, char **splited, int words);
int		count_words(char const *s, char c);
void	free_func(char **splited, int j);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_dup(int fd, int end);
void	ft_ree(t_list *exec);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	path_err(void);
int		err_out(t_list *exec, int mode, int mode1, int i);
void	error_msg(char *str, int err);

#endif