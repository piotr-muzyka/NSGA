#ifndef CUSTOMASSERTION_H
#define CUSTOMASSERTION_H

#ifndef UT
    #include <assert.h>
#else
    #pragma message("UT defined")
    void assert(bool expression); /* define it in Unit test */
#endif

#endif // CUSTOMASSERTION_H
