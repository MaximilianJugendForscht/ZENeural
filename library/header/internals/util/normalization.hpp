/*
2018 Maximilian Wittmer
wittmaxi@linux.pizza

https://github.com/Wittmaxi/ZENeural/blob/master/LICENSE

*/

#pragma once
#include <math.h>
#include <functional>

namespace ZNN
{
template <class floatType>
struct Normalization
{
	Normalization(){};
	Normalization(const std::function<floatType(floatType)> &norm, const std::function<floatType(floatType)> &der) : normalization(norm), derivative(der){};
	std::function<floatType(floatType)> normalization;
	std::function<floatType(floatType)> derivative;
};

template <class floatType>
Normalization<floatType> Fermi()
{
	std::function<floatType(floatType)> normalization = [=](floatType input) -> floatType {
		return (1 / (1 + (std::exp(-input))));
	};
	std::function<floatType(floatType)> derivative = [=](floatType input) -> floatType {
		return normalization(input) * (1 - normalization(input));
	};
	return Normalization<floatType>(normalization, derivative);
}

template <class floatType>
Normalization<floatType> Identity()
{
	std::function<floatType(floatType)> normalization = [=](floatType input) -> floatType {
		return input;
	};
	std::function<floatType(floatType)> derivative = [=](floatType) -> floatType {
		return 1;
	};
	return Normalization<floatType>(normalization, derivative);
}

template<class floatType>
Normalization<floatType> TanH ()
{
	std::function<floatType(floatType)> normalization = [=](floatType input) -> floatType {
		return std::tanh (input);
	};
	std::function<floatType(floatType)> derivative = [=](floatType input) -> floatType {
		floatType normalizedValue = std::tanh(input);
		return 1 - normalizedValue * normalizedValue;
	};
	return Normalization<floatType>(normalization, derivative);
}

} // namespace ZNN