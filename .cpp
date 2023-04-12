/*
	The game of Pig is a simple two player dice game in which the first player to reach 100 or more points wins. 
	Players take turns. On each turn a player rolls a six-sided die:  
	• If the player rolls a 2–6 then he or she can either   
		— ROLL AGAIN or   
		— HOLD. At this point the sum of all rolls made this turn is added to the player’s total score and it becomes the other player’s turn.  
	•  If the player rolls a 1 then the player loses his or her turn. 
	The player gets no new points and it becomes the opponent’s turn.  
	If a player reaches 100 or more points after holding then the player wins.  
	
	Write a program that plays the game of Pig, where one player is a human and the other is the computer. 
	Allow the human to input “r” to roll again or “h” to hold.  
	
	The computer program should play according to the following rule: keep rolling on the computer’s turn until it has accumulated 20 or more points, then hold.
	Of course, if the computer wins or rolls a 1 then the turn ends immediately. 
	Allow the human to roll first.  
	
	Write your program using at least two functions:  
		int humanTurn(int humanTotalScore);  
		int computerTurn(int computerTotalScore);
	These functions should perform the necessary logic to handle a single turn for either the computer or the human. 
	The input parameter is the total score for the human or computer. 
	The functions should return the turn total to be added to the total score upon completion of the turn. 
	
	For example, if the human rolls a 3 and 6 and then holds, then humanTurn should return 9. However, if the human rolls a 3 and 6 and then a 1, then the function should return 0.		
*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#define win 200
using namespace std;

int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main() {
	srand(time(NULL));
	
	int hScore=0, cScore=0;
	int turn=0; //1 for human. 0 for computer 
	
	do {
		turn++;
		
		if(turn%2 == 1){
			cout << "Your turn:" << endl;
			hScore += humanTurn(hScore);
		}
		else {
			cout << "Player's turn: " << endl;
			cScore += computerTurn(cScore);
		}	
			
		cout << "# You: " << hScore << endl
			<< "# Player: " << cScore << endl << endl;
			
	} while(hScore<win && cScore<win);
	
	if(hScore>cScore){
		cout << "You win!" << endl;
	}
	else {
		cout << "You lose" << endl;
	}	
	
	return 0;
}

int humanTurn(int humanTotalScore) {
	int score=0, temp;
	char repeat;
	
	do {
		temp = rand()%6+1;
		if(temp==1) {
			cout << "You rolls a 1, set score back to 0." << endl;
			return 0;
		}
		
		score += temp;
		cout << "You rolls a " << temp << ", current score: " << score << ".";
		
		if(score+humanTotalScore >= win) {
			cout << endl;
			return score;
		}
		
		cout << "	repeat(r) / hold(h) : ";
		cin >> repeat;
		
	} while(repeat == 'r');	
	
	return score;
}

int computerTurn(int computerTotalScore) {
	int score=0, temp, stopPoint=20;
	if(win-computerTotalScore < stopPoint) {
		stopPoint = win-computerTotalScore;
	}
	
	do {
	
		temp = rand()%6+1;
		if(temp==1) {
			cout << "Player rolls a 1, set score back to 0." << endl;
			return 0;
		}
		
		score += temp;
		cout << "Player rolls a " << temp << ", current score: " << score << "." << endl;
		
	} while(score < stopPoint);	
	
	return score;
}
