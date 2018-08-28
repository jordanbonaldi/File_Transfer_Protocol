/*
** EPITECH PROJECT, 2018
** cmds
** File description:
** cmds
*/

# ifndef H_CMD
	# define H_CMD

# define __call_cmd(name, request) get_cmd($, name, request)

# define __call_action(act) action_cmd($, req, act)

# define __call_data_action(act) action_data_cmd($, req, act)

# define __create_command(cmdname, func) add_cmd($, (cmd_t) { \
						.name = cmdname, \
						.cmd = func, \
						.next = NULL \
					})

#endif
