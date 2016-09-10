#ifndef CORE_H
#define CORE_H

struct CoreSettings;

template <typename ResultType>
class Core
{
public:
    virtual ~Core() {}

    virtual void execute(const CoreSettings& settings) = 0;
    virtual const ResultType& result() = 0;
};

#endif // CORE_H
