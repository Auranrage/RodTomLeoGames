//Funcao de criptografia da senha
int criptografia()
{
	FILE *criptoSenha, *admin;
	char c;
	admin = fopen("admin.txt", "r");
	criptoSenha = fopen("criptosenha.txt", "w+");
	while (!feof(admin) || c != ' ')
	{
		c = fgetc(admin);
	}
	do
	{
		c = fgetc(admin);
		if (c % 2 != 0)
		{
			c += 2;
			if (c == 123)
			{
				c = 97;
			}
			if (c == 91)
			{
				c = 65;
			}
			if (c == 59)
			{
				c = 49;
			}
		}
		else
		{
			c -= 2;
			if (c == 96)
			{
				c = 122;
			}
			if (c == 64)
			{
				c = 90;
			}
			if (c == 46)
			{
				c = 56;
			}
		}
		fprintf(criptoSenha, "%c", c);
	} while (!feof(admin));
	return 0;
}

int descriptografia()
{
	FILE *descriptoSenha, *criptoSenha;
	char c;
	criptoSenha = fopen("criptoSenha.txt", "r");
	criptoSenha = fopen("descriptosenha.txt", "w+");
	while (!feof(criptoSenha) || c != ' ')
	{
		c = fgetc(criptoSenha);
	}
	do
	{
		c = fgetc(criptoSenha);
		if (c % 2 != 0)
		{
			c -= 2;
			if (c == 95)
			{
				c = 121;
			}
			if (c == 63)
			{
				c = 89;
			}
			if (c == 47)
			{
				c = 57;
			}
		}
		else
		{
			c += 2;
			if (c == 124)
			{
				c = 98;
			}
			if (c == 92)
			{
				c = 66;
			}
			if (c == 58)
			{
				c = 48;
			}
		}
		fprintf(descriptoSenha, "%c", c);
	} while (!feof(criptoSenha));
	return 0;
}