#include "lcommands.h"

int get(string t[])
{
	string cl;
	bool entered;
	int count;

	do
	{
		cout << "Enter command: ";
		while(true)
		{
			getline(cin, cl);
			entered = check();
			if(entered)
				break;
		}

	}while(cl.length() == 0);

	count = tokenize(t, cl);
    return count;
}

int tokenize(string t[], string cl)
{
	char *token[8];
    char *wcl = new char [cl.length () + 1];
    int i;
    int count;

    for (i = 0; i < 8; i ++)
    {
        t[i] = "";
    }

    strcpy (wcl, cl.c_str ());	//copy cl to wcl

    i = 0;
    if ((token[i] = strtok (wcl, " ")) != NULL)
    {
        i ++;
        while ((token[i] = strtok (NULL, " ")) != NULL)
        {
            i ++;
        }
    }
    count = i;

    for (i = 0; i < count; i ++)		//make all of t equal to tokenize token cstring
    {
        t[i] = token[i];
    }

    delete [] wcl;	

    return count;

}

bool check()
{
	if(processed)
	{
		processed = 0;
		cin.clear();
		return false;
	}
	return true;
}

int process(string t[], int count)
{
	char** words;
	pid_t returnfork;
	int status;

	if (t[0] == "quit" || t[0] == "exit")
	{
		cout << "Returning to main terminal...\n";
		return 0;
	}
	else
	{
		returnfork = fork();
		if(returnfork == 0)
		{
			words = convert(t, count);
            execvp(words[0], words);
		}
		else if(returnfork > 0)
		{
			wait(&status);
			return 1;
		}
		else
		{
			cout << "Error in forking...\n";
		}
	}
	return 1;
}

char** convert(string t[], int count)
{
	char** words = (char **) malloc (sizeof (char*) * (count + 1));

	for (int i = 0; i < count; i++)
    {
        words[i] = strdup(t[i].c_str());
    }

    words[count] = NULL;
    return words;

}