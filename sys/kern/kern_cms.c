#include <sys/cms.h>

void expose_cms_hash(unsigned long cms_hash) {
    // set hash to local variable prevent compiler from optimizing out the hash
    volatile unsigned long hash = cms_hash;
    (void)hash; // suppress unused variable warning/error
    // do 3 nops to allow the CMS some more time to read the hash (not necessary, but nice to have)
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
}