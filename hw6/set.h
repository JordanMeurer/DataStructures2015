#ifndef SETDEF
#define SETDEF

/*global variable*/
typedef int setElementT;
typedef struct setCDT *setADT;
setADT setNew();				/*create a new empty set*/
void setFree(setADT S);				/*free the space allocated for the set S */
int setInsertElementSorted(setADT S, setElementT E);
setADT setUnion(setADT A, setADT B);		/*returns the new set containing A Union B*/
setADT setIntersection(setADT A, setADT B);	/*returns the set containing A interection  B*/
setADT setDifference(setADT A, setADT B);	/*returns the new set containing A difference B*/
int setCardinalty(setADT S);			/* returns the number of elements in S*/
void setPrint(setADT S, char name);		/* print elements of S, A = {2, 5, 7}*/
#endif
