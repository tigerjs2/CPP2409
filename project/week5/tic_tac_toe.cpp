#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell] = {};
    int x, y; // User Input x, y
    int count = 0; // Checking Process
    int winnerAppear = 0; // When Winner Appear, flag is 1
    // Board Initialize
    for(x = 0; x < numCell; x++){
        for(y = 0; y < numCell; y++)
            board[y][x] = ' ';
    }

    // Game Code
    int k = 0; // Check who's Turn
    char currentUser = 'X'; // currentUser's Marker
    while(true){
        // 1. Who's Turn
        switch(k % 2){
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        // 2. Get Position
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. Check Validity
        if(x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다.\n";
            continue; 
        }
        if(board[y][x] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다.\n";
            continue;
        }

        // 4. Set Marker on Position
        board[y][x] = currentUser;
        count++; // Increase when Turn ends

        // 5. Print Board
        for(int i = 0; i < numCell; i++){
            cout << "---|---|---\n";
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1) break;
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---\n";
        k++;

        // 6-1. Winner (Winner can appear at least count reach 5)
        if(count >= 5){
            // For every case check Vertical and Horizontal Lines
            
            // Check Vertical Line
            int lineCheck[numCell] = {0, };
            for(int i = 0; i < numCell; i++){
                if(board[i][x] == currentUser)
                    lineCheck[i] = 1;
            }
            if ((lineCheck[0] == lineCheck[1]) && (lineCheck[0] == lineCheck[2]) && lineCheck[0]){
                winnerAppear = 1;
                break;
            }
            // Check Horizontal Line
            for(int i = 0; i < numCell; i++) lineCheck[i] = 0; // lineChecker initaltize

            for(int i = 0; i < numCell; i++){
                if(board[y][i] == currentUser)
                    lineCheck[i] = 1;
            }
            if ((lineCheck[0] == lineCheck[1]) && (lineCheck[0] == lineCheck[2]) && lineCheck[0]){
                winnerAppear = 1;
                break;
            }

            // When mark is on Top to Bottom Tilted Line
            if(x == y){
                for(int i = 0; i < numCell; i++) lineCheck[i] = 0; // lineChecker initaltize

                for(int i = 0; i < numCell; i++){
                    if(board[i][i] == currentUser)
                        lineCheck[i] = 1;
                }
                if ((lineCheck[0] == lineCheck[1]) && (lineCheck[0] == lineCheck[2]) && lineCheck[0]){
                    winnerAppear = 1;
                    break;
                }
            }

            // When mark is on Bottom to Top Tilted Line
            if((x + y) == 2){
                for(int i = 0; i < numCell; i++) lineCheck[i] = 0; // lineChecker initaltize

                for(int i = 0; i < numCell; i++){
                    if(board[2 - i][i] == currentUser)
                        lineCheck[i] = 1;
                }
                if ((lineCheck[0] == lineCheck[1]) && (lineCheck[0] == lineCheck[2]) && lineCheck[0]){
                    winnerAppear = 1;
                    break;
                }
            }
        }
        // 6-2. No Winner and Every Board is Occupied
        if(count == 9){
            cout << "Nobody Won, Game Ends\n";
            break;
        }
    }
    // If Winner Exist or Not
    if(winnerAppear == 1) 
        cout << "유저(" << currentUser << ")가 이겼습니다!.\n";

    return 0;
}