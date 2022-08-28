#include <iostream>
#include <string>

int oli = 0;
bool me = true;

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

    cube[37] = buffer1;
    cube[40] = buffer2;
    cube[43] = buffer3;
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
            std::cout << "bring the white site to the bottom\n[ x2 ]\n\n";
        }
        else if (cube[13] == 6){
            xprime(cube);
            std::cout << "bring the white site to the bottom\n[ x' ]\n\n";
        }
        else if (cube[22] == 6){
            znormal(cube);
            std::cout << "bring the white site to the bottom\n[ z ]\n\n";
        }
        else if (cube[31] == 6){
            xnormal(cube);
            std::cout << "bring the white site to the bottom\n[ x ]\n\n";
        }
        else{
            zprime(cube);
            std::cout << "bring the white site to the bottom\n[ z' ]\n\n";
        }
    }
    else{std::cout << "white side is already at the bottom\n\n";}
}

int solve_white_cross(int cube[]){

    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){std::cout << "white cross is already solved\n";}
    else{

    moves possis[] = {rprime, rnormal,
                     fprime, fnormal,
                     lprime, lnormal,
                     bprime, bnormal,
                     uprime, unormal,
                     dprime, dnormal,
                     };

    int le = 12;

    int o = 0;
    int l = 0;
    int i = 0;
    int o2 = 0;
    int l2 = 0;
    int i2 = 0;
    int o3 = 0;
    int l3 = 0;
    int i3 = 0;

    me = true;

    std::string charset[12] = {"R'", "R",
                               "F'", "F",
                               "L'", "L",
                               "B'", "B",
                               "U'", "U",
                               "D'", "D"};

    std::string solution;
    solution = "";
    std::cout << solution;

    while (i < le){
        possis[i](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
            solution += charset[i];
            me = false;
            break;}
        else
        {
            possis[i](cube);
            possis[i](cube);
            possis[i](cube);
            }
        i ++;
    }

    if (me == true){
    while (l < le){
        if (me == false){break;}
        possis[l](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
            solution += charset[l];
            me = false;
            break;
        }
        else
        {
            i = 0;
            while (i < le){
                possis[i](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
                    solution += charset[l];
                    if (charset[l] == charset[i]){solution += '2';}
                    else{solution += charset[i];}
                    me = false;
                    break;}
                else
                {
                    possis[i](cube);
                    possis[i](cube);
                    possis[i](cube);
                    }
                i ++;
            }
            if (me == false){break;}
            possis[l](cube);
            possis[l](cube);
            possis[l](cube);
        }
        l ++;
    }

    if (me == true){
    while (o < le){
        if (me == false){break;}
        possis[o](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
            solution += charset[o];
            me = false;
            break;
        }
        else{
            l = 0;
            while (l < le){
                if (me == false){break;}
                possis[l](cube);
                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
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
                        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
                            solution += charset[o];
                            if (charset[o] == charset[l]){solution += '2';}
                            else{solution += charset[l];}
                            if (charset[l] == charset[i]){solution += '2';}
                            else{solution += charset[i];}
                            me = false;
                            break;}
                        else
                        {
                            possis[i](cube);
                            possis[i](cube);
                            possis[i](cube);
                            }
                        i ++;
                    }
                    if (me == false){break;}
                    possis[l](cube);
                    possis[l](cube);
                    possis[l](cube);
                }
                l ++;
            }
            if (me == false){break;}
                possis[o](cube);
                possis[o](cube);
                possis[o](cube);
            }
            o ++;
        }

    if (me == true){
    while (i2 < le){
        if (me == false){break;}
        possis[i2](cube);
        if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
            solution += charset[i2];
            me = false;
            break;
        }
    else{
        o = 0;
        while (o < le){
            if (me == false){break;}
            possis[o](cube);
            if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
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
                    if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
                        solution += charset[i2];
                        if (charset[i2] == charset[o]){solution += '2';}
                        else{solution += charset[o];}
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
                                if (cube[52] == 6 and cube[50] == 6 and cube[48] == 6 and cube[46] == 6){
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
                                possis[i](cube);
                                possis[i](cube);
                                possis[i](cube);
                                }
                            i ++;
                        }
                        if (me == false){break;}
                        possis[l](cube);
                        possis[l](cube);
                        possis[l](cube);
                    }
                    l ++;
                }
                if (me == false){break;}
                    possis[o](cube);
                    possis[o](cube);
                    possis[o](cube);
                }
                o ++;
            }
            if (me == false){break;}
            possis[i2](cube);
            possis[i2](cube);
            possis[i2](cube);
        }
        i2 ++;

    }}}}
    
    std::cout << "solve the white cross now\n[ " << solution << " ]\n";

    }
}

int start_solving(int cube[]){

    rotate_to_starting_position(cube);

    solve_white_cross(cube);

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

    std::cout << "\nsolved";
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                            co = 0;}
                        else{
                            co = 1;
                            i ++;}
                        while (co < 2){
                            if (instructions[i+1] == '\'')
                            {
                                if(instructions[i+2] == '2'){
                                    sprime(cube);
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                                    i += 2;
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
                    else
                    {break;}
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