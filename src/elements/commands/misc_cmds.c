/*
** EPITECH PROJECT, 2018
** misc
** File description:
** misc
*/

# include "project.h"

void command_noop(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		(void)session;
		(void)req;
		_200;
		return 1;
	}));
}

void command_help(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		(void)session;
		(void)req;
		_214;
		return 1;
	}));
}

void command_exec(_, char *req)
{
	__call_data_action(FUNC(int a(_, char *req) {
		int fd;

		fd = __(dup(1), ERR_DUP);
		__(dup2(DATA_SOCK, 1), ERR_DUP);
		system(req);
		__(dup2(fd, 1), ERR_DUP);
		_226;
		return 1;
	}));
}
