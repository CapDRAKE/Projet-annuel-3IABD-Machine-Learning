#include "models.h"
//By Bastien LEUWERS

LinearRegression::LinearRegression(bool is_classification) {

}

DLLEXPORT void LinearRegression::fit(float *all_samples_inputs,int32_t num_sample, int32_t num_features) {
	
}

DLLEXPORT float *LinearRegression::predict(float *sample_inputs, int32_t num_features, bool is_classification) {
    float prediction = 0;
	for(int i = 0; i < num_features; i++){
		prediction = prediction + [i]*sample_inputs[i];
	}
    return prediction;
}

LinearRegression::~LinearRegression() {

}
