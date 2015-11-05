#include "HighscoreManager.h"

/*
	Load the highscore from the file
*/
int HighscoreManager::LoadHighscore(){
	FILE* hs = NULL;

	fopen_s(&hs, "hs.txt", "r");
	int highscore;
	if (hs != NULL)
		fscanf_s(hs, "%d", &highscore);

	fclose(hs);

	return highscore;
}

void HighscoreManager::SaveHighscore(int score){
	FILE* hs = NULL;

	fopen_s(&hs, "hs.txt", "w");
	if (hs != NULL)
		fprintf_s(hs, "%d", score);
	
	fclose(hs);
}