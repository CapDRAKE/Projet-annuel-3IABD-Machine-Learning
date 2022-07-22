#include <iostream>
#include "Eigen"
#include <time.h>
using namespace Eigen;
#if WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif
struct Perceptron{
    VectorXf W;// Xf : la taille et le type (la on a taille X et float)
};



Perceptron* create_perceptron(int size){
    srand(time(NULL));
    Perceptron* p = new Perceptron();
    p->W.resize(size+1); // créer le vecteur de poids à size colonne et +1 car on ajoute le biais.
    p->W.setRandom(); // remplis avec des valeurs aléatoires entre -1 et 1 exclus.

    std::cout << p->W  << std::endl;
    return p;
}

float prediction(Perceptron* p,VectorXf X){


    float resultat = p->W.transpose() * X;
    //std::cout << "coucou : " << p->W.transpose() * X  << std::endl;

    if (resultat >= 0) {
        return 1;
    }
    else {
        return -1;
    }

}


Perceptron* apprentissage(Perceptron* p, float pas, VectorXf Y, MatrixXf X, int nbtour){

    // X les entrées Y les sortis, X la matrice d'entrée, nbtour le nombre de fois que l'on va faire l'apprentissage
    int lchoisie;
    int a = X.rows() - 1; // nombre de ligne - 1  car premiere ligne indice 0

    VectorXf Xk(X.cols()+1);
    //std::cout << Xk.size() << std::endl;
    //std::cout << Xk<< std::endl;
    Xk(Xk.size()-1) = 1;
    std::cout << Xk << std::endl;
    for (int i = 0; i<nbtour; i++){
        int colonne = 0;
        lchoisie = rand()%X.rows();

        for (int y = 0 ; y< Xk.size()-1; y++){
            Xk(y) =  X(lchoisie,colonne);
            colonne ++;
        }

        //std::cout << Xk << std::endl;

        float g = prediction(p,Xk);
        float Yk = Y(lchoisie );
//        std::cout << pas << std::endl;
//        std::cout << Yk<< std::endl;
//        std::cout << g << std::endl;
//        std::cout << Xk << std::endl;
//        std::cout << "coucou:" << lchoisie << std::endl;
//        std::cout << "Xk:" << Xk << std::endl;
//        std::cout << "Yk:" << Yk << std::endl;

        p->W = p->W + pas * (Yk - g) * Xk;

    }

    return p;
}

int main() {
    int sizeP = 2;
    Perceptron* p = create_perceptron(sizeP);
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

    Perceptron* a = apprentissage(p,pas,Y,X,nbtour);


    for (int b = 0 ; b < X.rows(); b++){

        VectorXf Xk(X.cols()+1);
        Xk(Xk.size()-1) = 1;

        int colonne = 0;

        for (int y = 0 ; y< X.cols(); y++) {
            Xk(y) = X(b, colonne);
            colonne++;
        }
        auto resultat= prediction(a,Xk);
        std::cout << resultat  << std::endl;
    }

    return 0;
}