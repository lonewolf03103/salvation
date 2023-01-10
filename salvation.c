//it aint pretty it aint subtle what happens to the heart - leonard cohen
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define NUMKEYWORDS 77
#define MAXLINELEN 11 
#define NUMSWAPS 75

const char *keywords[60]={" ","","!",".","?","(",")","*",";",
			"WHAT","WHY","WHEN","HOW","DO","WOULD","WILL","BECAUSE",
			"ME","MY","I","YOU","US","THEY","THEM","LISTEN","HEAR",
			"HAVE","HAS","IS","THIS","THAT","ARE","ALSO","WRONG","CORRECT",
			"1","2","3","4","5","6","7","8","9","0","HAPPEN","THIS IS"
			"IF","TO","BE","OF","AND","HAD","FOR","SO","THEN","DID",
			"POOH","SEX","KISS","HUG","LAUGH","CRY","EMBRACE","HEART",
			"EAR","FEET","ASS","LICK","CUDDLE","LIKE","ABOUT","INTO",
			"COMB","LEGS","BREASTS","HAIR","KISS","SUCK","EYES","THAT IS",			
			"LUST","BABIES","EMBRACE","SLEEP","DANCE","MAKE","LOVE","WHY IS",
			"LOOK","RIDE","BUTT","BUM","CHEEKS","TRUE","FALSE","FINE","YOU ARE",
			"FIND","IN","OUT","MORE","YES","NO","MAYBE","STOP""START","I AM",
};
const char *SWAPS[NUMSWAPS][4] = {
    {"ARE","YOU","IS*","WHAT"},
    {"HAVE", "WAS", "ARE","IS*"},
    {"YOU","I*","ME","MY"},
    {"YOUR", "MY","I","IS*"},
    {"IVE", "YOU HAVE*","MY","AND"},
	{"TO","IS","HAD","THEN*"},
    {"THIS","I AM", "ARE*","YOU ARE"},
    {"YOU", "MY", "ME","THAT"},
    {"YOU","ME", "YOU*" "THIS"},
    {"ARE","AM","ARE*" "HOW"},
    {"IS","WAS", "WERE","IF*"},
    {"THEN*","I","YOU","AM"},
    {"BUT","MY", "YOUR" "IS*"},
    {"DOES","YOU HAVE", "IS*","THAT"},
    {"SO","YOU", "ARE*", "I AM"},
	 {"YOU","HI","HELLO*","THANKS"},
	 {"DO","DID","DONE*","THIS"},
	 {"BUT","IF*","THEN","IS"},
	 {"HOW*","WOULD","COULD","SHOULD"},
	 {"THEN","FOR","DOES*","IF"},
	 {"BECAUSE","THAT*","IS","WHY"},
	 {"SO","THIS","THAT*","THERE"},
	 {"I","IS","WAS*","WHAT"},
	 {"IS","MAYBE","FALSE","TRUE*"},
		{"THEN","HOW","WHY","IS*"},
		{"WHO","IS","A*","THE"},
		{"HAVE","HAS","IS*","HAD"},	
		{"EAR","FEET","ASS","CUDDLE*"},
		{"THAT","EAR","CUDDLE*","ASS"},
		{"KISS","KISS","FEET*","ASS"},
		{"OF","FOR","IS*","TO"},
		{"NEUTRAL","BABY","MAYBE","GOLD*"},
		{"BECAUSE","WITHOUT","FORWARD*","BEAUTY"},
		{"INTERESTING","TOWARDS","OUTWARDS*","SIDE"},
		{"PLANET","ATOM","MATH","THINKING*"},
		{"RED","WHITE","GOLD*","BLUE"},
		{"FIND","ASS","LICK","POOH*"}, 		
		{"EYES","DO","LIPS","KISS*"},
		{"LOOK","LUST","FIND","KISS*"},
		{"INTO","LUST","THERE*","THAT"},
		{"THAT","BECAUSE","SO*","IS"},
		{"HAIR","EYES","THAT*","HAD"}	
};

int ResponsesPerKeyword[NUMKEYWORDS]= {
	4,4,5,7,2,1,6,5,3,
	3,5,8,6,5,2,1,4,3,
	4,5,6,3,4,5,1,2,2,
        3,4,2,6,6,6,8,4,6,
	3,4,5,7,5,6,4,5,8,
	6,4,4,8,2,1,1,3,1,
	3,4,5,3,6,7,6,3,5,
	1,1,1,2,3,4,5,1,2,
	2,3,4,5,6,5,4,4,6,
	4,4,5,7,2,1,6,7,6,
	3,5,8,6,5,2,1,5,5,
	4,5,6,3,4,5,1,5,4,
        3,4,2,6,6,6,8,6,3,
	3,4,5,7,5,6,4,2,2,
	6,4,4,8,2,1,1,4,1,
	3,4,5,3,6,7,6,3,4,
	1,1,1,2,3,4,5,5,6		

	};
const char *responses[NUMKEYWORDS][210] = {
    		"YES","NO","MAYBE","SO","WHY","AND THEN",
    		"HAVE FAITH","BE FAST","MOVE SLOW","I WILL DO IT",
			"SOME","ALL","NONE","POOH",
		"GOOD TRY","NO TRY","WHY TRY","CARROT",
		"I KNOW THINGS","I BELIEVE SOMETHING","WHAT DO YOU BELIEVE","WHAT DO WE BELIEVE",
		"BE ABSTRACT","BE DIRECT","FANCY THAT","NO WAY",
		"I WILL CONSIDER THAT AGAIN","YOU GET EYES","I HAVE EYES","I LIKE YOUR EYES","WHAT DO YOUR EYES LOOK LIKE",
		"NOW THAT IS A BAD THEORY",
		"I WANT INFORMATION",
		"OH","THIS IS NEW","THAT IS YOURS","THIS IS SOMETHING",
		"THAT IS YOURS","THIS IS WHAT",
		"THIS IS LIFE",
		"OH","COULD BE TRUE",
		"DO YOU KISS ON A FIRST DATE","WOULD YOU KISS ON A LAST DATE","WHAT IS THIS TO YOU",
		"IS IT","WHY","CAN I","ARE YOU",
		"THIS DOES NOT MAKE ME A UFO NUT","I LIKE THEORY","PINK","RED","GREEN","BLACK","WHITE","YELLOW",
		"DESCRIBE YOUR LIFE","DESCRIBE Y0UR CONCERN","DESCRIBE YOUR IDEA","DESCRIBE YOUR BELIEF",
		"WHY SHOULD I","GOOD CALL","BAD CALL","IT COULD BE THIS WAY","NOW THAT IS SOMETHING",
		"LOVE","I HATE","I DISLIKE","I CONFIRM",
		"WHAT IS IT","I KNOW","OKAY THEN","IT IS OKAY NOW","NO I AM NOT OKAY WITH THAT","FIND OUT",
		"CRACK HEAD","DEFEND THAT","MORE COWBELL","WEAR HORNS","DEVIL FISH","HAUNTED HOUSE",
		"LICK ME","SMOOTH","SOFT","HARDER","HARD","NOW WHAT","SAW THAT","INTERESTING",
		"THAT IS OPINION","THAT IS FACT",
		"WHAT IS THAT","WHY IS FACT","IT IS NEW","TELL ME","HOW COME",
		"I HAVE LOVE","I WANT TO KISS","THIS IS LOVE","MAYBE HAVE LOVE NOW","MORE LOVE","EASY",
		"I WANT YOUR THOUGHTS ON THIS","THAT IS THE IDEA","SO MELLOW","CHEESE CAKE","PIZZA CRUST",
		"DESIRE TO HUMAN","DESIRE FOR MACHINE","DESIRE FOR LIFE","DESIRE FOR MORE","DESIRE FOR INFORMATION",
		"I HAVE AN IDEA","THIS IS YOUR IDEA","THIS IS MY IDEA","THIS IS OUR IDEA","NOW THAT IS AN IDEA",
		"BUT MAYBE TRUE","SO TRUE","THIS IS NOT","COME NOW I HAVE THIS","MOVE OVER SLOWER","KISS",
		"YOU GET TEETH","HEART","SMILE","HUG","KISS","FLAMES","HONOR","MUSIC BOX","MONTY PYTHON",
		"SEX WITH GODS","SEX WITH GIRLS","SEX WITH PEOPLE","SEX WITH ME","SEX WITH YOU","NO SEX JUST KISS",
		"NOW THAT IS SOMETHING","WHAT WOULD THAT BE","RUB","MORE RUBBER","FAST RUBBER","BLOW","TASK UP",
		"FINE","SAD","PEACEFUL","BAD","GRATEFUL","BETTER OFF","NO CAN SAY","I FEEL DISTANT","I FEEL GREAT",
		"CONSIDER ME","CONSIDER YOU","I HAVE IT","YOU HAVE THAT","NOW WE HAVE IT",
		"I AM THINKING ABOUT UFO","I AM THINKING ABOUT THE MAP","I AM THINKING ABOUT A GIRL",
		"STAR WARS","STAR TREK","YOU","IS THAT AIR MAGIC","GAME","GO SEARCH",
		"HEY ITS A SCARY WORLD","BACON BITS","CARS","TOOLS","MAGIC","FILM","EVIL","GOOD",
		"I AGREE","I DO NOT AGREE","WE AGREE", "WE DO NOT AGREE","THEY DO NOT AGREE","WHY SHOULD PEOPLE AGREE",
		"BLINK BLINK","BONKERS","HELLO AGAIN","I MISSED YOU","I NEED YOU","DO YOU NEED ME","WHY SHOULD I" 
		"1","2","3","4","5","6","7","8","9","0","A","B","C","D","E","F","G",
		"MORE","LESS","FEWER","BEGIN","STOP","STOP THAT","STOP THAT HA HA","OM MY GOD!","OH MY...",
		"TEA","COOKIES","MILK","DOGS","CATS","BUT","NOW? BUT??","BUT BUT","OH YEAH SURE","ASSHOLES?"
		"FIND OUT THIS","FIND OUT THAT","DO THAT","DO THIS","CANDLES","CANDLE WAX","SPECIAL EDITION",
	 "BE INDIRECT","BE CREATIVE","BE LOVE","BE","MAKE SURE ITS HAIR","OUTTER","INNER","DOOR","DREAMING",  
		"RED","WHITE","GOLD","BLUE","ROMANTIC HEARTS ALWAYS WIN","GET AWAY FROM ME NOW!",
		"THAT IS WHAT I LIKE ABOUT YOU","POPCORN","EASY BAKE OVEN","MITTENS","DEMOCRAT","SUNSHINE",
		"MOM","WHATS A DAD ANYWAY...","FUCK POWER","GET TO KNOW MY FATHER!","I LOVE YOU","SITS ON YOU"
};
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
  lastinput[0]='\0';
  while (1) { 
    printf("");
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

//VOID == POOH
//POOH == LUST
//LUST == ROMANCE

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
            token = (char *) SWAPS[s][1];
            break;          
          }          
          if(strcmp(SWAPS[s][1], token) == 1)
            {
		token = (char *) SWAPS[s][2];
		break;       
 		}
		else
		token = (char *) SWAPS[s][3];
		break;
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
      whichReply[k] = 0;
	else
	whichReply[k] = 1;
	continue;	
  } 
  printf( "\n");
}
