#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[10];
} Haab;

typedef struct
{
	char name[10];
} Tzolkin;


Haab Haab_Name[19]= {"pop","no","zip","zotz","tzec",
                     "xul","yoxkin","mol","chen","yax",
                     "zac","ceh","mac","kankin","muan",
                     "pax","koyab","cumhu","uayet"
                    };

Tzolkin Tzolkin_Name[21] = {"","imix","ik","akbal","kan","chicchan",
                            "cimi","manik","lamat","muluk","ok",
                            "chuen","eb","ben","ix","mem",
                            "cib","caban","eznab","canac","ahau"
                           };

int main(int argc, char **argv)
{
	int number = 0 ;
	scanf("%d",&number);

	int HabbYear = 0 ;
	char HabbMounth[10] = {0} ;
	int HabbDay = 0 ;

	int TzolkinYear = 0 ;
	int TzolkinMounth = 0 ;
	int TzolkinDay = 0 ;

	int totalnumber = 0 ;
	printf("%d\n",number);
	while(number--)
	{
		scanf("%d. %s%d",&HabbDay,HabbMounth,&HabbYear);
		totalnumber = HabbYear * 365 + HabbDay + 1;

		TzolkinMounth = 0 ;

		while(strcmp(Haab_Name[TzolkinMounth].name,HabbMounth))
		{
			TzolkinMounth ++;
		}

		totalnumber = totalnumber + (TzolkinMounth  + 0)* 20 ;

		TzolkinYear = totalnumber / 260 ;
		totalnumber = totalnumber - TzolkinYear * 260 ;

		if(totalnumber==0) TzolkinYear--;

		TzolkinMounth = totalnumber%20==0?20:totalnumber%20 ;
		TzolkinDay = totalnumber%13==0?13:totalnumber%13 ;

		printf("%d %s %d\n",TzolkinDay,Tzolkin_Name[TzolkinMounth].name,TzolkinYear);
	}


	return 0;
}
