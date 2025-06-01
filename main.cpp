// Kleber Ordonez-Puac
// Lab #11

#include "demo.h"

int main() {
    srand(time(0));
    menu selection = static_cast<menu>(1);
    int userInput = 0;

    do {
        PrintMenu();

        selection = static_cast<menu>(GetNum("Make your selection: "));

        switch (selection) {
        case PLAY_GAME:
            PlayGame();
            break;
        case EXIT:
            ExitMessage();
            break;
        default:
            ClearInputError();
            cout << "\n\nInvalid selection.\n\n";
            break;
        }
    } while (selection != EXIT);
}



/*


1. Play game
2. Exit Program

Make your selection: 1


Name your army: lima


Name your opponent's army: bravo


Enter the size of the armies: 12
lima vs bravo
Army size: 12

--------------------------------------------------------------------------------------------------------

Original stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1         151       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2         247       202          BAHAMUT        CREATURE_2         136       128
NUGGLE         CREATURE_3         150       152          NUGGLE         CREATURE_3         241       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4         152       127
BAHAMUT        CREATURE_5         203       134          CYBER BAHAMUT  CREATURE_5         157       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 1

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_1         195          LIMA            CREATURE_1         151

LIMA'S CREATURE_1 has been defeated by BRAVO'S CREATURE_1


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2         247       202          BAHAMUT        CREATURE_2         136       128
NUGGLE         CREATURE_3         150       152          NUGGLE         CREATURE_3         241       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4         152       127
BAHAMUT        CREATURE_5         203       134          CYBER BAHAMUT  CREATURE_5         157       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 2

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_2          91          LIMA            CREATURE_2         247
LIMA            CREATURE_2         114          BRAVO           CREATURE_2         136
BRAVO           CREATURE_2         140          LIMA            CREATURE_2         156
LIMA            CREATURE_2           9          BRAVO           CREATURE_2          22
BRAVO           CREATURE_2          32          LIMA            CREATURE_2          16

LIMA'S CREATURE_2 has been defeated by BRAVO'S CREATURE_2


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3         150       152          NUGGLE         CREATURE_3         241       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4         152       127
BAHAMUT        CREATURE_5         203       134          CYBER BAHAMUT  CREATURE_5         157       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 3

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_3          63          BRAVO           CREATURE_3         241
BRAVO           CREATURE_3         103          LIMA            CREATURE_3         150
LIMA            CREATURE_3          98          BRAVO           CREATURE_3         178
BRAVO           CREATURE_3          38          LIMA            CREATURE_3          47
LIMA            CREATURE_3           1          BRAVO           CREATURE_3          80
BRAVO           CREATURE_3         152          LIMA            CREATURE_3           9

LIMA'S CREATURE_3 has been defeated by BRAVO'S CREATURE_3


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4         152       127
BAHAMUT        CREATURE_5         203       134          CYBER BAHAMUT  CREATURE_5         157       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 4

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_4         338          BRAVO           CREATURE_4         152

BRAVO'S CREATURE_4 has been defeated by LIMA'S CREATURE_4


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5         203       134          CYBER BAHAMUT  CREATURE_5         157       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 5

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_5         134          LIMA            CREATURE_5         203
LIMA            CREATURE_5          98          BRAVO           CREATURE_5         157
BRAVO           CREATURE_5         144          LIMA            CREATURE_5          69

LIMA'S CREATURE_5 has been defeated by BRAVO'S CREATURE_5


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6         208       219          NUGGLE         CREATURE_6         207       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 6

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_6         136          LIMA            CREATURE_6         208
LIMA            CREATURE_6         434          BRAVO           CREATURE_6         207

BRAVO'S CREATURE_6 has been defeated by LIMA'S CREATURE_6


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         178       169          NUGGLE         CREATURE_7         192       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 7

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_7          74          BRAVO           CREATURE_7         192
BRAVO           CREATURE_7          35          LIMA            CREATURE_7         178
LIMA            CREATURE_7         194          BRAVO           CREATURE_7         118

BRAVO'S CREATURE_7 has been defeated by LIMA'S CREATURE_7


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         134       183          NUGGLE         CREATURE_8         205       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 8

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_8         163          BRAVO           CREATURE_8         205
BRAVO           CREATURE_8          26          LIMA            CREATURE_8         134
LIMA            CREATURE_8          89          BRAVO           CREATURE_8          42

BRAVO'S CREATURE_8 has been defeated by LIMA'S CREATURE_8


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         108       183          NUGGLE         CREATURE_8           0       147
CYBER BAHAMUT  CREATURE_9         215       132          BAHAMUT        CREATURE_9         174       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 9

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_9         150          BRAVO           CREATURE_9         174
BRAVO           CREATURE_9         159          LIMA            CREATURE_9         215
LIMA            CREATURE_9         131          BRAVO           CREATURE_9          24

BRAVO'S CREATURE_9 has been defeated by LIMA'S CREATURE_9


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         108       183          NUGGLE         CREATURE_8           0       147
CYBER BAHAMUT  CREATURE_9          56       132          BAHAMUT        CREATURE_9           0       177
CYBER BAHAMUT  CREATURE_10        245       178          CYBER BAHAMUT  CREATURE_10        243       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 10

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_10        103          LIMA            CREATURE_10        245
LIMA            CREATURE_10        171          BRAVO           CREATURE_10        243
BRAVO           CREATURE_10        227          LIMA            CREATURE_10        142

LIMA'S CREATURE_10 has been defeated by BRAVO'S CREATURE_10


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         108       183          NUGGLE         CREATURE_8           0       147
CYBER BAHAMUT  CREATURE_9          56       132          BAHAMUT        CREATURE_9           0       177
CYBER BAHAMUT  CREATURE_10          0       178          CYBER BAHAMUT  CREATURE_10         72       129
BAHAMUT        CREATURE_11        185       145          NUGGLE         CREATURE_11        121       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 11

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

BRAVO           CREATURE_11        133          LIMA            CREATURE_11        185
LIMA            CREATURE_11         68          BRAVO           CREATURE_11        121
BRAVO           CREATURE_11         68          LIMA            CREATURE_11         52

LIMA'S CREATURE_11 has been defeated by BRAVO'S CREATURE_11


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         108       183          NUGGLE         CREATURE_8           0       147
CYBER BAHAMUT  CREATURE_9          56       132          BAHAMUT        CREATURE_9           0       177
CYBER BAHAMUT  CREATURE_10          0       178          CYBER BAHAMUT  CREATURE_10         72       129
BAHAMUT        CREATURE_11          0       145          NUGGLE         CREATURE_11         53       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12        216       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

Round 12

ARMY            ATTACKER        DAMAGE          ARMY            DEFENDER        HEALTH

LIMA            CREATURE_12        228          BRAVO           CREATURE_12        216

BRAVO'S CREATURE_12 has been defeated by LIMA'S CREATURE_12


Current stats:

LIMA                                                     BRAVO

TYPE           NAME            HEALTH  STRENGTH          TYPE           NAME            HEALTH  STRENGTH

BAHAMUT        CREATURE_1           0       138          CYBER BAHAMUT  CREATURE_1         121       237
CEFFYL         CREATURE_2           0       202          BAHAMUT        CREATURE_2          13       128
NUGGLE         CREATURE_3           0       152          NUGGLE         CREATURE_3          79       223
CYBER BAHAMUT  CREATURE_4         247       248          BAHAMUT        CREATURE_4           0       127
BAHAMUT        CREATURE_5           0       134          CYBER BAHAMUT  CREATURE_5          59       212
NUGGLE         CREATURE_6          72       219          NUGGLE         CREATURE_6           0       179
BAHAMUT        CREATURE_7         143       169          NUGGLE         CREATURE_7           0       136
CEFFYL         CREATURE_8         108       183          NUGGLE         CREATURE_8           0       147
CYBER BAHAMUT  CREATURE_9          56       132          BAHAMUT        CREATURE_9           0       177
CYBER BAHAMUT  CREATURE_10          0       178          CYBER BAHAMUT  CREATURE_10         72       129
BAHAMUT        CREATURE_11          0       145          NUGGLE         CREATURE_11         53       151
CYBER BAHAMUT  CREATURE_12        241       202          CYBER BAHAMUT  CREATURE_12          0       218

--------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------

LIMA has won with a net health of 867 to BRAVO'S net health of 397

--------------------------------------------------------------------------------------------------------

Game has ended



1. Play game
2. Exit Program

Make your selection: 2


Program will exit

*/