#include <cstdint>

class LinearRegression {

public:
    LinearRegression(bool is_classification);

    void fit(float *all_samples_inputs,
                         int32_t num_sample,
                         int32_t num_features);

    float *predict(float *sample_inputs,
                             int32_t num_features,
                             bool is_classification);

    ~LinearRegression();
};