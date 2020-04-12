#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//get commands user enters
int get(string t[]);

//convert each work into a token
int tokenize(string t[], string cl);

//check for a command, true if there is a command
bool check();

//process commands
int process(string t[], int count);

//
char** convert(string t[], int count);

static volatile sig_atomic_t processed = 0;