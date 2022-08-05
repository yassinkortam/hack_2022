//Alien Years | Yassin Kortam

//Pin Definitions
//Drive motors
#define M1R 12 //orientation control 1 right
#define M1L 27 //orientation control 1 left
#define M2R 33 //orientation control 2 right
#define M2L 15 //orientation control 2 left
#define ER 32 //speed control right
#define EL 14 //speed control left

//Servo motors
#define SR 26
#define SL 25
#define S_MAX 180
#define S_TRANS 100

//Drive constants
#define W 7 //expirementally derived angular velocity
#define V_MAX 240 //highest possible analog output for velocity
#define V_TURN 240 //turning velocity
#define V_DELAY 50 //delay in velocity change

//User input constants
#define V_INC 20 //user input velocity increments
#define R_INC 0.25 //user input angle increments
#define S_INC 20 //user input servo angle increments

//Dance constants
#define V_DANCE 100 //dance maximum speed
#define R_DANCE 1.57 //dance turn angle radians
