#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EXPR 20

struct patt {
	char digit;
	char alpha;
	char space;
	char braces[10];
	char inv_braces[10];
	char ch;
};
struct patt expressions[MAX_EXPR];

void comp(const char* pattern, int size)
{
	char c;
	int i=0;
	int j=0;

	while(size > 0)
	{
		int k=0;
                c = pattern[i];

                switch(c)
                {
                        case '\\':
                                  {
					  i++;
					  size--;
                                                  switch(pattern[i])
                                                  {
                                                          case 'd': { expressions[j].digit = 'd';
								      expressions[j].ch = 'd';  } break;
                                                          case 's': { expressions[j].space = 's';
								      expressions[j].ch = 's';  } break;
                                                          case 'w': { expressions[j].alpha = 'w';
								      expressions[j].ch = 'w';  } break;
                                                  }
                                  } break;
                        case '[':
                                  {
					  i++;
					  size--;
                                          if((pattern[i]) == '^')
                                          {
						  expressions[j].ch = ']';
                                                  i++;
                                                  while((pattern[i]) != ']')
                                                  {
                                                          expressions[j].braces[k] = pattern[i];
                                                          i++;
                                                          k++;
							  size--;
                                                  }
						  size++;
                                          }
                                          else
                                          {
						  expressions[j].ch = '[';
                                                  while((pattern[i]) != ']')
                                                  {
                                                          expressions[j].braces[k] = pattern[i];
                                                          i++;
                                                          k++;
							  size--;
                                                  }
						  size++;
					  }
                                  }
                                  break;
                }
		i++;
		j++;
		size--;
	}
}

static int matchdigit(char c)
{
       if((c >= '0') && (c <= '9'))
               return 1;
       else
               return 0;
}
static int matchalpha(char c)
{
        if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
                return 1;
        else
                return 0;
}

static int matchspace(char c)
{
 	if(c== 0x20)
                return 1;
        else
                return 0;
}

static int matchone (char c, char p)
{
 	if(c == p)
                return 1;
        else

                return 0;
}



int match(const char* text, int size)
{

	int j=0;
	
	while((size) > 0)
	{
		if(expressions[j].ch == 'd')
		{
			if(!(matchdigit(*text)))
				return -1;
			text++;
		}
		else if(expressions[j].ch == 's')
		{
			if(!(matchspace(*text)))
				return -1;
			text++;
		}
		else if(expressions[j].ch == 'w')
		{
			if(!(matchalpha(*text)))
				return -1;
			text++;
		}
		else if(expressions[j].ch == '[')
		{
			int k=0;
			while(expressions[j].braces[k] != '\0')
			{
				if(!(matchone(*text, expressions[j].braces[k])))
					return -1;
				text++;
				size--;
				k++;
			}
			size++;
		}
		else if(expressions[j].ch == ']')
		{
			int k=0;
                        while(expressions[j].braces[k] != '\0')
                        {
                                if(matchone(*text, expressions[j].braces[k]))
                                        return -1;
                                text++;
				size--;
                                k++;
                        }
			size++;
		}
		j++;
		size--;
	}
	if((expressions[j].ch == '\0') && (*text == '\0'))
		return 0;
	else
		return -1;
}
