#include <iostream>
#include "Eigen"
#include <time.h>
using namespace Eigen;

struct Perceptron{
    VectorXf W;// Xf : la taille et le type (la on a taille X et float)
};

int Rand (int a, int b){
    int c ;
    c =  a + (int)((float)rand() * (b-a+1) / (RAND_MAX-1)) ;
    return c;
}

Perceptron* create_perceptron(int size){
    srand(time(NULL));
    Perceptron* p = new Perceptron();
    p->W.resize(size+1); // créer le vecteur de poids à size colonne et +1 car on ajoute le biais.
    p->W.setRandom(); // remplis avec des valeurs aléatoires entre -1 et 1 exclus.

//    std::cout << p->W  << std::endl;
    return p;
}

float prediction(Perceptron* p,VectorXf X){


    float resultat = p->W.transpose() * X;
    //VectorXf b2(1);

    if (resultat >= 0) {
        return 1;
    }
    else {
        return -1;
    }

}


void apprentissage(Perceptron* p, float pas, VectorXf Y, MatrixXf X, int nbtour){

    // X les entrées Y les sortis, X la matrice d'entrée, nbtour le nombre de fois que l'on va faire l'apprentissage
    int lchoisie;
    int a = X.rows() - 1; // nombre de ligne - 1  car premiere ligne indice 0

    VectorXf Xk(3);
    Xk(0)= 1;

    for (int i = 0; i<nbtour; i++){
        int colonne = 0;
        lchoisie = Rand(0,a);
        for (int y = 1 ; y< 3; y++){
            Xk(y) =  X(lchoisie,colonne);
            colonne ++;
        }


        float g = prediction(p,Xk);
        float Yk = Y(lchoisie );
//        std::cout << pas << std::endl;
//        std::cout << Yk<< std::endl;
//        std::cout << g << std::endl;
//        std::cout << Xk << std::endl;

        p->W = p->W + pas * (Yk - g) * Xk;

    }

}

int main() {

    Perceptron* p = create_perceptron(2);
    //std::cout << p->W << std::endl;
    //float a = prediction(p);
    float pas = 0.001;
    VectorXf Y(3);
    Y(0)= -1;
    Y(1)= 1;
    Y(2)= 1;

    MatrixXf X(3,2); // nb colonne nombre d'entrée du percptron
    X(0,0)= 0;
    X(0,1)= 0;
    X(1,0)= 0;
    X(1,1)= 1;
    X(2,0)= 1;
    X(2,1)= 0;

    int nbtour = 10000;

    apprentissage(p,pas,Y,X,nbtour);

    int lchoisie;
    VectorXf Xk(3);
    Xk(0)= 1;

    int colonne = 0;
    lchoisie = Rand(0,2);
    for (int y = 1 ; y< 3-1; y++){
        Xk(y) =  X(lchoisie,colonne);
        colonne ++;
    }

    auto resultat= prediction(p,Xk);
    auto resultat1= prediction(p,Xk);
    auto resultat2= prediction(p,Xk);
    std::cout << resultat  << std::endl;
    std::cout << resultat1  << std::endl;
    std::cout << resultat2 << std::endl;

    return 0;
}


