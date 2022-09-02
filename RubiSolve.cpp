#include <iostream>
#include <string>
#include <chrono>

int oli = 0;
bool me = true;
bool check = true;
int pri = 0;

int startArt(){
    std::cout << "<================================================================================================>" << std::endl;

    std::cout << "*   ______              ______    _____         ______     ______                        ______  *" << std::endl;
    std::cout << "*  |      |  |      |  |      \\     |          |          /      \\   |        \\      /  |        *" << std::endl;
    std::cout << "*  |______|  |      |  |______/     |          |______   |        |  |         \\    /   |___     *" << std::endl;
    std::cout << "*  |    \\    |      |  |      \\     |                 |  |        |  |          \\  /    |        *" << std::endl;
    std::cout << "*  |     \\   |______|  |______/   __|__         ______|   \\______/   |______     \\/     |______  *" << std::endl;
    std::cout << "*                                                                                                *"<<std::endl;

    std::cout << "<================================================================================================>" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
}

int help(){
    std::cout << std::endl << std::endl << "RUBI SOLVE SYNTAX" << std::endl << "" << std::endl << "video demonstration : <upcoming>" << std::endl << std::endl

        << "R - turn right side clockwise by 90 degrees" << std::endl << "L - turn left side clockwise by 90 degrees" << std::endl << "F - turn front side clockwise by 90 degrees" << std::endl
        << "D - turn lower side clockwise by 90 degrees" << std::endl << "U - turn upper side clockwise by 90 degrees" << std::endl
        << "B - turn back side clockwise by 90 degrees (when holding the backside to the front)" << std::endl << "M - turn the layer between L and R by 90 degrees downwards" << std::endl
        << "E - turn the layer between U and D by 90 degrees to the right"<< std::endl << "S - turn the layer between F and B by 90 degrees clockwise" << std::endl << std::endl
        
        << "Letter + ' --> turn counterclockwise" << std::endl << "Letter + 2 --> turn twice" << std::endl << "Lowercase letter --> turn the middle layer along (not possible for M, E, S)" << std::endl << std::endl
        
        << "x - turn the cube by 90 degrees so that the top side ends up at the back" << std::endl << "y - turn the cube by 90 degrees so that the front side ends up on the left"
        << std::endl << "z - turn the cube by 90 degrees so that the top side ends up on the right" << std::endl << std::endl
        << "sample scramble: RUR'LF2B2DuRF'2U'2M'xdR2" << std::endl << std::endl;
}

int checkSyntax(std::string a, char instructions[])
{
    int i = 0;
    // std::vector<std::string> instructions = {};
    // std::cout << a.length();
    while (i != a.length())
    {
        if (a.at(i) == 'R' or a.at(i) == 'L' or a.at(i) == 'U' or a.at(i) == 'F' or a.at(i) == 'B' or a.at(i) == 'D' or
            a.at(i) == 'r' or a.at(i) == 'l' or a.at(i) == 'u' or a.at(i) == 'f' or a.at(i) == 'b' or a.at(i) == 'd' or
            a.at(i) == 'M' or a.at(i) == 'E' or a.at(i) == 'S' or a.at(i) == 'x' or a.at(i) == 'y' or a.at(i) == 'z' or
            (a.at(i) == '2' and a.at(i-1) != '2') or a.at(i) == '\'' and a.at(i-1) != '2' and a.at(i-1) != '\'')
        {

            // std::cout << a.at(i);
            
            instructions[i] = a.at(i);

            i ++;
        }
        else
        {
            std::cout << "Syntax error, check for correct spelling of your scramble" << std::endl << std::endl;
            oli = 1;
            break;
        }
    }
}   
typedef int (*moves)(int cube[]);

int uprime(int cube[]){
    // first rotate the outer ring
    int buffer1 = cube[9];
    int buffer2 = cube[10];
    int buffer3 = cube[11];

    cube[9] = cube[36];
    cube[10] = cube[37];
    cube[11] = cube[38];

    cube[36] = cube[27];
    cube[37] = cube[28];
    cube[38] = cube[29];

    cube[27] = cube[18];
    cube[28] = cube[19];
    cube[29] = cube[20];

    cube[18] = buffer1;
    cube[19] = buffer2;
    cube[20] = buffer3;
    // circle the face around
    int buffer4 = cube[0];
    int buffer5 = cube[1];
    // corners first
    cube[0] = cube[2];
    cube[2] = cube[8];
    cube[8] = cube[6];
    cube[6] = buffer4;
    // then the edges
    cube[1] = cube[5];
    cube[5] = cube[7];
    cube[7] = cube[3];
    cube[3] = buffer5;
}

int unormal(int cube[]){

    int buffer1 = cube[9];
    int buffer2 = cube[10];
    int buffer3 = cube[11];

    cube[9] = cube[18];
    cube[10] = cube[19];
    cube[11] = cube[20];

    cube[18] = cube[27];
    cube[19] = cube[28];
    cube[20] = cube[29];

    cube[27] = cube[36];
    cube[28] = cube[37];
    cube[29] = cube[38];

    cube[36] = buffer1;
    cube[37] = buffer2;
    cube[38] = buffer3;
    
    int buffer4 = cube[0];
    int buffer5 = cube[1];
    
    cube[0] = cube[6];
    cube[6] = cube[8];
    cube[8] = cube[2];
    cube[2] = buffer4;
    
    cube[1] = cube[3];
    cube[3] = cube[7];
    cube[7] = cube[5];
    cube[5] = buffer5;
}

int utwo(int cube[]){
    unormal(cube);
    unormal(cube);
}

int rprime(int cube[]){

    int buffer1 = cube[11];
    int buffer2 = cube[14];
    int buffer3 = cube[17];

    cube[11] = cube[2];
    cube[14] = cube[5];
    cube[17] = cube[8];

    cube[8] = cube[27];
    cube[5] = cube[30];
    cube[2] = cube[33];

    cube[27] = cube[53];
    cube[30] = cube[50];
    cube[33] = cube[47];

    cube[47] = buffer1;
    cube[50] = buffer2;
    cube[53] = buffer3;

    int buffer4 = cube[18];
    int buffer5 = cube[19];

    cube[18] = cube[20];
    cube[20] = cube[26];
    cube[26] = cube[24];
    cube[24] = buffer4;
    
    cube[19] = cube[23];
    cube[23] = cube[25];
    cube[25] = cube[21];
    cube[21] = buffer5;
}

int rnormal(int cube[]){

    int buffer1 = cube[11];
    int buffer2 = cube[14];
    int buffer3 = cube[17];

    cube[11] = cube[47];
    cube[14] = cube[50];
    cube[17] = cube[53];

    cube[47] = cube[33];
    cube[50] = cube[30];
    cube[53] = cube[27];

    cube[33] = cube[2];
    cube[30] = cube[5];
    cube[27] = cube[8];

    cube[2] = buffer1;
    cube[5] = buffer2;
    cube[8] = buffer3;

    int buffer4 = cube[18];
    int buffer5 = cube[19];
    
    cube[18] = cube[24];
    cube[24] = cube[26];
    cube[26] = cube[20];
    cube[20] = buffer4;
    
    cube[19] = cube[21];
    cube[21] = cube[25];
    cube[25] = cube[23];
    cube[23] = buffer5;
}

int lprime(int cube[]){

    int buffer1 = cube[0];
    int buffer2 = cube[3];
    int buffer3 = cube[6];

    cube[0] = cube[9];
    cube[3] = cube[12];
    cube[6] = cube[15];

    cube[9] = cube[45];
    cube[12] = cube[48];
    cube[15] = cube[51];

    cube[45] = cube[35];
    cube[48] = cube[32];
    cube[51] = cube[29];

    cube[35] = buffer1;
    cube[32] = buffer2;
    cube[29] = buffer3;

    int buffer4 = cube[36];
    int buffer5 = cube[37];
    
    cube[36] = cube[38];
    cube[38] = cube[44];
    cube[44] = cube[42];
    cube[42] = buffer4;
    
    cube[37] = cube[41];
    cube[41] = cube[43];
    cube[43] = cube[39];
    cube[39] = buffer5;
}

int lnormal(int cube[]){

    int buffer1 = cube[0];
    int buffer2 = cube[3];
    int buffer3 = cube[6];

    cube[0] = cube[35];
    cube[3] = cube[32];
    cube[6] = cube[29];

    cube[29] = cube[51];
    cube[32] = cube[48];
    cube[35] = cube[45];

    cube[45] = cube[9];
    cube[48] = cube[12];
    cube[51] = cube[15];

    cube[9] = buffer1;
    cube[12] = buffer2;
    cube[15] = buffer3;

    int buffer4 = cube[36];
    int buffer5 = cube[37];
    
    cube[36] = cube[42];
    cube[42] = cube[44];
    cube[44] = cube[38];
    cube[38] = buffer4;
    
    cube[37] = cube[39];
    cube[39] = cube[43];
    cube[43] = cube[41];
    cube[41] = buffer5;
}

int ltwo(int cube[]){
    lnormal(cube);
    lnormal(cube);
}
    
int fprime(int cube[]){

    int buffer1 = cube[6];
    int buffer2 = cube[7];
    int buffer3 = cube[8];

    cube[6] = cube[18];
    cube[7] = cube[21];
    cube[8] = cube[24];

    cube[18] = cube[47];
    cube[21] = cube[46];
    cube[24] = cube[45];

    cube[45] = cube[38];
    cube[46] = cube[41];
    cube[47] = cube[44];

    cube[44] = buffer1;
    cube[41] = buffer2;
    cube[38] = buffer3;

    int buffer4 = cube[9];
    int buffer5 = cube[10];
    
    cube[9] = cube[11];
    cube[11] = cube[17];
    cube[17] = cube[15];
    cube[15] = buffer4;
    
    cube[10] = cube[14];
    cube[14] = cube[16];
    cube[16] = cube[12];
    cube[12] = buffer5;
}

int fnormal(int cube[]){

    int buffer1 = cube[6];
    int buffer2 = cube[7];
    int buffer3 = cube[8];

    cube[6] = cube[44];
    cube[7] = cube[41];
    cube[8] = cube[38];

    cube[38] = cube[45];
    cube[41] = cube[46];
    cube[44] = cube[47];

    cube[45] = cube[24];
    cube[46] = cube[21];
    cube[47] = cube[18];

    cube[18] = buffer1;
    cube[21] = buffer2;
    cube[24] = buffer3;

    int buffer4 = cube[9];
    int buffer5 = cube[10];
    
    cube[9] = cube[15];
    cube[15] = cube[17];
    cube[17] = cube[11];
    cube[11] = buffer4;
    
    cube[10] = cube[12];
    cube[12] = cube[16];
    cube[16] = cube[14];
    cube[14] = buffer5;
}

int dprime(int cube[]){

    int buffer1 = cube[15];
    int buffer2 = cube[16];
    int buffer3 = cube[17];

    cube[15] = cube[24];
    cube[16] = cube[25];
    cube[17] = cube[26];

    cube[24] = cube[33];
    cube[25] = cube[34];
    cube[26] = cube[35];

    cube[33] = cube[42];
    cube[34] = cube[43];
    cube[35] = cube[44];

    cube[42] = buffer1;
    cube[43] = buffer2;
    cube[44] = buffer3;

    int buffer4 = cube[45];
    int buffer5 = cube[46];
    
    cube[45] = cube[47];
    cube[47] = cube[53];
    cube[53] = cube[51];
    cube[51] = buffer4;
    
    cube[46] = cube[50];
    cube[50] = cube[52];
    cube[52] = cube[48];
    cube[48] = buffer5;
}

int dnormal(int cube[]){

    int buffer1 = cube[15];
    int buffer2 = cube[16];
    int buffer3 = cube[17];

    cube[15] = cube[42];
    cube[16] = cube[43];
    cube[17] = cube[44];

    cube[42] = cube[33];
    cube[43] = cube[34];
    cube[44] = cube[35];

    cube[33] = cube[24];
    cube[34] = cube[25];
    cube[35] = cube[26];

    cube[24] = buffer1;
    cube[25] = buffer2;
    cube[26] = buffer3;

    int buffer4 = cube[45];
    int buffer5 = cube[46];
    
    cube[45] = cube[51];
    cube[51] = cube[53];
    cube[53] = cube[47];
    cube[47] = buffer4;
    
    cube[46] = cube[48];
    cube[48] = cube[52];
    cube[52] = cube[50];
    cube[50] = buffer5;
}

int bprime(int cube[]){

    int buffer1 = cube[0];
    int buffer2 = cube[1];
    int buffer3 = cube[2];

    cube[2] = cube[36];
    cube[1] = cube[39];
    cube[0] = cube[42];

    cube[36] = cube[51];
    cube[39] = cube[52];
    cube[42] = cube[53];

    cube[51] = cube[26];
    cube[52] = cube[23];
    cube[53] = cube[20];

    cube[20] = buffer1;
    cube[23] = buffer2;
    cube[26] = buffer3;

    int buffer4 = cube[27];
    int buffer5 = cube[28];
    
    cube[27] = cube[29];
    cube[29] = cube[35];
    cube[35] = cube[33];
    cube[33] = buffer4;
    
    cube[28] = cube[32];
    cube[32] = cube[34];
    cube[34] = cube[30];
    cube[30] = buffer5;
}

int bnormal(int cube[]){

    int buffer1 = cube[0];
    int buffer2 = cube[1];
    int buffer3 = cube[2];

    cube[0] = cube[20];
    cube[1] = cube[23];
    cube[2] = cube[26];

    cube[20] = cube[53];
    cube[23] = cube[52];
    cube[26] = cube[51];

    cube[51] = cube[36];
    cube[52] = cube[39];
    cube[53] = cube[42];

    cube[42] = buffer1;
    cube[39] = buffer2;
    cube[36] = buffer3;

    int buffer4 = cube[27];
    int buffer5 = cube[28];
    
    cube[27] = cube[33];
    cube[33] = cube[35];
    cube[35] = cube[29];
    cube[29] = buffer4;
    
    cube[28] = cube[30];
    cube[30] = cube[34];
    cube[34] = cube[32];
    cube[32] = buffer5;
}

int btwo(int cube[]){
    bnormal(cube);
    bnormal(cube);
}

int mprime(int cube[]){
    // middle ring rotation
    int buffer1 = cube[1];
    int buffer2 = cube[4];
    int buffer3 = cube[7];

    cube[1] = cube[10];
    cube[4] = cube[13];
    cube[7] = cube[16];

    cube[10] = cube[46];
    cube[13] = cube[49];
    cube[16] = cube[52];

    cube[46] = cube[34];
    cube[49] = cube[31];
    cube[52] = cube[28];

    cube[34] = buffer1;
    cube[31] = buffer2;
    cube[28] = buffer3;
    // no face for the middle ring(s)
}

int mnormal(int cube[]){

    int buffer1 = cube[1];
    int buffer2 = cube[4];
    int buffer3 = cube[7];

    cube[1] = cube[34];
    cube[4] = cube[31];
    cube[7] = cube[28];

    cube[34] = cube[46];
    cube[31] = cube[49];
    cube[28] = cube[52];

    cube[46] = cube[10];
    cube[49] = cube[13];
    cube[52] = cube[16];

    cube[10] = buffer1;
    cube[13] = buffer2;
    cube[16] = buffer3;
}

int eprime(int cube[]){

    int buffer1 = cube[12];
    int buffer2 = cube[13];
    int buffer3 = cube[14];

    cube[12] = cube[21];
    cube[13] = cube[22];
    cube[14] = cube[23];

    cube[21] = cube[30];
    cube[22] = cube[31];
    cube[23] = cube[32];

    cube[30] = cube[39];
    cube[31] = cube[40];
    cube[32] = cube[41];

    cube[39] = buffer1;
    cube[40] = buffer2;
    cube[41] = buffer3;
}

int enormal(int cube[]){

    int buffer1 = cube[12];
    int buffer2 = cube[13];
    int buffer3 = cube[14];

    cube[12] = cube[39];
    cube[13] = cube[40];
    cube[14] = cube[41];

    cube[39] = cube[30];
    cube[40] = cube[31];
    cube[41] = cube[32];

    cube[30] = cube[21];
    cube[31] = cube[22];
    cube[32] = cube[23];

    cube[21] = buffer1;
    cube[22] = buffer2;
    cube[23] = buffer3;
}

int sprime(int cube[]){

    int buffer1 = cube[3];
    int buffer2 = cube[4];
    int buffer3 = cube[5];

    cube[3] = cube[19];
    cube[4] = cube[22];
    cube[5] = cube[25];

    cube[19] = cube[50];
    cube[22] = cube[49];
    cube[25] = cube[48];

    cube[48] = cube[37];
    cube[49] = cube[40];
    cube[50] = cube[43];

    cube[37] = buffer3;
    cube[40] = buffer2;
    cube[43] = buffer1;
}

int snormal(int cube[]){

    int buffer1 = cube[3];
    int buffer2 = cube[4];
    int buffer3 = cube[5];

    cube[3] = cube[43];
    cube[4] = cube[40];
    cube[5] = cube[37];

    cube[37] = cube[48];
    cube[40] = cube[49];
    cube[43] = cube[50];

    cube[48] = cube[25];
    cube[49] = cube[22];
    cube[50] = cube[19];

    cube[19] = buffer1;
    cube[22] = buffer2;
    cube[25] = buffer3;
}

int xprime(int cube[]){

    lnormal(cube);
    mnormal(cube);
    rprime(cube);
}

int xnormal(int cube[]){

    lprime(cube);
    mprime(cube);
    rnormal(cube);
}

int yprime(int cube[]){

    dnormal(cube);
    enormal(cube);
    uprime(cube);
}

int ynormal(int cube[]){

    dprime(cube);
    eprime(cube);
    unormal(cube);
}

int zprime(int cube[]){

    bnormal(cube);
    sprime(cube);
    fprime(cube);
}

int znormal(int cube[]){

    bprime(cube);
    snormal(cube);
    fnormal(cube);
}

int rotate_to_starting_position(int cube[]){

    if (cube[49] != 6){
        if (cube[4] == 6){
            xnormal(cube);
            xnormal(cube);
            std::cout << "white side : [ x2 ]\n\n";
        }
        else if (cube[13] == 6){
            xprime(cube);
            std::cout << "white side : [ x' ]\n\n";
        }
        else if (cube[22] == 6){
            znormal(cube);
            std::cout << "white side : [ z ]\n\n";
        }
        else if (cube[31] == 6){
            xnormal(cube);
            std::cout << "white side : [ x ]\n\n";
        }
        else{
            zprime(cube);
            std::cout << "white side : [ z' ]\n\n";
        }
    }
    else{std::cout << "white side : [ already at the bottom ]\n\n";}
    if (cube[13] != 2){
                int counti = 0;
                while (true){
                    if (cube[13] != 2){
                        ynormal(cube);
                        counti ++;
                    }
                    else{break;}
                }
                std::string aha;
                if (counti == 3){aha = "y'";}
                else if (counti == 2){aha = "y2";}
                else {aha = "y";}
                std::cout << "now hold the blue side towards yourself\n[ " << aha << " ]\n\n";     
            }
}

int solve_white_cross(int cube[]){

    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5)
        {std::cout << "white cross is already solved...\n";}
    else{

    moves possis[] = {mprime, mnormal,
                     sprime, snormal,
                     rprime, rnormal,
                     fprime, fnormal,
                     lprime, lnormal,
                     bprime, bnormal,
                     uprime, unormal,
                     dprime, dnormal,
                     };
    
    moves antipossis[] = {mnormal, mprime,
                          snormal, sprime,
                          rnormal, rprime,
                          fnormal, fprime,
                          lnormal, lprime,
                          bnormal, bprime,
                          unormal, uprime,
                          dnormal, dprime,
                          };

    int le = 16;

    int o = 0;
    int l = 0;
    int i = 0;
    int o2 = 0;
    int l2 = 0;
    int i2 = 0;
    int o3 = 0;
    int l3 = 0;
    int i3 = 0;
    int o4 = 0;

    me = true;

    std::string charset[16] = {"M'", "M",
                               "S'", "S",
                               "R'", "R",
                               "F'", "F",
                               "L'", "L",
                               "B'", "B",
                               "U'", "U",
                               "D'", "D"
                               };

    std::string solution;
    solution = "";
    std::cout << solution;
/*------------------------------------------------------------------------------------------- 1 -----------------------------------------------------------------------------------*/
    while (i < le){
        possis[i](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[i];
            me = false;
            break;}
        else
        {
            antipossis[i](cube);
            }
        i ++;
    }
/*------------------------------------------------------------------------------------------- 2 -----------------------------------------------------------------------------------*/
    if (me == true){
    while (l < le){
        if (me == false){break;}
        possis[l](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[l];
            me = false;
            break;
        }
        else
        {
            i = 0;
            while (i < le){
                possis[i](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                    solution += charset[l];
                    if (charset[l] == charset[i]){solution += '2';}
                    else{solution += charset[i];}
                    me = false;
                    break;}
                else
                {
                    antipossis[i](cube);
                    }
                i ++;
            }
            if (me == false){break;}
            antipossis[l](cube);
        }
        l ++;
    }
/*------------------------------------------------------------------------------------------- 3 -----------------------------------------------------------------------------------*/
    if (me == true){
    while (o < le){
        if (me == false){break;}
        possis[o](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[o];
            me = false;
            break;
        }
        else{
            l = 0;
            while (l < le){
                if (me == false){break;}
                possis[l](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                    solution += charset[o];
                    if (charset[o] == charset[l]){solution += '2';}
                    else{solution += charset[l];}
                    me = false;
                    break;
                }
                else
                {
                    i = 0;
                    while (i < le){
                        possis[i](cube);
                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                            solution += charset[o];
                            if (charset[o] == charset[l]){solution += '2';}
                            else{solution += charset[l];}
                            if (charset[l] == charset[i]){solution += '2';}
                            else{solution += charset[i];}
                            me = false;
                            break;}
                        else
                        {
                            antipossis[i](cube);
                            }
                        i ++;
                    }
                    if (me == false){break;}
                    antipossis[l](cube);
                }
                l ++;
            }
            if (me == false){break;}
                antipossis[o](cube);
            }
            o ++;
        }
/*------------------------------------------------------------------------------------------- 4 -----------------------------------------------------------------------------------*/
    if (me == true){
    while (i2 < le){
        if (me == false){break;}
        possis[i2](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[i2];
            me = false;
            break;
        }
    else{
        o = 0;
        while (o < le){
            if (me == false){break;}
            possis[o](cube);
            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                solution += charset[i2];
                if (charset[i2] == charset[o]){solution += '2';}
                else{solution += charset[o];}
                me = false;
                break;
            }
            else{
                l = 0;
                while (l < le){
                    if (me == false){break;}
                    possis[l](cube);
                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                        solution += charset[i2];
                        if (charset[i2] == charset[o]){solution += '2';}
                        else{solution += charset[o];}
                        if (charset[o] == charset[l]){solution += '2';}
                        else{solution += charset[l];}
                        me = false;
                        break;
                    }
                    else
                    {
                        i = 0;
                        while (i < le){
                            possis[i](cube);
                                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                solution += charset[i2];
                                if (charset[i2] == charset[o]){solution += '2';}
                                else{solution += charset[o];}
                                if (charset[o] == charset[l]){solution += '2';}
                                else{solution += charset[l];}
                                if (charset[l] == charset[i]){solution += '2';}
                                else{solution += charset[i];}
                                me = false;
                                break;}
                            else
                            {
                                antipossis[i](cube);
                                }
                            i ++;
                        }
                        if (me == false){break;}
                        antipossis[l](cube);
                    }
                    l ++;
                }
                if (me == false){break;}
                    antipossis[o](cube);
                }
                o ++;
            }
            if (me == false){break;}
            antipossis[i2](cube);
        }
        i2 ++;
    }
/*------------------------------------------------------------------------------------------- 5 -----------------------------------------------------------------------------------*/
    if (me == true){
    while (l2 < le){
        if (me == false){break;}
        possis[l2](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[l2];
            me = false;
            break;
        }
        else{
            i2 = 0;
        while (i2 < le){
            if (me == false){break;}
            possis[i2](cube);
            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                solution += charset[l2];
                if (charset[l2] == charset[i2]){solution += '2';}
                else{solution += charset[i2];}
                me = false;
                break;
            }
        else{
            o = 0;
            while (o < le){
                if (me == false){break;}
                possis[o](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                    solution += charset[l2];
                    if (charset[l2] == charset[i2]){solution += '2';}
                    else{solution += charset[i2];}
                    if (charset[i2] == charset[o]){solution += '2';}
                    else{solution += charset[o];}
                    me = false;
                    break;
                }
                else{
                    l = 0;
                    while (l < le){
                        if (me == false){break;}
                        possis[l](cube);
                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                            solution += charset[l2];
                            if (charset[l2] == charset[i2]){solution += '2';}
                            else{solution += charset[i2];}
                            if (charset[i2] == charset[o]){solution += '2';}
                            else{solution += charset[o];}
                            if (charset[o] == charset[l]){solution += '2';}
                            else{solution += charset[l];}
                            me = false;
                            break;
                        }
                        else
                        {
                            i = 0;
                            while (i < le){
                                possis[i](cube);
                                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                    solution += charset[l2];
                                    if (charset[l2] == charset[i2]){solution += '2';}
                                    else{solution += charset[i2];}
                                    if (charset[i2] == charset[o]){solution += '2';}
                                    else{solution += charset[o];}
                                    if (charset[o] == charset[l]){solution += '2';}
                                    else{solution += charset[l];}
                                    if (charset[l] == charset[i]){solution += '2';}
                                    else{solution += charset[i];}
                                    me = false;
                                    break;}
                                else
                                {
                                    antipossis[i](cube);
                                    }
                                i ++;
                            }
                            if (me == false){break;}
                            antipossis[l](cube);
                        }
                        l ++;
                    }
                    if (me == false){break;}
                    antipossis[o](cube);
                    }
                    o ++;
                }
                if (me == false){break;}
                antipossis[i2](cube);
            }
            i2 ++;
        }
        if (me == false){break;}
        antipossis[l2](cube);
        }
        l2 ++;
    }
/*------------------------------------------------------------------------------------------- 6 -----------------------------------------------------------------------------------*/
    if (me == true){
    while (o2 < le){
        if (me == false){break;}
        possis[o2](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[o2];
            me = false;
            break;
        }
        else{
            l2 = 0;
            while (l2 < le){
                if (me == false){break;}
                possis[l2](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                    solution += charset[o2];
                    if (charset[o2] == charset[l2]){solution += '2';}
                    else{solution += charset[l2];}
                    me = false;
                    break;
                }
                else{
                i2 = 0;
                while (i2 < le){
                    if (me == false){break;}
                    possis[i2](cube);
                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                        solution += charset[o2];
                        if (charset[o2] == charset[l2]){solution += '2';}
                        else{solution += charset[l2];}
                        if (charset[l2] == charset[i2]){solution += '2';}
                        else{solution += charset[i2];}
                        me = false;
                        break;
                    }
                else{
                    o = 0;
                    while (o < le){
                        if (me == false){break;}
                        possis[o](cube);
                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                            solution += charset[o2];
                            if (charset[o2] == charset[l2]){solution += '2';}
                            else{solution += charset[l2];}
                            if (charset[l2] == charset[i2]){solution += '2';}
                            else{solution += charset[i2];}
                            if (charset[i2] == charset[o]){solution += '2';}
                            else{solution += charset[o];}
                            me = false;
                            break;
                        }
                        else{
                            l = 0;
                            while (l < le){
                                if (me == false){break;}
                                possis[l](cube);
                                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                    solution += charset[o2];
                                    if (charset[o2] == charset[l2]){solution += '2';}
                                    else{solution += charset[l2];}
                                    if (charset[l2] == charset[i2]){solution += '2';}
                                    else{solution += charset[i2];}
                                    if (charset[i2] == charset[o]){solution += '2';}
                                    else{solution += charset[o];}
                                    if (charset[o] == charset[l]){solution += '2';}
                                    else{solution += charset[l];}
                                    me = false;
                                    break;
                                }
                                else
                                {
                                    i = 0;
                                    while (i < le){
                                        possis[i](cube);
                                            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                            solution += charset[o2];
                                            if (charset[o2] == charset[l2]){solution += '2';}
                                            else{solution += charset[l2];}
                                            if (charset[l2] == charset[i2]){solution += '2';}
                                            else{solution += charset[i2];}
                                            if (charset[i2] == charset[o]){solution += '2';}
                                            else{solution += charset[o];}
                                            if (charset[o] == charset[l]){solution += '2';}
                                            else{solution += charset[l];}
                                            if (charset[l] == charset[i]){solution += '2';}
                                            else{solution += charset[i];}
                                            me = false;
                                            break;}
                                        else
                                        {
                                            antipossis[i](cube);
                                            }
                                        i ++;
                                    }
                                    if (me == false){break;}
                                    antipossis[l](cube);
                                }
                                l ++;
                            }
                            if (me == false){break;}
                            antipossis[o](cube);
                            }
                            o ++;
                        }
                        if (me == false){break;}
                        antipossis[i2](cube);
                    }
                    i2 ++;
                }
                if (me == false){break;}
                antipossis[l2](cube);
            }
            l2 ++;
        }
        if (me == false){break;}
        antipossis[o2](cube);
    }
    o2 ++;
    }
/*------------------------------------------------------------------------------------------- 7 -----------------------------------------------------------------------------------*/
if (me == true){
    while (i3 < le){
        if (me == false){break;}
        possis[i3](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
            solution += charset[i3];
            me = false;
            break;
        }
        else{
            o2 = 0;
            while (o2 < le){
                if (me == false){break;}
                possis[o2](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                    solution += charset[i3];
                    if (charset[i3] == charset[o2]){solution += '2';}
                    else{solution += charset[o2];}
                    me = false;
                    break;
                }
                else{
                    l2 = 0;
                    while (l2 < le){
                        if (me == false){break;}
                        possis[l2](cube);
                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                            solution += charset[i3];
                            if (charset[i3] == charset[o2]){solution += '2';}
                            else{solution += charset[o2];}
                            if (charset[o2] == charset[l2]){solution += '2';}
                            else{solution += charset[l2];}
                            me = false;
                            break;
                        }
                        else{
                        i2 = 0;
                        while (i2 < le){
                            if (me == false){break;}
                            possis[i2](cube);
                            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                solution += charset[i3];
                                if (charset[i3] == charset[o2]){solution += '2';}
                                else{solution += charset[o2];}
                                if (charset[o2] == charset[l2]){solution += '2';}
                                else{solution += charset[l2];}
                                if (charset[l2] == charset[i2]){solution += '2';}
                                else{solution += charset[i2];}
                                me = false;
                                break;
                            }
                        else{
                            o = 0;
                            while (o < le){
                                if (me == false){break;}
                                possis[o](cube);
                                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                    solution += charset[i3];
                                    if (charset[i3] == charset[o2]){solution += '2';}
                                    else{solution += charset[o2];}
                                    if (charset[o2] == charset[l2]){solution += '2';}
                                    else{solution += charset[l2];}
                                    if (charset[l2] == charset[i2]){solution += '2';}
                                    else{solution += charset[i2];}
                                    if (charset[i2] == charset[o]){solution += '2';}
                                    else{solution += charset[o];}
                                    me = false;
                                    break;
                                }
                                else{
                                    l = 0;
                                    while (l < le){
                                        if (me == false){break;}
                                        possis[l](cube);
                                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                            solution += charset[i3];
                                            if (charset[i3] == charset[o2]){solution += '2';}
                                            else{solution += charset[o2];}
                                            if (charset[o2] == charset[l2]){solution += '2';}
                                            else{solution += charset[l2];}
                                            if (charset[l2] == charset[i2]){solution += '2';}
                                            else{solution += charset[i2];}
                                            if (charset[i2] == charset[o]){solution += '2';}
                                            else{solution += charset[o];}
                                            if (charset[o] == charset[l]){solution += '2';}
                                            else{solution += charset[l];}
                                            me = false;
                                            break;
                                        }
                                        else
                                        {
                                            i = 0;
                                            while (i < le){
                                                possis[i](cube);
                                                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                                    solution += charset[i3];
                                                    if (charset[i3] == charset[o2]){solution += '2';}
                                                    else{solution += charset[o2];}
                                                    if (charset[o2] == charset[l2]){solution += '2';}
                                                    else{solution += charset[l2];}
                                                    if (charset[l2] == charset[i2]){solution += '2';}
                                                    else{solution += charset[i2];}
                                                    if (charset[i2] == charset[o]){solution += '2';}
                                                    else{solution += charset[o];}
                                                    if (charset[o] == charset[l]){solution += '2';}
                                                    else{solution += charset[l];}
                                                    if (charset[l] == charset[i]){solution += '2';}
                                                    else{solution += charset[i];}
                                                    me = false;
                                                    break;}
                                                else
                                                {
                                                    antipossis[i](cube);
                                                    }
                                                i ++;
                                            }
                                            if (me == false){break;}
                                            antipossis[l](cube);
                                        }
                                        l ++;
                                    }
                                    if (me == false){break;}
                                    antipossis[o](cube);
                                    }
                                    o ++;
                                }
                                if (me == false){break;}
                                antipossis[i2](cube);
                            }
                            i2 ++;
                        }
                        if (me == false){break;}
                        antipossis[l2](cube);
                    }
                    l2 ++;
                }
                if (me == false){break;}
                antipossis[o2](cube);
            }
            o2 ++;
        }
        if (me == false){break;}
        antipossis[i3](cube);
        }
        i3 ++;
    }
/*------------------------------------------------------------------------------------------- 8 -----------------------------------------------------------------------------------*/
if (me == true){
    while (l3 < le){
    if (me == false){break;}
    possis[l3](cube);
    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
        solution += charset[l3];
        me = false;
        break;
    }
    else{
        i3 = 0;
        while (i3 < le){
            if (me == false){break;}
            possis[i3](cube);
            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                solution += charset[l3];
                if (charset[l3] == charset[i3]){solution += '2';}
                else{solution += charset[i3];}
                me = false;
                break;
            }
            else{
                o2 = 0;
                while (o2 < le){
                    if (me == false){break;}
                    possis[o2](cube);
                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                        solution += charset[l3];
                        if (charset[l3] == charset[i3]){solution += '2';}
                        else{solution += charset[i3];}
                        if (charset[i3] == charset[o2]){solution += '2';}
                        else{solution += charset[o2];}
                        me = false;
                        break;
                    }
                    else{
                        l2 = 0;
                        while (l2 < le){
                            if (me == false){break;}
                            possis[l2](cube);
                            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                solution += charset[l3];
                                if (charset[l3] == charset[i3]){solution += '2';}
                                else{solution += charset[i3];}
                                if (charset[i3] == charset[o2]){solution += '2';}
                                else{solution += charset[o2];}
                                if (charset[o2] == charset[l2]){solution += '2';}
                                else{solution += charset[l2];}
                                me = false;
                                break;
                            }
                            else{
                            i2 = 0;
                            while (i2 < le){
                                if (me == false){break;}
                                possis[i2](cube);
                                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                    and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                    solution += charset[l3];
                                    if (charset[l3] == charset[i3]){solution += '2';}
                                    else{solution += charset[i3];}
                                    if (charset[i3] == charset[o2]){solution += '2';}
                                    else{solution += charset[o2];}
                                    if (charset[o2] == charset[l2]){solution += '2';}
                                    else{solution += charset[l2];}
                                    if (charset[l2] == charset[i2]){solution += '2';}
                                    else{solution += charset[i2];}
                                    me = false;
                                    break;
                                }
                            else{
                                o = 0;
                                while (o < le){
                                    if (me == false){break;}
                                    possis[o](cube);
                                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                        and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                        solution += charset[l3];
                                        if (charset[l3] == charset[i3]){solution += '2';}
                                        else{solution += charset[i3];}
                                        if (charset[i3] == charset[o2]){solution += '2';}
                                        else{solution += charset[o2];}
                                        if (charset[o2] == charset[l2]){solution += '2';}
                                        else{solution += charset[l2];}
                                        if (charset[l2] == charset[i2]){solution += '2';}
                                        else{solution += charset[i2];}
                                        if (charset[i2] == charset[o]){solution += '2';}
                                        else{solution += charset[o];}
                                        me = false;
                                        break;
                                    }
                                    else{
                                        l = 0;
                                        while (l < le){
                                            if (me == false){break;}
                                            possis[l](cube);
                                            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                                and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                                solution += charset[l3];
                                                if (charset[l3] == charset[i3]){solution += '2';}
                                                else{solution += charset[i3];}
                                                if (charset[i3] == charset[o2]){solution += '2';}
                                                else{solution += charset[o2];}
                                                if (charset[o2] == charset[l2]){solution += '2';}
                                                else{solution += charset[l2];}
                                                if (charset[l2] == charset[i2]){solution += '2';}
                                                else{solution += charset[i2];}
                                                if (charset[i2] == charset[o]){solution += '2';}
                                                else{solution += charset[o];}
                                                if (charset[o] == charset[l]){solution += '2';}
                                                else{solution += charset[l];}
                                                me = false;
                                                break;
                                            }
                                            else
                                            {
                                                i = 0;
                                                while (i < le){
                                                    possis[i](cube);
                                                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6 and cube[16] == 2 and cube[25] == 3 and cube[34] == 4
                                                            and cube[4] == 1 and cube[13] == 2 and cube[22] == 3 and cube[31] == 4 and cube[40] == 5){
                                                        solution += charset[l3];
                                                        if (charset[l3] == charset[i3]){solution += '2';}
                                                        else{solution += charset[i3];}
                                                        if (charset[i3] == charset[o2]){solution += '2';}
                                                        else{solution += charset[o2];}
                                                        if (charset[o2] == charset[l2]){solution += '2';}
                                                        else{solution += charset[l2];}
                                                        if (charset[l2] == charset[i2]){solution += '2';}
                                                        else{solution += charset[i2];}
                                                        if (charset[i2] == charset[o]){solution += '2';}
                                                        else{solution += charset[o];}
                                                        if (charset[o] == charset[l]){solution += '2';}
                                                        else{solution += charset[l];}
                                                        if (charset[l] == charset[i]){solution += '2';}
                                                        else{solution += charset[i];}
                                                        me = false;
                                                        break;}
                                                    else
                                                    {
                                                        antipossis[i](cube);
                                                        }
                                                    i ++;
                                                }
                                                if (me == false){break;}
                                                antipossis[l](cube);
                                            }
                                            l ++;
                                        }
                                        if (me == false){break;}
                                        antipossis[o](cube);
                                        }
                                        o ++;
                                    }
                                    if (me == false){break;}
                                    antipossis[i2](cube);
                                }
                                i2 ++;
                            }
                            if (me == false){break;}
                            antipossis[l2](cube);
                        }
                        l2 ++;
                    }
                    if (me == false){break;}
                    antipossis[o2](cube);
                }
                o2 ++;
            }
            if (me == false){break;}
            antipossis[i3](cube);
            }
            i3 ++;
        }
    if (me == false){break;}
    antipossis[l3](cube);
    }
    l3 ++;
    }
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    }}}}}}}
    
    std::cout << "white cross : [ " << solution << " ]\n\n";

    }
}
/*------------------------------------------------------------------------------------------f2l------------------------------------------------------------------------------------*/
int f2l1(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    yprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l2(int cube[]){
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    yprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l3(int cube[]){
    rprime(cube);
    fprime(cube);
    rnormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    fnormal(cube);
    yprime(cube);
}

int f2l4(int cube[]){
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rnormal(cube);
    yprime(cube);
}

int f2l5(int cube[]){
    rnormal(cube);
    fnormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    fprime(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l6(int cube[]){
    yprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l7(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l8(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l9(int cube[]){
    rnormal(cube);
    unormal(cube);
    fnormal(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    fprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l10(int cube[]){
    yprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l11(int cube[]){
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l12(int cube[]){
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l13(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    yprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l14(int cube[]){
    yprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l15(int cube[]){
    yprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l16(int cube[]){
    yprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l17(int cube[]){
    fnormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    fprime(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l18(int cube[]){
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l19(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l20(int cube[]){
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l21(int cube[]){
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l22(int cube[]){
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l23(int cube[]){
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l24(int cube[]){
    yprime(cube);
    unormal(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l25(int cube[]){
    yprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l26(int cube[]){
    yprime(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l27(int cube[]){
    yprime(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
}

int f2l28(int cube[]){
    lnormal(cube);
    mnormal(cube);
    unormal(cube);
    rnormal(cube);
    mprime(cube);
    uprime(cube);
    rprime(cube);
    mnormal(cube);
    uprime(cube);
    lprime(cube);
    mprime(cube);
    yprime(cube);
}

int f2l29(int cube[]){
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l30(int cube []){
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l31(int cube[]){
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l32(int cube[]){
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
}

int f2l33(int cube[]){
    yprime(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    dprime(cube);
    eprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l34(int cube[]){
    yprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l35(int cube[]){
    yprime(cube);
    unormal(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l36(int cube[]){
    yprime(cube);
    unormal(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
}

int f2l37(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    yprime(cube);
    rprime(cube);
    uprime(cube);
    rnormal(cube);
}

int f2l38(int cube[]){
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l39(int cube[]){
    uprime(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    yprime(cube);
}

int f2l40(int cube[]){
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

int f2l41(int cube[]){
    uprime(cube);
    rnormal(cube);
    uprime(cube);
    rprime(cube);
    unormal(cube);
    rnormal(cube);
    unormal(cube);
    rprime(cube);
    yprime(cube);
}

std::string carry[41] = {"(RU\'R\'U) y\' (R\'U2RU\'U\') (R\'UR)", "(URU\'R\'U\') y\' (R\'UR)",                 "(R\'F\'RU) (RU\'R\'F) (y\')",        "(RUR\'U\') (RU2R\'U\') (RUR\') (y\')",
                         "(RF) U (RU\'R\'F\') (U\'R\') (y\')",    "y\' (R\'U\'RU) (R\'U\'R)",                  "(RU\'R\'U) (RU\'R\') (y\')",         "(RU\'R\'U) (RU\'U\'R\'U) (RU\'R\') (y\')",
                         "(RU) F (RUR\'U\') F\'R\' (y\')",        "y\' (R\'URU\') (R\'UR)",                    "(RUR\'U\') (RUR\') (y\')",           "(RUR\'U\')2 (RUR\') (y\')",
                         "(RU\'R\'U) y\' (R\'UR)",                "y\' (R\'U2) (RUR\'U\'R)",                   "y\'U\' (R\'U2) (RU\'R\'UR)",         "y\' (R\'URU\'U\') (R\'U\'R)",
                         "FU (RU\'R\'F\') (RU\'R\') (y\')",       "U (RU\'R\'U\') (RU\'R\'U) (RU\'R\') (y\')", "(RU\'R\'U2) (RUR\') (y\')",          "U (RU\'U\') (R\'URU\'R\') (y\')",
                         "(RU\'U\') (R\'U\'RUR\') (y\')",         "U\' (RU\'R\'U2) (RU\'R\') (y\')",           "U\' (RUR\') y\' (UR\'U\'R)",         "y\'U (R\'URU\') (R\'U\'R)",
                         "y\' (R\'U\'R)",                         "y\'U (R\'U\'RU\') (R\'U\'R)",               "y\' (RU\'U\') (R\'2U\') (R2U\'R\')", "(lU) (rU\'r\'U\') l\' (y\')",
                         "U\' (RU\'U\') (R\'U2) (RU\'R\') (y\')", "U\' (RUR\'U\') (RU\'U\'R\') (y\')",         "URU\'R\' (y\')",                     "U\' (RU\'U\'R\'U) (RUR\')"
                         "y\'U (R\'U\'R) d\' (RUR\') (y\')",      "y\'U\' (R\'UR)",                            "y\'U (R\'U\'RU\'U\') (R\'UR)",       "y\'U (R\'U2RU\'U\') (R\'UR)",
                         "(RU\'R\'U2) y\' (R\'U\'R)",             "(RU\'R\'U) (RU\'R\'U2) (RU\'R\') (y\')",    "U\' (RUR\'U) (RUR\') (y\')",         "(RUR\') (y\')",
                         "U\' (RU\'R\'U) (RUR\') (y\')"};

int cd = 6;
int cf;
int cr;
int cl;
int cb;

int tryf2l(int cube[], int solved){

    std::cout << "-----tryf2l-----\n";

    cf = cube[13];
    cr = cube[22];
    cl = cube[40];
    cb = cube[31];

    if (cube[14] == cr and cube[17] == cf and cube[47] == cd and cube[21] == cf and cube[24] == cr){
        f2l1(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 0;}
    else if (cube[10] == cf and cube[17] == cf and cube[47] == cd and cube[7] == cr and cube[24] == cr){
        f2l2(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 1;}
    else if (cube[5] == cf and cube[17] == cf and cube[47] == cd and cube[19] == cr and cube[24] == cr){
        f2l3(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 2;}
    else if (cube[14] == cf and cube[17] == cd and cube[47] == cr and cube[21] == cr and cube[24] == cf){
        f2l4(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 3;}
    else if (cube[14] == cr and cube[17] == cd and cube[47] == cr and cube[21] == cf and cube[24] == cf){
        f2l5(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 4;}
    else if (cube[7] == cr and cube[17] == cd and cube[47] == cr and cube[10] == cf and cube[24] == cf){
        f2l6(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 5;}
    else if (cube[5] == cf and cube[17] == cd and cube[47] == cr and cube[19] == cr and cube[24] == cf){
        f2l7(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 6;}
    else if (cube[14] == cf and cube[17] == cr and cube[47] == cf and cube[21] == cr and cube[24] == cd){
        f2l8(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 7;}
    else if (cube[14] == cr and cube[17] == cr and cube[47] == cf and cube[21] == cf and cube[24] == cd){
        f2l9(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 8;}
    else if (cube[10] == cf and cube[17] == cr and cube[47] == cf and cube[7] == cr and cube[24] == cd){
        f2l10(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 9;}
    else if (cube[5] == cf and cube[17] == cr and cube[47] == cf and cube[19] == cr and cube[24] == cd){
        f2l11(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 10;}
    else if (cube[8] == cd and cube[11] == cr and cube[14] == cf and cube[18] == cf and cube[21] == cr){
        f2l12(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 11;}
    else if (cube[8] == cd and cube[11] == cr and cube[14] == cr and cube[18] == cf and cube[21] == cf){
        f2l13(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 12;}
    else if (cube[8] == cd and cube[11] == cr and cube[10] == cf and cube[18] == cf and cube[7] == cr){
        f2l14(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 13;}
    else if (cube[8] == cd and cube[11] == cr and cube[37] == cf and cube[18] == cf and cube[3] == cr){
        f2l15(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 14;}
    else if (cube[8] == cd and cube[11] == cr and cube[28] == cf and cube[18] == cf and cube[1] == cr){
        f2l16(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 15;}
    else if (cube[8] == cd and cube[11] == cr and cube[19] == cf and cube[18] == cf and cube[5] == cr){
        f2l17(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 16;}
    else if (cube[8] == cd and cube[11] == cr and cube[7] == cf and cube[18] == cf and cube[10] == cr){
        f2l18(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 17;}
    else if (cube[8] == cd and cube[11] == cr and cube[3] == cf and cube[18] == cf and cube[37] == cr){
        f2l19(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 18;}
    else if (cube[8] == cd and cube[11] == cr and cube[1] == cf and cube[18] == cf and cube[28] == cr){
        f2l20(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 19;}
    else if (cube[8] == cd and cube[11] == cr and cube[5] == cf and cube[18] == cf and cube[19] == cr){
        f2l21(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 20;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[14] == cf and cube[21] == cr){
        f2l22(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 21;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[14] == cr and cube[21] == cf){
        f2l23(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 22;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[7] == cr and cube[10] == cf){
        f2l24(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 23;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[3] == cr and cube[37] == cf){
        f2l25(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 24;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[1] == cr and cube[28] == cf){
        f2l26(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 25;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[5] == cr and cube[19] == cf){
        f2l27(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 26;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[7] == cf and cube[10] == cr){
        f2l28(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 27;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[3] == cf and cube[37] == cr){
        f2l29(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 28;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[1] == cf and cube[28] == cr){
        f2l30(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 29;}
    else if (cube[8] == cf and cube[11] == cd and cube[18] == cr and cube[5] == cf and cube[19] == cr){
        f2l31(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 30;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[21] == cr and cube[14] == cf){
        f2l32(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 31;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[21] == cf and cube[14] == cr){
        f2l33(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 32;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[10] == cf and cube[7] == cr){
        f2l34(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 33;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[37] == cf and cube[3] == cr){
        f2l35(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 34;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[28] == cf and cube[1] == cr){
        f2l36(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 35;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[19] == cf and cube[5] == cr){
        f2l37(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 36;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[10] == cr and cube[7] == cf){
        f2l38(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 37;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[37] == cr and cube[3] == cf){
        f2l39(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 38;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[28] == cr and cube[1] == cf){
        f2l40(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 39;}
    else if (cube[8] == cr and cube[11] == cf and cube[18] == cd and cube[19] == cr and cube[5] == cf){
        f2l41(cube);
        std::cout << "\nF2L pair " << solved << " : [ ";
        solved ++; pri = 40;}
    else{
        check = false;
        pri = -1;
    }
    if (pri != -1){std::cout << carry[pri] << std::endl;}
    else{check = true;}
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int solve_f2l(int cube[]){

    moves hmm[9] = {unormal, utwo, uprime,
                  lnormal, ltwo, lprime,
                  bnormal, btwo, bprime};
    
    moves hmmanti[9] = {uprime, utwo, unormal,
                      lprime, ltwo, lnormal,
                      bprime, btwo, bnormal};

    std::string h[9] = {"U", "U2", "U\'"
                        "L", "L2", "L\'"
                        "B", "B2", "B\'"};

    std::string hanti[9] = {"U\'", "U2", "U"
                            "L\'", "L2", "L"
                            "B\'", "B2", "B"};

    int solved = 1;    

    cf = cube[13];
    cr = cube[22];
    cl = cube[40];
    cb = cube[31];

    if (cube[12] == cf and cube[13] == cf and cube[14] == cf and cube[15] == cf and cube[16] == cf and cube[17] == cf and
            cube[21] == cr and cube[22] == cr and cube[23] == cr and cube[24] == cr and cube[25] == cr and cube[26] == cr and 
            cube[39] == cl and cube[40] == cl and cube[41] == cl and cube[42] == cl and cube[43] == cl and cube[44] == cl and 
            cube[30] == cb and cube[31] == cb and cube[32] == cb and cube[33] == cb and cube[34] == cb and cube[35] == cb
            ){std::cout << "F2L : [ already solved ]\n"; solved = 5;}
        
    else if (cube[14] == cf and cube[17] == cf and cube[47] == cd and cube[21] == cr and cube[24] == cr){
        solved = 2;
        yprime(cube);
        cf = cube[13];
        cr = cube[22];
        cl = cube[40];
        cb = cube[31];

        if (cube[14] == cf and cube[17] == cf and cube[47] == cd and cube[21] == cr and cube[24] == cr){
            solved = 3;
            yprime(cube);
            cf = cube[13];
            cr = cube[22];
            cl = cube[40];
            cb = cube[31];
            
            if (cube[14] == cf and cube[17] == cf and cube[47] == cd and cube[21] == cr and cube[24] == cr){

                solved = 4;
                yprime(cube);

                std::cout << "\nF2L pair 1 : [ already solved ]\n";
                std::cout << "\nF2L pair 2 : [ already solved ]\n";
                std::cout << "\nF2L pair 3 : [ already solved ]\n";
                std::cout << "[ y ]\n";
            }
            else{
                ynormal(cube);
                std::cout << "\nF2L pair 1 : [ already solved ]\n";
                std::cout << "\nF2L pair 2 : [ already solved ]\n";
                std::cout << "[ y2 ]\n";
            }
        }
        else{
                std::cout << "\nF2L pair 1 : [ already solved ]\n";
                std::cout << "[ y\' ]\n";
            }
    }

    while (solved < 5){std::cout << "while solved < 5\n";

        tryf2l(cube, solved);
        oli = 0;
        if(check == false){while (check == false){
            hmm[oli](cube);
            tryf2l;
            if (check == true){
                std::cout << h[oli] << " ]" << carry[pri] << "[ " << hanti[oli] << " ]\n";
                hmmanti[oli](cube);
            }
            else{
                hmmanti[oli](cube);
                oli ++;
            }
        }
        }
            
            
            
            
            
        }
        





    


}

int start_solving(int cube[]){
    std::cout << "\nsolving...\n";
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    rotate_to_starting_position(cube);

    solve_white_cross(cube);

    solve_f2l(cube);
    std::cout << "\n";

    int x = 0;
            // for debugging
            while(x < 54)
            {
                std::cout << cube[x];
                
                if (x % 9 == 8 and x != 0)
                {
                    std::cout << std::endl;
                }
                x ++;
            }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "solved in " <<  (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) /1000000.0  << "s" << std::endl;
}

int main()
{

    startArt();
    
    while(true)
    {
        int cube[54] = {
                1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,
                3,3,3,3,3,3,3,3,3,
                4,4,4,4,4,4,4,4,4,
                5,5,5,5,5,5,5,5,5,
                6,6,6,6,6,6,6,6,6
                };
        
        std::cout << "Please make sure to hold your cube exactly how you scrambled it,\nstarting from yellow at the top and blue at the front!" << std::endl;
        std::cout << "Scramble it and enter the Scramble you want to solve (for sytax rules type help)"<< std::endl;
        std::cout << ":";
        std::string a;
        std::cin >> a;
        std::cout << std::endl;

        char instructions[100] = {};
        
        if (a == "help")
        {
            help();   
        }
        else
        {
            checkSyntax(a, instructions);
            if (oli != 1){
            
                int i = 0;
                while(true){
                    if (instructions[i] == 'U')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    uprime(cube);
                                    i ++;
                                }
                                uprime(cube);
                                i ++;
                            }
                            else
                            {
                                unormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'R')
                    {   
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    rprime(cube);
                                    i ++;
                                }
                                rprime(cube);
                                i ++;
                            }
                            else
                            {
                                rnormal(cube);
                            }
                            co ++;
                        }
                                        
                    }
                    else if (instructions[i] == 'L')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    lprime(cube);
                                    i ++;
                                }
                                lprime(cube);
                                i ++;
                            }
                            else
                            {
                                lnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'F')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    fprime(cube);
                                    i ++;
                                }
                                fprime(cube);
                                i ++;
                            }
                            else
                            {
                                fnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'D')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    dprime(cube);
                                    i ++;
                                }
                                dprime(cube);
                                i ++;
                            }
                            else
                            {
                                dnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'B')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    bprime(cube);
                                    i ++;
                                }
                                bprime(cube);
                                i ++;
                            }
                            else
                            {
                                bnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'M')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    mprime(cube);
                                    i ++;
                                }
                                mprime(cube);
                                i ++;
                            }
                            else
                            {
                                mnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'E')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    eprime(cube);
                                    i ++;
                                }
                                eprime(cube);
                                i ++;
                            }
                            else
                            {
                                enormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'S')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    sprime(cube);
                                    i ++;
                                }
                                sprime(cube);
                                i ++;
                            }
                            else
                            {
                                snormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'u')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    uprime(cube);
                                    enormal(cube);
                                    i ++;
                                }
                                uprime(cube);
                                enormal(cube);
                                i ++;
                            }
                            else
                            {
                                unormal(cube);
                                eprime(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'r')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    rprime(cube);
                                    mnormal(cube);
                                    i ++;
                                }
                                rprime(cube);
                                mnormal(cube);
                                i ++;
                            }
                            else
                            {
                                rnormal(cube);
                                mprime(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'f')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    fprime(cube);
                                    sprime(cube);
                                    i ++;
                                }
                                fprime(cube);
                                sprime(cube);
                                i ++;
                            }
                            else
                            {
                                fnormal(cube);
                                snormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'l')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    lprime(cube);
                                    mprime(cube);
                                    i ++;
                                }
                                lprime(cube);
                                mprime(cube);
                                i ++;
                            }
                            else
                            {
                                lnormal(cube);
                                mnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'd')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    dprime(cube);
                                    eprime(cube);
                                    i ++;
                                }
                                dprime(cube);
                                eprime(cube);
                                i ++;
                            }
                            else
                            {
                                dnormal(cube);
                                enormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'b')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    bprime(cube);
                                    snormal(cube);
                                    i ++;
                                }
                                bprime(cube);
                                snormal(cube);
                                i ++;
                            }
                            else
                            {
                                bnormal(cube);
                                sprime(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'x')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    xprime(cube);
                                    i ++;
                                }
                                xprime(cube);
                                i ++;
                            }
                            else
                            {
                                xnormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'y')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    yprime(cube);
                                    i ++;
                                }
                                yprime(cube);
                                i ++;
                            }
                            else
                            {
                                ynormal(cube);
                            }
                            co ++;
                        }
                    }
                    else if (instructions[i] == 'z')
                    {
                        int co;
                        if (instructions[i+1] == '2'){
                            co = 0;
                            i ++;}
                        else{
                            co = 1;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    zprime(cube);
                                    i ++;
                                }
                                zprime(cube);
                                i ++;
                            }
                            else
                            {
                                znormal(cube);
                            }
                            co ++;
                        }
                    }
                    else{break;}
                    i ++;
                }
            int x = 0;
            // for debugging
            while(x < 54)
            {
                std::cout << cube[x];
                
                if (x % 9 == 8 and x != 0)
                {
                    std::cout << std::endl;
                }
                x ++;
            }
            
            int p = 0;
            std::cout << "cube scrambled !\n"
                      << "solve [ ";
                      
                      while(p <= i){
                        
                        std::cout << instructions[p];
                        p ++;
                      }
            std::cout << " ] ? (y / n)\n";
            while (true){
                std::string v;
                std::cin >> v;
                if (v == "no" or v == "n"){
                    break;
                }
                else if (v == "yes" or v == "y"){
                    start_solving(cube);
                    break;
                }
                else{
                    std::cout << "Please enter a valid option (yes or no)\n";
                }
            }
            
            std::cout << std::endl;
        }
        oli = 0;
        }
    }
    



    return(0);
}