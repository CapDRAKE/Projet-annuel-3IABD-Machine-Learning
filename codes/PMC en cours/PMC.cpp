#include <iostream>
#include "Eigen"
#include <time.h>
using namespace Eigen;

//struct Model{
//    VectorXf W;
//    VectorXf X;
//
//};
//
//Model *create_model( int size, int tab[]){
//    auto *model = new Model();
//
//    model->X.resize(size);
//    model->W.resize(size);
//
//
//}



VectorXf predict (VectorXf entree,  int nbcouche, VectorXf NbP, bool isclassification){

    VectorXf entree_deux(entree.size()+1 ); // on crée un vecteur taille + 1 pour mettre le biais

    entree_deux[0] = 1; //valeur pour le biais

    for (int a = 0; a < entree.size(); a++){
        entree_deux[a+1] = entree[a];// on donne les valeurs des premiers valeurs d'entrees

    }

    int change = 0;

    for (int  couche = 1; couche < nbcouche; couche++){

        int e =  NbP[couche-1]; // e prend le nombre de percepetron dans la couche

        VectorXf save( e); // on prend save pour garder les resulats de sorti de la couche


        for (int  neuronne = 0; neuronne < NbP[couche -1]; neuronne++){

            srand(time(NULL));
            VectorXf poids(entree_deux.size()); // créer le vecteur des poids pris en random entre -1 et 1
            poids.setRandom();
            std::cout << poids  << std::endl;
            int total = 0;
            total = tanh(poids.transpose() *   entree_deux);
            std::cout << total << std::endl;
            std::cout << entree_deux << std::endl;

            save[neuronne] = total;

        }
        std::cout << save << std::endl;
        if (couche = nbcouche){
            break;
        }

        entree_deux.resize(0);
        entree_deux.resize(save.size());
        entree_deux = save;
        save.resize(0);



    }
    return entree_deux;
}



int main() {

    int nbcouche = 4;
    VectorXf NbP(4);
    NbP(0)= 2;
    NbP(1)= 1;
    NbP(2)= 3;
    NbP(2)= 2;
    VectorXf entree(3);
    entree(0)= 1;
    entree(1)=2;
    entree(2)=3;

    auto resultat= predict(entree, nbcouche,entree, true);
    std::cout << resultat  << std::endl;




}
