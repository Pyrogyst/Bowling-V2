	// Nicholas Jessop, ITCS 2530
	// BowlingScores.txt in same directory as .sln
	// File.open for txt
	// Tutorialspoint.com for help

	#include <iostream>
	#include <iomanip>
	#include <string>
	#include <fstream>
	using namespace std;

	// Named Constants
	int playerCount = 0;
	float average = 0;
	int product = 0;
	int score = 0;
	int i = 0;
	string Bowlername;
	string BowlerScores;
	string Bowling;
	
//--------------------------------------------------------------------------- REQUIRED FUNCTIONS ---------------------------------------------------------------------------------

		// GetBowlingData (read and store data into two arrays) 
		bool GetBowlingData (string BowlerScores, string Bowling[100], int score[5][100]) {

			fstream file;
			file.open ("BowlingScores.txt", ios::in);

			//STATUS CHECK
			if (file.fail())
				return false;
			
			while (!file.eof()) {
				file >> Bowling [playerCount];

				if (Bowling [playerCount] == "")
					break;

				for (int i = 0; i < 5; i++) {
					file >> score[i][playerCount];
				}
				playerCount++;
			}
		}


		// GetAverageScore (Calculation)
		float * GetAverageScore (int score [5] [100]) {
			static float average[100];

			for (int i = 0; i < playerCount; i++) {
				int product = 0;

				for (int j = 0; j < 5; j++) {
					product += score[j][i];
				}

				//Math
				average [i] = product / 5;
			}
			return average;
		}

		// PrettyPrintResults (Bowler Name, Scores and Average PRINT)
		void PrettyPrintResults (string Bowlername[], int score[][100], float average[]) {

			//NOTE: This is the only way i found to space it nicely. Any better ideas? Adding a space just makes it even more off-centered.
			cout << "Name\t\t" << "Score1\t\tScore2\t\tScore3\t\tScore4\t\tScore5\t\tAverage" << endl;

			for (int i = 0; i < playerCount; i++) {

				// Printing of the scores + Spacing Declaration (Found this method on Tutorialspoint.com) is that an issue? let me know! 
				// Length() seems to work here too, not only Java like I thought
				if (Bowlername [i].length() > 8) // Only applies to Mike (last row)
					cout << Bowlername [i] << "\t" << score [0] [i] << "\t\t" << score [1] [i] << "\t\t" << score [2] [i] << "\t\t" << score [3] [i] << "\t\t" << score[4][i] << average [i] << endl;

				else //Applies to rest of Bowlers
					cout << Bowlername [i] << "\t\t" << score [0] [i] << "\t\t" << score [1] [i] << "\t\t" << score [2] [i] << "\t\t" << score [3] [i] << "\t\t" << score[4][i] << average [i] << endl;
				 
				//Causes hard-coded alignment ^^^
			}
		}
		//------------------------------------------------------------------------------- END REQUIRED FUNCTIONS ------------------------------------------------------------------------

	
	
	
	//Delcared all before, now just need to call it all.
	
	// MAIN START
	
	int main()

	{
		// Named Constants
		string Bowlername [100];
		int Bowlerscore [5] [100];
		float * average;


		// GetBowlingData (read and store data into two arrays)
		GetBowlingData ("BowlingScores.txt", Bowlername, Bowlerscore);

		// GetAverageScore (Calculation)
		average = GetAverageScore(Bowlerscore);

		// PrettyPrintResults (Bowler Name, Scores and Average PRINT)
		PrettyPrintResults (Bowlername, Bowlerscore, average);

		return 0;
	}
