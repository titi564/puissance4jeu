//*************************************************************************** //
//  PROGRAMME : modele.ccp (mettre � jour ce cartouche)
//  DATE      :
//  OBJET     :
//  AUTEUR(S) :
//***************************************************************************

// ===================== Liste des fichiers d'en-t�te ======================= //
#include <iostream>			// flux d'entr�es/sorties
#include <iomanip>			// manipulateurs de flux
#include <cstdlib>		    // biblioth�que c standard
#define _USE_MATH_DEFINES	// biblioth�que math�matique
#include <cmath>
#include <clocale>			// caract�res accentu�s


using namespace std;		// permet d'abr�ger les appels aux flux std::cin et std::cout

// =============================== Constantes =============================== //
/* d�clarez ici les constantes */
const int LIG_MAX = 6;
const int COL_MAX = 7;
// ================================== Types ================================= //
/* d�clarez ici les nouveaux types */
typedef int t_tableau[LIG_MAX][COL_MAX];
// ============================ Sous programmes ============================= //
/* d�clarez ici les sous-programmes */
void initialiserTableau (t_tableau &Grille, int l, int c)  // Ce sous programme permet d'initialiser la grille de jeu
    {
        int i,j;
        for (i = 0; i< l; i++)
        {
            for(j=0; j<c ; j++)
                Grille[i][j]= 0;
        }
    }
void afficherTableau (t_tableau grille, int l, int c) // Ce programme permet d'afficher la grille de jeu
{
    int i,j;
    for(i=0; i<l; i++)
    {
        for (j=0; j<c; j++)
        {
            cout<<grille[i][j]<<" | ";
        }
        cout<<endl;
    }
}
bool detectHorizontal(t_tableau grille) // Ce sous programme detecte si 4 jetons sont align�s horizontalement
{

    int i,j;
    for(i=0;i<LIG_MAX; i++)
    {
        for(j=0; j<COL_MAX-3; j++)
        {
            if (grille[i][j] == 1 && grille[i][j+1]== 1 && grille[i][j+2]== 1 && grille[i][j+3]==1)
                return true;
        }
    }
    return false;
}
bool detectVertical(t_tableau grille) // Ce sous programme detecte si 4 jetons sont align�s verticalement
{
    int i, j;

    for(i=0;i<LIG_MAX-3; i++)
    {
        for(j=0; j<COL_MAX; j++)
        {
            if (grille[i][j]==1 && grille[i+1][j]==1 && grille[i+2][j] ==1 && grille[i+3][j]==1)
                return true;
        }
    }
    return false;
}
bool detectDiagonal(t_tableau grille)  // Ce sous programme detecte si 4 jetons sont align�s en diagonale
{

    int i,j;
    for(i=0;i<LIG_MAX-3; i++)
    {
        for(j=0; j<COL_MAX-3; j++)
        {
            if (((grille[i][j]==1) && (grille[i+1][j+1]==1) && (grille[i+2][j+2] ==1) && (grille[i+3][j+3]==1))
                ||((grille[i][j]==1) && (grille[i+1][j-1]==1) && (grille[i+2][j-2] ==1) && (grille[i+3][j-3]==1) ))
                return true;
        }
    }
    return false;
}

bool grilleRemplie(t_tableau grille) // Ce sous programme retourne vrai si la grille de jeu est remplie
{
    int j;
        for(j=0; j<COL_MAX;j++)
        {
            if ( grille[0][j]==0)
                {
                    return false;
                }

        }
        return true;
    }

void choixColonne(int &x) // Ce sous programme demande a l'utilisateur un num�ro de colonne pour le jeton
{
    do
    {
        cout<<" Choisissez un nombre de colonne entre 0 et 6 pour placer le jeton"<<endl;
        cin>>x;
    }
    while ( x< 0 || x>6);
}

bool PlacerPion (t_tableau grille, int colonne) // ce sous programme place le pion dans la colonne et renvoie vrai si il a plac� le pion et faux si la                 colonne �tait d�ja remplie
{
    int i = LIG_MAX-1;
    while( grille[i][colonne] == 1 && i>=0)
    {
        i--;
    }
    if (i>=0)
    {
        grille[i][colonne] = 1;
        return true;
    }
    else
    {
        cout<< " Cette colonne est deja pleine"<<endl;
        return false;
    }
}

// ========================== Programme principal =========================== //
int main(void)
{

   // D�clarations locales
    t_tableau grille_jeu={{0,1,0,0,0,0,0},
                          {0,1,0,0,0,0,0},
                          {0,1,0,0,0,0,0},
                          {0,1,0,0,0,0,0},
                          {0,1,0,0,0,0,0},
                          {0,1,1,0,1,0,0}};
  //  bool detectH;
   // bool detectV;
  //  bool detectD;
  //  bool colR;
  //  int colonneChoisie;
  //  bool grilleR;
int col;
   // Actions
   setlocale(LC_ALL, "french");
    //initialiserTableau(grille_jeu,LIG_MAX,COL_MAX);
    afficherTableau(grille_jeu,LIG_MAX,COL_MAX);
    choixColonne(col);
    PlacerPion(grille_jeu,col);
    afficherTableau(grille_jeu,LIG_MAX,COL_MAX);



   // retour au syst�me d'exploitation
   return 0;
}
// ============================ Fin du programme ============================ //
