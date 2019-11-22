#include<stdio.h>


int validate_expr(const char* pattern , int size)
{
	int i =0;
	int j =0;
	char c;
	char s;

	while((size) > 0)
	{
		c = pattern[i];
		switch(c)
		{
			case '\\':
				{
					i++;
					size--;
					if(!((pattern[i]) == 'w' || (pattern[i]) == 's' || (pattern[i]) == 'd')) 
					{
						return -1;
					}
				} break;
			case '[':
				{
					i++;
					size--;
					if(pattern[i] == '^')
					{
						i++;
						size--;
						while(pattern[i] !=']')
						{
							if(!(((pattern[i]) >= '0' && (pattern[i]) <= '9') ||
						  	((pattern[i]) >= 'a' && (pattern[i]) <= 'z') ||
						 	((pattern[i]) >= 'A' && (pattern[i]) <= 'Z')))
							{
								return -1;
							}
							i++;
							size--;
						}
					}
					else
					{		
						while(pattern[i] !=']')
                                                {
							if(!(((pattern[i]) >= '0' && (pattern[i]) <= '9') ||
						  	((pattern[i]) >= 'a' && (pattern[i]) <= 'z') ||
						 	((pattern[i]) >= 'A' && (pattern[i]) <= 'Z')))
							{
								return -1;
							}
							i++;
							size--;
                                                }
					}

				} break;
			default:
				{
					return -1;
				}
		}
		size--;
		i++;
	}
	return 0;
}

				
