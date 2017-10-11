#include <stdio.h>
#include <omp.h>
int tid;
#pragma omp threadprivate( tid )
int main(int argc, char * argv[])
{
	int numt;
	//  Incorrect way of finding out total no of threads
	//  Sequence fails every time because all threads other 
	//  0 are executed before "numt" can be assigned
	// #pragma omp parallel private( tid ) shared( numt )
	// {
	// 	int tid = omp_get_thread_num();
	// 	if(tid == 0){
	// 		for(int i = 1; i <= 1000000; i++);
	// 		numt = omp_get_num_threads();
	// 		}
	// 	printf("Hello World from %d thread of %d threads.\n",
	// 	 tid, numt);
	// }





	//    Correct way, though DEFINITELY not elegant :|
	// #pragma omp parallel private( tid ) shared( numt )
	// {
	// 	int tid = omp_get_thread_num();// tid is called double times
	// 	if(tid == 0){
	// 		for(int i = 1; i <= 1000000; i++);

	// 		numt = omp_get_num_threads();
	// 		}
	// }
	// #pragma omp parallel private( tid ) shared( numt )
	// {
	// 	tid = omp_get_thread_num();
	// 	printf("Hello to %d of %d.\n", tid, numt);
	// }
	



	
	// Making tid persistent across different parallel sections
	#pragma omp parallel default(shared)
	{   //parallel section 1
		// tid --> declared globally as 'thread private variable'
		#pragma omp single
		{
			for(int j=0; j < 100000000; j++)
				numt = omp_get_num_thread(s);
		}
		tid = omp_get_thread_num();
	//	{
	//setting barrier for synchronization
		//#pragma omp barrier
	//           barrier need not be set as "fork"ing 
	//           hasn't occured yet
	// }
		// parallel section 2
		printf("Hello to %d of %d.\n", tid, numt);
	}
	printf("Total %d\n", numt);
	printf("Last tid-- %d\n", tid);
	return 0;

}