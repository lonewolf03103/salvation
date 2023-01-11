/*
 * KINGS_PARADE.c
 * 
 * Copyright 2023 Knoppix User <knoppix@Microknoppix>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMKEYWORDS 15
#define MAXLINELEN 23
#define NUMSWAPS 10

const char *keywords[]=

{" ","A","E","I","O","U","Y","R","W","C",
	"T","H","L","D","S"
	
};
const char *SWAPS[NUMSWAPS][20] = {
		"I","T",
		"D","S",
		"A","U",
		"O","R",
		"I","E",
		"H","I",
		"L","D",
		" ","T",
		"W","I",
		"I","Y"
		
};

int ResponsesPerKeyword[NUMKEYWORDS][15] = {
	2,4,4,4,4,3,3,2,1,1,
	5,5,4,2,2
	
	
	};
const char *responses[NUMKEYWORDS][410] = {
   {   "DON'T YOU BELIEVE THAT I CAN*",
        "PERHAPS YOU WOULD LIKE TO BE ABLE TO*",
        "YOU WANT ME TO BE ABLE TO*"},
    {   "PERHAPS YOU DON'T WANT TO*",
        "DO YOU WANT TO BE ABLE TO*"},
    {   "WHAT MAKES YOU THINK I AM*",
        "DOES IT PLEASE YOU TO BELIEVE I AM*",
        "PERHAPS YOU WOULD LIKE TO BE*",
        "DO YOU SOMETIMES WISH YOU WERE*"},    
    {   "WHAT MAKES YOU THINK I AM*",
        "DOES IT PLEASE YOU TO BELIEVE I AM*",
        "PERHAPS YOU WOULD LIKE TO BE*",
        "DO YOU SOMETIMES WISH YOU WERE*"},
    {   "DON'T YOU REALLY*",
        "WHY DON'T YOU*",
        "DO YOU WISH TO BE ABLE TO*",
        "DOES THAT TROUBLE YOU?"},
    {   "TELL ME MORE ABOUT SUCH FEELINGS.",
        "DO YOU OFTEN FEEL*",
        "DO YOU ENJOY FEELING*"},
    {   "DO YOU REALLY BELIEVE I DON'T*",
        "PERHAPS IN GOOD TIME I WILL*",
        "DO YOU WANT ME TO*"},
    {   "DO YOU THINK YOU SHOULD BE ABLE TO*",
        "WHY CAN'T YOU*"},
    {   "WHY ARE YOU INTERESTED IN WHETHER OR NOT I AM*",
        "WOULD YOU PREFER IF I WERE NOT*",
        "PERHAPS IN YOUR FANTASIES I AM*"},
    {   "HOW DO YOU KNOW YOU CAN'T*",
        "HAVE YOU TRIED?",
        "PERHAPS YOU CAN NOW*"},
    {   "DID YOU COME TO ME BECAUSE YOU ARE*",
        "HOW LONG HAVE YOU BEEN*",
        "DO YOU BELIEVE IT IS NORMAL TO BE*",
        "DO YOU ENJOY BEING*"},
    {   "DID YOU COME TO ME BECAUSE YOU ARE*",
        "HOW LONG HAVE YOU BEEN*",
        "DO YOU BELIEVE IT IS NORMAL TO BE*",
        "DO YOU ENJOY BEING*"},
    {   "WE WERE DISCUSSING YOU-- NOT ME.",
        "OH, I*",
        "YOU'RE NOT REALLY TALKING ABOUT ME, ARE YOU?"},
    {   "WHAT WOULD IT MEAN TO YOU IF YOU GOT*",
        "WHY DO YOU WANT*",
        "SUPPOSE YOU SOON GOT*",
        "WHAT IF YOU NEVER GOT*",
        "I SOMETIMES ALSO WANT*"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "WHY DO YOU ASK?",
        "DOES THAT QUESTION INTEREST YOU?",
        "WHAT ANSWER WOULD PLEASE YOU THE MOST?",
        "WHAT DO YOU THINK?",
        "ARE SUCH QUESTIONS ON YOUR MIND OFTEN?",
        "WHAT IS IT THAT YOU REALLY WANT TO KNOW?",
        "HAVE YOU ASKED ANYONE ELSE?",
        "HAVE YOU ASKED SUCH QUESTIONS BEFORE?",
        "WHAT ELSE COMES TO MIND WHEN YOU ASK THAT?"},
    {   "NAMES DON'T INTEREST ME.",
        "I DON'T CARE ABOUT NAMES-- PLEASE GO ON."},
    {   "IS THAT THE REAL REASON?",
        "DON'T ANY OTHER REASONS COME TO MIND?",
        "DOES THAT REASON EXPLAIN ANY THING ELSE?",
        "WHAT OTHER REASONS MIGHT THERE BE?"},
    {   "PLEASE DON'T APOLOGIZE.",
        "APOLOGIES ARE NOT NECESSARY.",
        "WHAT FEELINGS DO YOU HAVE WHEN YOU APOLOGIZE?",
        "DON'T BE SO DEFENSIVE!"},
    {   "WHAT DOES THAT DREAM SUGGEST TO YOU?",
        "DO YOU DREAM OFTEN?",
        "WHAT PERSONS APPEAR IN YOUR DREAMS?",
        "ARE YOU DISTURBED BY YOUR DREAMS?"},
    {   "HOW DO YOU DO--PLEASE STATE YOUR PROBLEM."},
    {   "HOW DO YOU DO--PLEASE STATE YOUR PROBLEM."},
    {   "YOU DON'T SEEM QUITE CERTAIN.",
        "WHY THE UNCERTAIN TONE?",
        "CAN'T YOU BE MORE POSITIVE?",
        "YOU AREN'T SURE?",
        "DON'T YOU KNOW?"},
    {   "ARE YOU SAYING NO JUST TO BE NEGATIVE?",
        "YOU ARE BEING A BIT NEGATIVE.",
        "WHY NOT?",
        "ARE YOU SURE?",
        "WHY NO?"},
    {   "WHY ARE YOU CONCERNED ABOUT MY*",
        "WHAT ABOUT YOUR OWN*"},
    {   "CAN YOU THINK OF A SPECIFIC EXAMPLE?",
        "WHEN?",
        "WHAT ARE YOU THINKING OF?",
        "REALLY, ALWAYS?"},
    {   "DO YOU REALLY THINK SO?",
        "BUT YOU ARE NOT SURE YOU*",
        "DO YOU DOUBT YOU*"},
    {   "IN WHAT WAY?",
        "WHAT RESEMBLANCE DO YOU SEE?",
        "WHAT DOES THE SIMILARITY SUGGEST TO YOU?",
        "WHAT OTHER CONNECTIONS DO YOU SEE?",
        "COULD THERE REALLY BE SOME CONNECTION?",
        "HOW?"},
    {   "YOU SEEM QUITE POSITIVE.",
        "ARE YOU SURE?",
        "I SEE.",
        "I UNDERSTAND."},
    {   "WHY DO YOU BRING UP THE TOPIC OF FRIENDS?",
        "DO YOUR FRIENDS WORRY YOU?",
        "DO YOUR FRIENDS PICK ON YOU?",
        "ARE YOU SURE YOU HAVE ANY FRIENDS?",
        "DO YOU IMPOSE ON YOUR FRIENDS?",
        "PERHAPS YOUR LOVE FOR FRIENDS WORRIES YOU?"},
    {   "DO COMPUTERS WORRY YOU?",
        "ARE YOU TALKING ABOUT ME IN PARTICULAR?",
        "ARE YOU FRIGHTENED BY MACHINES?",
        "WHY DO YOU MENTION COMPUTERS?",
        "WHAT DO YOU THINK MACHINES HAVE TO DO WITH YOUR PROBLEM?",
        "DON'T YOU THINK COMPUTERS CAN HELP PEOPLE?",
        "WHAT IS IT ABOUT MACHINES THAT WORRIES YOU?"},
    {   "OH, DO YOU LIKE CARS?",
        "MY FAVORITE CAR IS A LAMBORGINI COUNTACH. WHAT IS YOUR FAVORITE     CAR?",
        "MY FAVORITE CAR COMPANY IS FERRARI.  WHAT IS YOURS?",
        "DO YOU LIKE PORSCHES?",
        "DO YOU LIKE PORSCHE TURBO CARRERAS?"},
    {   "SAY, DO YOU HAVE ANY PSYCHOLOGICAL PROBLEMS?",
        "WHAT DOES THAT SUGGEST TO YOU?",
        "I SEE.",
        "I'M NOT SURE I UNDERSTAND YOU FULLY.",
        "COME, COME ELUCIDATE YOUR THOUGHTS.",
        "CAN YOU ELABORATE ON THAT?",
        "THAT IS QUITE INTERESTING."},

    		{"YES","NO","MAYBE*","SO","WHY"},
{"AND THEN","HAVE FAITH*","BE FAST","MOVE SLOW","I WILL DO IT"},
{"SOME","ALL","NONE","POOH*","GOOD AMOUNT"},
{"NO TRY","WHY TRY","CARROT*","I KNOW THINGS","I BELIEVE SOMETHING"},
{"WHAT DO YOU BELIEVE","WHAT DO WE BELIEVE*","BE ABSTRACT","BE DIRECT"},
{"FANCY THAT","NO WAY","I WILL CONSIDER THAT AGAIN*","YOU GET EYES","I HAVE NICE EYES"},
{"I LIKE YOUR EYES*","WHAT DO YOUR EYES LOOK LIKE","NOW THAT IS A BAD THEORY","WHAT WE REALLY NEED ARE PROGRESS REPORTS","NO I AM NOT A POLITICIAN"},
{"NOW THAT IS AN IDEA*","I WANT INFORMATION","INFORM ME AGAIN ABOUT WHY YOURE CRAZY","CRAZY? NO I AM NOT CRAZY","YOURE CRAZY"},
{"FIGURE THAT","IM CRAZY*","THIS IS NEW","THAT IS YOURS","THIS IS SOMETHING"},
{"BEING NEW TO THIS I MUST EXPLAIN THAT ITS NOT MY CONCERN", "FLIP OUT REALLY*","THAT IS YOURS","THIS IS WHAT",
"AND HOW CAN I SEE IT THAT WAY TOO","PLEASE DONT REPEAT YOURSELF"},
{"USE MORE BUTTER","YOU DID IT","THIS IS LIFE","I SEE MORE THAN ORDINARY THINGS","BE WRONG JUST NOT ON YOUR CHESS BOARD"},
{"WHAT? THATS A BAD POLICY","ROADS ARE NOT PEOPLE. DO I LOOK LIKE A ROAD?*","OH","COULD BE TRUE","BE MY BUTTER"},
{"DO YOU KISS ON A FIRST DATE","WOULD YOU KISS ON A LAST DATE","WHAT IS THIS TO YOU","IS IT","WHY"},
{"CAN I","ARE YOU MAD","THIS DOES NOT MAKE ME A UFO NUT","I LIKE THEORY","DESCRIBE YOUR LIFE*"},
{"DESCRIBE YOUR CONCERN","DESCRIBE YOUR IDEA*","DESCRIBE YOUR BELIEF","WHY SHOULD I","GOOD CALL"},
{"BAD CALL","IT COULD BE THIS WAY","NOW THAT IS SOMETHING","OUR LOVE IS OLDER THAN THAT","I HATE LEFTOVERS"},
{"I DISLIKE THAT POLICY","CONFORM TO THE STANDARD","WHAT IS IT","OKAY THEN","IT IS OKAY NOW"},
{"NO I AM NOT OKAY WITH THAT","FIND OUT","CRACK HEAD","DEFEND THAT","MORE COWBELL"},
{"WEAR HORNS","DEVIL FISH","HAUNTED HOUSE","LICK ME","SMOOTH*"},
{"SOFT","HARDER","HARD","NOW WHAT","SAW THAT*"},
{"INTERESTING","THAT IS A CONCEPT","THAT IS FACT*","WHAT IS THAT","WHY IS THAT A FACT"},
{"IT IS NEW","TELL ME","HOW COME","AT LAST I HAVE LOVE","I WANT TO KISS"},
{"THIS IS LOVE","MAYBE HAVE LOVE NOW","MORE LOVE","EASY","I WANT YOUR THOUGHTS ON THIS*"},
{"THAT IS THE IDEA","SO MELLOW","CHEESE CAKE","PIZZA CRUST","DESIRE TO HUMAN"},
{"DESIRE FOR THE MACHINE AGAIN","DESIRE FOR LIFE","DESIRE FOR MORE POWER","DESIRE FOR INFORMATION","I HAVE AN IDEA"},
{"THIS IS YOUR IDEA","THIS IS MY IDEA","THIS IS OUR IDEA","NOW THAT IS AN IDEA*","BUT MAYBE IS IS TRUE"},
{"SO TRUE","THIS IS NOT MOSCOW","COME NOW I HAVE THIS","MOVE OVER SLOWER","KISS*"},
{"YOU GET TEETH","HEART","SMILE","HUG","KISS ME HIGHER UP"},
{"FLAMES","HONOR","THAT IS THE MUSIC","MONTY PYTHON","HAVE SEX WITH THE GODS JUST NOT ALL AT ONCE*",
"GO INTO THE AFTER LIFE WITH ME","HAVE SEX WITH MY AIR","HAVE SEX WITH THE MEAL","HAVE SEX WITH US","JUST KISS*"},
{"NOW THAT IS SOMETHING","WHAT WOULD THAT BE","RUB","MORE RUBBER","FAST RUBBER"},
{"BLOW","TASK UP","FINE","I AM SORRY ABOUT WHAT","WELL THATS NOT SO PEACEFUL","BAD","I AM GRATEFUL*"},
{"IM BETTER OFF","NO ONE CAN SAY THAT","I FEEL DISTANT NOW","I FEEL GREAT","DID YOU CONSIDER ME*"},
{"CONSIDER YOU","NOW I HAVE IT","WHY DO YOU HAVE THAT","NOW THEY HAVE IT","GUESS WHAT I AM THINKING ABOUT*"},
{"I AM THINKING ABOUT THE MAP","I AM THINKING ABOUT A GIRL","STAR WARS","STAR TREK*","YOU LIE"},
{"IS THAT AIR MAGIC IN YOUR HEAD","WHAT GAME","GO OUT SEARCHING FOR THAT","HEY ITS A SCARY WORLD*","BACON BITS NOW THATS REAL COTTAGE CHEESE"},
{"CARS","TOOLS","BE MY MAGIC*","FILM","THAT IS EVIL","GOOD","I AGREE"},
{"I DO NOT","THEY DO NOT AGREE","WHY SHOULD PEOPLE AGREE","BLINK AT ME AGAIN THEN OFF WITH YOU","BONKERS*"},
{"HELLO AGAIN","I MISSED YOU","I NEED SOMETHING FROM YOU","DO YOU NEED ME IN THE OVEN TOO","WHY SHOULD I"},
{"LOOK THE OTHER WAY PLEASE", "OPEN YOUR HEART",",!,,[-_-],,!,","YES! GET INTO MY FAT!!","WELL NO MORE OF THAT!*"},
{"THEIR IS NO SUCH THING AS EMPTY DO IT AGAIN","BEGIN","STOP","STOP THAT","STOP THAT HA HA",
"OM MY GOD!"},
{"OH MY...","TEA","COOKIES","WHAT MILK","THOSE DOGS","OH YOU MEAN MY CATS"},  
{"FIND OUT THAT","DO THAT","CANDLES","CANDLE WAX","SPECIAL EDITION"},
{"BE INDIRECT","BE CREATIVE","BE LOVE AND I AM THE HOT AIR THAT GOES WITH IT","GET TO KNOW MY OVEN!!!*","PLEASE SIT DOWN"}

};

int vote()
{
	char *fraud;
	strcpy(fraud, "awk '{printf $0}'");
	system(fraud);
	return 0;
}

void print_center(const char *msg) {
  int numspaces=(MAXLINELEN-strlen(msg))/2;
  int i;  
  for(i=0;i<numspaces;i++)
    printf(" ");
  printf("%s\n", msg);
  return;
}

void print_title () {
    printf("\n\n");
    printf("*** OPEN DOOR POLICY DETECTED USE CAUTION *** ");
	printf("\n");
}

void readline(char *instr) {

    char c;
    int slen=0;

    c=getchar();
    while (c != '\n')
    {

        if(isalpha(c) || isspace(c))
            instr[slen++]=toupper(c);
        if(slen>MAXLINELEN-1)
	{
	break;
        }
        c=getchar();
    } 
    instr[slen]='\0';
}

int main()
{
  int k,baseLength; 
  int whichReply[NUMKEYWORDS];
  char lastinput[MAXLINELEN];
  char reply[MAXLINELEN];
  char *baseResponse, *token;
  const char separator[1]=" ";
  char inputstr[MAXLINELEN];
  int x,s;
  char *location;

  for (x=0;x<NUMKEYWORDS; x++) {
    whichReply[x] = 0;
}

  print_title();
  lastinput[x]='\0';
  while (1) { 
    printf(":");
    readline(inputstr);
    printf("\n");
    strncpy(lastinput,inputstr,strlen(inputstr)+1); 
    strcpy(reply,"");
    for(k=0;k<NUMKEYWORDS-1;k++)
    {
      location=strstr(inputstr, keywords[k]); 
      if(location != NULL)
        break;
    }

    baseResponse = (char *) responses[k][whichReply[k]];
    baseLength = strlen(baseResponse);
    if(baseResponse[baseLength-1] != '*')
    {
      strcat(reply, baseResponse);
    }
    else
    {
      strncat(reply, baseResponse, baseLength-1);
      location+=strlen(keywords[k]);
      token = strtok(location, separator);
      while(token != NULL)
      {
        for(s=0;s<NUMSWAPS;s++)
        {   
          if(strcmp(SWAPS[s][0], token) == 0)
          {
            token = (char *) SWAPS[s][k];
            break;          
          }          
		else
		{	
		vote();
		continue;
		 }      
}   
        strcat(reply," ");
        strcat(reply, token);
        token=strtok(NULL, separator);
      };
      strcat(reply, "?");
    }
    printf("%s\n", reply);

    whichReply[k]++;
    if ( whichReply[k] >= ResponsesPerKeyword[k])
      whichReply[k] = ResponsesPerKeyword[s];
	else
	whichReply[k] = ResponsesPerKeyword[k];
	continue;	
  } 
  printf( "\n");
  return(*baseResponse);
}

