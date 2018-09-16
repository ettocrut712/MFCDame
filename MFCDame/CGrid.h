#pragma once

#include <vector>
#include <array>



class CGrid
{
public:
	CGrid();
	~CGrid();

	

	struct pion
	{
		long int ID;							// ID du pion
		int x;									// coordonnees X
		int y;									// coordonnees Y
		bool dame;  							// si le pion devient une dame, alors dame = TRUE;
		int score;								// score calculé pour ce pion (évaluation minimax)
		int move;								// correspond au mouvement associé au score (directions (x,y) -> 0= +/+ , 1 = -/+, 2 = +/-, 3 = -/-) 

	};

	struct pion_move
	{
		int ID;
		int score;
		int move;

	};

	int niveau;

	void RetirePion(int pionID);
	void TransferTousPionToGrid();
	void CloneGrid();
	void ResetMainGrid();
	pion_move TrouveBestPionOrdi();
	void CalculScoreInitial();
	void CalculScoreGrid();
	pion_move TrouveBestPionHumain();
	void ResetScorePions();
	int SetPionScore(int pionID, int score, int move);
	void ResetSubGrid();
	void CreatePionsOrdi();
	void CreatePionHumain();

private:

	int score_ordi_initial, score_humain_initial;
	int score_ordi_grid, score_humain_grid;



	int grid_main[10][10];						//grid principal avant changement 
	int grid_sub[10][10];						//grid secondaire après changement.  Transféré au niveau suivant pour suite des calculs (recursion).

	
	int max_niveau = 2;
	int max_grid_size = 10;						// grille de 10 par 10 max (selon le web, c'est le grid pour un jeu de dame)

	int delta_x = 1;							// deplacement permis en x (+/-)
	int delta_y = 1;							// deplacement permis en y (+/-)
	std::vector <pion> pion_vector_ordi;
	std::vector <pion> pion_vector_humain;



};


	
	
