/*
** EPITECH PROJECT, 2018
** File
** File description:
** file
*/

# include "project.h"

void command_del(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		char cwd[MAX_LENGTH + 1];
		char *complete_path;
		int check;

		__O(getcwd(cwd, MAX_LENGTH), ERR_CWD);
		complete_path = strcat(cwd, "/");
		complete_path = strcat(complete_path, req);
		printf("Try to remove : %s\n", complete_path);
		check = remove(complete_path);
		__sendComposed(FUNC(int a(_) {
			return check >= 0 ? _250_DEL_OK : _250_DEL_NO;
		}));
		return 1;
	}));
}

void command_list(_, char *req)
{
	__call_data_action(FUNC(int a(_, char *req) {
		int fd;
		char *cmd = strdup("ls -l");

		cmd = req ? strcat(cmd, req) : cmd;
		fd = __(dup(1), ERR_DUP);
		__(dup2(DATA_SOCK, 1), ERR_DUP);
		system(cmd);
		__(dup2(fd, 1), ERR_DUP);
		free(cmd);
		_226;
		return 1;
	}));
}

void command_retr(_, char *req)
{
	__call_data_action(FUNC(int a(_, char *req) {
		int fd = req ? open(req, O_RDONLY) : 0;
		char file[MAX_LENGTH];

		if (!fd || fd < 0) {
			_xxx(550, "No file specified or file not found");
			return 1;
		}
		while (read(fd, file, 1))
			__(write(DATA_SOCK, file, 1), ERR_WRITE_CLIENT);
		close(fd);
		_226;
		return 1;
	}));
}

void command_stor(_, char *req)
{
	__call_data_action(FUNC(int a(_, char *req) {
		int fd = req ? open(req, O_CREAT | O_TRUNC | O_RDWR, 0666) : 0;
		char file[MAX_LENGTH];

		if (!fd || fd < 0) {
			_xxx(550, "No file specified or file not found");
			return 1;
		}
		while (read(DATA_SOCK, file, 1))
			__(write(fd, file, 1), ERR_WRITE_CLIENT);
		close(fd);
		_226;
		return 1;
	}));
}
