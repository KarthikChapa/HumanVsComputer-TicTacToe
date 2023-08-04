#include <bits/stdc++.h>
using namespace std;
#define COMPUTER 1
#define HUMAN 2

void showboard(char board[][3]){
    cout << "\t\t\t "<< board[0][0] <<" | " <<board[0][1] << " | " << board[0][2] << endl ;
    cout << "\t\t\t "<< board[1][0] <<" | " <<board[1][1] << " | " << board[1][2] << endl ;
    cout << "\t\t\t "<< board[2][0] <<" | " <<board[2][1] << " | " << board[2][2] << endl ; 
}
void showinstructions (){
    cout << "\t\t\t"<< " 1 | 2 | 3 "<< endl;
    cout << "\t\t\t"<< " 4 | 5 | 6 "<< endl;
    cout << "\t\t\t"<< " 6 | 8 | 9 "<< endl;

}

void declarewinner (int whoseturn){
    if (whoseturn == (COMPUTER)){
        cout << "YOU LOST" << endl;
    }
    else 
        cout << "YOU WON" << endl;
}
bool checkrow(char board[][3]){
    for (int i=0;i<3;i++){
       
            if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]  && board[i][0] != '*')
                return true;
        
    }
    return false;
}

bool checkcollumn(char board[][3]){
    for (int i=0;i<3;i++){
       
            if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]  && board[0][i] != '*')
                return true;
        
    }
    return false;
}
bool diagnol(char board[][3]){
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]  && board[0][0] != '*')
        return true;
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]  && board[0][2] != '*')
        return true;
    return false;

}

bool gameover(char board[][3]){
    return (checkrow(board)||checkcollumn(board)||diagnol(board));
    
}
int minimax(char board[][3],int depth, bool isAI){
    int score =0;
    int bestscore=0;
    if (gameover(board)==true){
        if(isAI==true)
            return -10;
        if(isAI==false)
            return 10;
    }
    else{
        if(depth<9){
            if(isAI==true){
                bestscore=-99;
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                         if( board[i][j]=='*'){
                            board[i][j]='O';
                            score=minimax(board,depth+1,false);
                            board[i][j]='*';
                            if (score>bestscore){
                                bestscore=score;
                                
                            }
                        }
                    }
                }
                return bestscore;

            }
            else {
                bestscore=999;
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                         if( board[i][j]=='*'){
                            board[i][j]='X';
                            score=minimax(board,depth+1,true);
                            board[i][j]='*';
                            if (score<bestscore){
                                bestscore=score;
                                
                            }
                        }
                    }
                }
                return bestscore;
            }

        }
        else 
            return 0;

    }
}


int bestmove(char board[][3],int index){
    int x=-1;
    int y=-1;
    int score =0;
    int bestscore=-99;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
           if( board[i][j]=='*'){
            board[i][j]='O';
            score=minimax(board,index+1,false);
            board[i][j]='*';
            if (score>bestscore){
                bestscore=score;
                x=i;
                y=j;
            }
           }
        }
    }
    return x*3 + y;
}

void play(int whoseturn){
    char board[3][3];
    int index=0;
    int x=0;
    int y=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            board[i][j]='*';
        }
    }
    showinstructions();
    while(gameover(board)==false&& index!= 9){
        int n;
        if(whoseturn==COMPUTER){
            n=bestmove(board,index);
            x=n/3;
            y=n%3;
            board[x][y]='O';
            showboard(board);
            index++;
            whoseturn=HUMAN;
        }
        else if(whoseturn== HUMAN)
        {
            cout<< "\t\t\t please enter a valid position : ";
            cin >> n;
            n--;
            x=n/3;
            y=n%3;
            if(board[x][y]=='*' && n<9 && n>0){
                board[x][y]='X';
                showboard(board);
                index++;
                whoseturn=COMPUTER;
            }
            else if (board[x][y]!='*' && n<9 && n>0)
                cout<< "This position is already occupied"<< endl;
            else  
                cout<< "invalid position" << endl;
        }
        

    }
    if(gameover(board)==false&& index==9){
            cout<< "Match Tie"<< endl;
        }
    else{
        if(whoseturn==COMPUTER)
            whoseturn= HUMAN;
        if(whoseturn==HUMAN)
            whoseturn= COMPUTER;
        declarewinner(whoseturn);
    }
}



int main(){
    cout<< "\t\t\t TIC-TAC-TOE"<< endl;
    cout<< "\n";
    
        
            char choice;
            cout << "\t Do you want to start ? (y/n) : ";
            cin >> choice;
            if(choice=='n'){
                
                play(1);
            }
            else if(choice=='y'){
                
                play(2);
            }
            else {
                cout<< "invaid choice";
            }
            
        
    return 0;
}


