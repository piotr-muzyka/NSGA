#ifndef GENOTYPE_H
#define GENOTYPE_H

class Genotype
{
public:
    Genotype();
    Genotype(const Genotype& genA, const Genotype& genB);

    void mutate(unsigned mutationProbabilityInPercent);
};

#endif // GENOTYPE_H
