/*
2018 Maximilian Wittmer
wittmaxi@linux.pizza

https://github.com/Wittmaxi/ZENeural/blob/master/LICENSE

*/

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
#define CATCH_CONFIG_DISABLE_MATCHERS
#include "../header/NeuralNetwork.hpp"
#include "../header/Layer.hpp"
#include "../header/VanillaRecurrentNetwork.hpp"
#include "../header/Perceptron.hpp"
#include "../header/typedefs.hpp"
#include "../header/util/numbers.hpp"
#include "../external/catch.hpp"

#include "test_Layer.hpp"
#include "test_HiddenLayer.hpp"
#include "test_Neuron.hpp"
#include "test_OutputLayer.hpp"
#include "test_NN.hpp"
#include "test_VRNN.hpp"
#include "test_Perceptron.hpp"
#include "test_numbers.hpp"