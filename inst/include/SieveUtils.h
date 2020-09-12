#ifndef SIEVE_UTILS_R
#define SIEVE_UTILS_R

#include "Cpp14MakeUnique.h"
#include "TonelliShanks.h"
#include <unordered_map>
#include <cstdlib>
#include <vector>
#include <numeric>
#include <cmath>

constexpr std::size_t oneThousand = 1000u;
constexpr double Significand53 = 9007199254740991.0;
constexpr int L1Cache = 32768;

using vec2dint = std::vector<std::vector<int>>;
using hash64vec = std::unordered_map<std::uint64_t, std::vector<int>>;
using hash64mpz = std::unordered_map<std::uint64_t, mpz_class>;
using hash64size_t = std::unordered_map<std::uint64_t, std::size_t>;

std::vector<std::size_t> SetSieveDist(const std::vector<int> &facBase, mpz_t myNum);

std::vector<std::uint8_t> MyIntToBit(std::size_t x, std::size_t dig);

std::vector<int> GetPrimesQuadRes(mpz_t myN, double LimB, double fudge1,
                                  double sqrLogLog, std::size_t myTarget);

void SinglePoly(const std::vector<std::size_t> &SieveDist,
                const std::vector<int> &facBase, const std::vector<int> &LnFB,
                vec2dint &powsOfSmooths, vec2dint &powsOfPartials,
                std::vector<std::size_t> &coFactorIndexVec, std::vector<int> &myStart,
                hash64vec &partFactorsMap, hash64mpz &partIntvlMap, hash64size_t &keepingTrack,
                std::vector<mpz_class> &smoothInterval, std::vector<double> &largeCoFactors,
                std::vector<mpz_class> &partialInterval, mpz_class NextPrime,
                mpz_class LowBound, mpz_class myNum, std::size_t &nPartial,
                std::size_t &nSmooth, std::size_t &coFactorInd, int theCut,
                int DoubleLenB, int mpzFacSize, int vecMaxSize, std::size_t strt);

#endif
