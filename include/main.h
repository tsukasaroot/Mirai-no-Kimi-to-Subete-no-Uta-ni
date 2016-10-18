#ifndef MAIN_H_
#define MAX_LENGTH	2000

void	delay(unsigned int ms);
void	clearbuffer();
void	wrapping(char const *string, FILE* filedest);
void	rewrite(char *strings, FILE* filesrc, FILE* filedest);
void	cleanerchar(char const *string, FILE *filedest);
void	cleanerstrings(char *strings, FILE *filesrc, FILE* filedest);
int	readchar(char *path, int length);
int	prog();
int	my_strlen(char *str);
int	my_putchar(char c);
int	my_putstr(char *str);

#endif /* MAIN_H_ */
