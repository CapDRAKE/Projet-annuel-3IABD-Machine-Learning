#include "models.h"
//By Bastien LEUWERS

#if WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

bool classification;

extern "C" {
	LinearRegression::LinearRegression(bool is_classification) {
		classification = is_classification;
	}

	DLLEXPORT void LinearRegression::fit(float *all_samples_inputs,int32_t num_sample, int32_t num_features) {
		
	}

	//TEST
	DLLEXPORT float *LinearRegression::predict(float *sample_inputs, int32_t num_features, bool is_classification) {
		float prediction = 0;
		for(int i = 0; i < num_features; i++){
			prediction = prediction + [i]*sample_inputs[i];
		}
		return prediction;
	}
	//NOT GOOD
	DLLEXPORT float train(int32_t num_features, float *sample_inputs, int i){
		W[i] = W[i] + alpha;
		return W[i];
	}

	LinearRegression::~LinearRegression() {

	}
}

int main(){
	
}