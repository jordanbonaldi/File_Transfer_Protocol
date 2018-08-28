/*
** EPITECH PROJECT, 2018
** USER
** File description:
** USER
*/

# include "project.h"

void command_user(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		printf("Fetching username : %s\n", req);
		if (!strcmp(req, USER))
			CLIENT_LOG = LOGGING;
		_331;
		return 1;
	}));
}

void command_pass(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		if (!CONNECTED || CLIENT_LOG == NONE)
			_xxx(530, "No account");
		else if (!req || !*req) {
			CLIENT_LOG = LOGGED;
			_230;
		}
		return 1;
	}));
}

void command_syst(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		(void)req;
		_220;
		return 1;
	}));
}

void command_quit(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		(void)req;
		(void)session;
		_221;
		kill_client($);
		return 1;
	}));
}
