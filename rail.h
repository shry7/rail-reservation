typedef struct login {
	char id[128];
	char pass[128];
	char *password;
	} login;

typedef struct detail {
	int tno[64]; 			/* ticket no */
	char tname[128];		/* train name*/
	char bp[64];	 		/* boarding point */
	char dest[64];	 		/* destination point  */
	int c1, c2, c1fare, c2fare;	/* no of seats in class 1, no of seat in class 2, class 1 fare, class 2 fare */
	int dd , mm, yy; 		/* date - month - year */
	} detail;

typedef struct reserv {
	int pnr;
	int tno;
	char tname[64];
	char bp[64];
	char dest[128];
	char pname[8][64];
	int age[8];
	char clas[8];
	int nosr; // no of seat reserved
	int i;
	int dd,mm,yy;
	int con;
	float amc;
	} reserv;

typedef struct canc{
	int pnr;
	int tno;
	char tname[64];
	char bp[64];
	char dest[128];
	char pname[8][64];
	int age[8];
	char clas[8];
	int nosc; // no of seats cancelled 
	int i;
	int dd,mm,yy;
	int con;
	float amc;
	} canc;

void manage();
void can();
void user();
void database();
void res();
void reserv();
void displaypassdetail();
void cancell();
void enquiry();
void getcancdet();
void displaycancdet();
void getdetail();
void displaydetail();
void getid();
void displayid();
void getresdet();
void displayresdet();
