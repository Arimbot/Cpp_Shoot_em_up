#include "HighscoreManager.h"

/*
	Load the highscore from the file
*/
int HighscoreManager::LoadHighscore(){
	FILE* hs = NULL;

	fopen_s(&hs, "data2", "r");
	int highscore = 0;

	if (hs != NULL){
		fscanf_s(hs, "%d", &highscore);
		fclose(hs);
	}

	return highscore;
}

/*
	Save the highscore in the file
*/
void HighscoreManager::SaveHighscore(int score){
	FILE* hs = NULL;

	fopen_s(&hs, "data2", "w");

	if (hs != NULL){
		fprintf_s(hs, "%d", score);
		fclose(hs);
	}
}