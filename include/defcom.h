#ifndef DEFCOM_H
#define DEFCOM_H

int executeDefaultCommand(char *command, char **args);

/* 
 * executeCommand is used to execute files
*/
int executeCommand(char *binf, char **args, char *env[],char **path, int path_cnt);
#endif