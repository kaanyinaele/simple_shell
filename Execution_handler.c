#include "shell.h"

/**
 * start_execution - initiates the execution of commands
 * @current_command: current token to be checked
 * @type_command: parsed token type
 * Return: void function
 */
void start_execution(char **current_command, int type_command)
{
    pid_t PID;

    if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
    {
        PID = fork();
        if (PID == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (PID == 0)
        {
            execute_command(current_command, type_command);
        }
        else
        {
            int child_status;
            waitpid(PID, &child_status, 0);

            if (WIFEXITED(child_status))
            {
                status = WEXITSTATUS(child_status);
            }
            else
            {
                // Handle abnormal child termination if needed
                status = 1; // Set a default exit status
            }
        }
    }
    else
    {
        execute_command(current_command, type_command);
    }
}
