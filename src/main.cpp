#include <Arduino.h>
#include "ceiling_fan_model_float.h"

// Number of features expected by the model
const int FEATURE_COUNT = 17;

// Reference input from Google Colab
// Feature order must remain identical to Python.
float test_features[FEATURE_COUNT] = {
    20.0f,          // 0: VOC
    47.5499992f,    // 1: Sound pressure level
    74.7343369f,    // 2: Relative humidity
    27.8033333f,    // 3: Air temperature
    0.0f,           // 4: Illuminance
    4.73333311f,    // 5: PM2.5
    448.666656f,    // 6: CO2
    0.0f,           // 7: Occupant presence
    0.0f,           // 8: Occupant count
    -0.806444604f,  // 9: Hour sin
    -0.591309648f,  // 10: Hour cos
    -0.433883739f,  // 11: Day of week sin
    -0.900968868f,  // 12: Day of week cos
    0.0f,           // 13: Admin office
    1.0f,           // 14: Lecture room
    0.0f,           // 15: Research office
    0.0f            // 16: Student library
};

void setup() {
    Serial.begin(115200);
    delay(1000);

    Serial.println();
    Serial.println("================================");
    Serial.println("Smart Branch ML Inference Test");
    Serial.println("================================");

    // Run the converted Random Forest
    float prediction = ceiling_fan_model_float_predict(
        test_features,
        FEATURE_COUNT
    );

    Serial.println("Inference completed!");

    Serial.print("Predicted ceiling fan energy: ");
    Serial.println(prediction, 10);

    Serial.println("================================");
}

void loop() {
    // No repeated inference for this initial test.
}
