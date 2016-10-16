void	delay(unsigned int ms);
void	clearbuffer();
void	wrappring(char const *string, FILE* filedest);
void	rewrite(char *strings, FILE* filesrc, FILE* filedest);
void	cleanerchar(char const *string, FILE *filedest);
void	cleanerstrings(char *strings, FILE *filesrc, FILE* filedest);
int	readchar(char *path, int length);
