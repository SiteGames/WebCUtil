#ifndef SESSIONS_H
#define SESSIONS_H

typedef struct{
	char id[MAX_SESSION_ID_LENGTH];
	time_t expiration;
	String name;
	String data;
	char hora[9];
	date date;
} sessions;

static void random_abc(char t[])
{
	srand(time(NULL));
	int caracteres[MAX_SESSION_ID_LENGTH];
	for (int i = 0; i < MAX_SESSION_ID_LENGTH; i++)
	{
		caracteres[i] = 65 + rand() % (90 - 65 + 1);
	}
	for (int i = 0; i < MAX_SESSION_ID_LENGTH; i++)
	{
		t[i] = caracteres[i];
	}
}

void create_session(sessions *ses)
{
	char sess[100];
	char hora_actual[9];
	time_t tiempo_actual;
	struct tm *tiempo_info;
	time(&tiempo_actual);
	tiempo_info = localtime(&tiempo_actual);
	strftime(hora_actual, sizeof(hora_actual), "%H:%M:%S", tiempo_info);
	random_abc(ses->id);
	concatplus(sess, "tmp/%s.sess", ses->id);
	FILE *fp = fopen(sess, "w"), *fp2;
	if (fp == NULL)
	{
		perror("webCUtil ");
		return;
	}
	else
	{
		fprintf(fp, "%s|s:\"%s\":date\":%s\":Active", ses->name, ses->data, hora_actual);
		strcpy(hora_actual, ses->hora);
	}
	fclose(fp);
	fp2 = fopen("tmp/sess.reg", "a");
	if (fp2 == NULL)
	{
		perror("webCUtil ");
		return;
	}
	else
	{
		fprintf(fp2, "file: %s\n", sess);
	}
	fclose(fp2);
}

int verify_session(sessions *ses)
{
	int result = 0;
	char hora_actual[9];
	time_t tiempo_actual;
	struct tm *tiempo_info;
	time(&tiempo_actual);
	tiempo_info = localtime(&tiempo_actual);
	strftime(hora_actual, sizeof(hora_actual), "%H:%M:%S", tiempo_info);
	if (strcmp(hora_actual, ses->hora) == 0)
	{
		result = END_SESSION;
	}
	else
	{
		result = NOT_END_SESSION;
	}
	return result;
}

static char *_search_(const char *palabra, char caracterLimite, const char *f)
{
	FILE *fp = fopen(f, "r");
	char *data[BUFFER_SIZE];
	char *texto;
	char *encontrado;
	if (fp == NULL)
	{
		perror("webCUtil ");
		return NULL;
	}
	fread(data, sizeof(char), BUFFER_SIZE, fp);
	texto = data;
	encontrado = strstr(texto, palabra);
	if (encontrado != NULL)
	{
		size_t posicionFinal = encontrado - texto + strlen(palabra);
		const char *limite = strchr(texto + posicionFinal, caracterLimite);
		if (limite != NULL)
		{
			size_t longitud = limite - (texto + posicionFinal);
			char *subcadena = (char *)malloc(longitud + 1);
			strncpy(subcadena, texto + posicionFinal, longitud);
			subcadena[longitud] = '\0';
			return subcadena;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}

static int _search_2(const char *texto, const char *f)
{
	char *word = GET_RESPONSE();
	FILE *fp = fopen(f, "r");
	char *text_copy;
	char *line;
	char dess[BUFFER_SIZE];
	if (fp == NULL)
	{
		perror("webCUtil ");
		return Error;
	}
	while (feof(fp) == 0)
	{
		fgets(dess, BUFFER_SIZE, fp);
	}
	word = dess;
	text_copy = strdup(word);
	if (text_copy == NULL)
	{
		return Error;
	}
	line = strtok(text_copy, "\n");
	while (line != NULL)
	{
		if (strstr(line, texto) != NULL)
		{
			free(text_copy);
			return Ok;
		}
		line = strtok(NULL, "\n");
	}
	free(text_copy);
	return Error;
}

void destroy_session(sessions *sess)
{
	char data[BUFFER_SIZE];
	char dess[100];
	String ress;
	int res;
	FILE *fp = fopen("tmp/sess.reg", "r"), *tmp;
	if (fp == NULL)
	{
		perror("webCUtil ");
		return;
	}
	else
	{
		while (feof(fp) == 0)
		{
			fgets(data, BUFFER_SIZE, fp);
			ress = _search_("file: ", '\n', "tmp/sess.reg");
			printf("Ress value: %s\n", ress);
			tmp = fopen(ress, "r");
			if (tmp == NULL)
			{
				perror("webCUtil ");
				return;
			}
			else
			{
				while (feof(tmp) == 0)
				{
					fgets(dess, 100, tmp);
					res = _search_2("Active", ress);
					if (res == Ok)
					{
						if (remove(ress))
						{
							fclose(fp);
							fclose(tmp);
							return;
						}
						else
						{
							perror("webCUtil ");
							printf("Error al eliminar el archivo\n");
							fclose(fp);
							fclose(tmp);
							return;
						}
					}
				}
			}
		}
	}
	fclose(fp);
	fclose(tmp);
}

#endif
