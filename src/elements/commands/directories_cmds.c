/*
** EPITECH PROJECT, 2018
** directories
** File description:
** directories
*/

# include "project.h"

void command_pwd(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		(void)req;
		char cwd[MAX_LENGTH];

		__O(getcwd(cwd, MAX_LENGTH), ERR_PWD);
		__sendComposed(FUNC(int a(_) {
			return _2XX_OK(257);
		}));
		return 1;
	}));
}

void command_cwd(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		char cwd[MAX_LENGTH + 1];
		char *complete_path;
		int check;

		__O(getcwd(cwd, MAX_LENGTH), ERR_CWD);
		if (!req || !*req)
			return dprintf(CLIENT_SOCK, "550 No params\n");
		else if (*req == '/')
			check = chdir(req);
		else {
			complete_path = strcat(cwd, "/");
			complete_path = strcat(complete_path, req);
			printf("Try to access : %s\n", complete_path);
			check = chdir(complete_path);
		}
		__sendComposed(FUNC(int a(_) {
			return check >= 0 ? _2XX_OK(250) :
				dprintf(CLIENT_SOCK, "550 Bad path\n");
		}));
		return 1;
	}));
}

void command_cdup(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		char cwd[MAX_LENGTH + 1];
		int check;

		(void)req;
		check = chdir("..");
		__sendComposed(FUNC(int a(_) {
			return check >= 0 ? _2XX_OK(200) : _2XX_NO(200);
		}));
		return 1;
	}));
}
