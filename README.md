# minishell

### TO DO
- Add translation funcs between list env and array of strings for execve.
- Add perror custom func, coupled with errno and strerrno.
- We need to save errno right after execve, it could be lost.
- Confused about assigning errno when we need to perror our way out of minishell
