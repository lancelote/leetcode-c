#include <stdio.h>

int
GetValue(char Char) {
	switch(Char)
    {
		case 'I': return(1);
		case 'V': return(5);
		case 'X': return(10);
		case 'L': return(50);
		case 'C': return(100);
		case 'D': return(500);
		case 'M': return(1000);
		default:  return(0);
	}
}

int
romanToInt(char* s)
{
    int Result, Idx, Current, Next;
	
    Result = 0;
	for(Idx = 0; s[Idx] != '\0'; Idx++)
    {
		Current = GetValue(s[Idx]);
		Next    = GetValue(s[Idx + 1]);

		if(Current < Next)
        {
			Result -= Current;
		}
        else
        {
			Result += Current;
		}
	}

	return(Result);
}

int
main(void)
{
    int NumTests, TestIdx, Got;

	struct {
		char* S;
		int   Want;
	} Tests[] = {
		{"III", 3},
		{"LVIII", 58},
		{"MCMXCIV", 1994},
	};

	NumTests = sizeof(Tests) / sizeof(Tests[0]);
	for (TestIdx = 0; TestIdx < NumTests; TestIdx++) {
		Got = romanToInt(Tests[TestIdx].S);
		if (Tests[TestIdx].Want != Got) {
			printf("want %d, got %d\n", Tests[TestIdx].Want, Got);
			return(1);
		}
	}

	return(0);
}
