#include <stdio.h>
#include "boxlocal.h"

main() {
indexstruct  is;
boxlogstruct bls;

#define P(X)  printf(#X": %i\n", sizeof(X));
#define Pis(X)	printf("is."#X": %i\n", sizeof(is.X));

P(is);
Pis(hver);
Pis(id);
Pis(dest);
Pis(absender);
Pis(verbreitung);
Pis(betreff);
Pis(rxdate);
Pis(txdate);
Pis(lifetime);
Pis(txlifetime);
Pis(msgtype);
Pis(firstbyte);
Pis(start);
Pis(packsize);
Pis(size);
Pis(rxqrg);
Pis(rxfrom);
Pis(deleted);
Pis(pmode);
Pis(level);
Pis(fwdct);
Pis(msgflags);
Pis(erasetime);
Pis(lastread);
Pis(readcount);
Pis(readby);
Pis(eraseby);
Pis(sendbbs);
Pis(reserved);
Pis(msgnum);
Pis(bcastchecksum);
Pis(infochecksum);
Pis(headerchecksum);



}

