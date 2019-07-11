#include "dpfj.h"
#include "dpfj_compression.h"
#include "dpfj_quality.h"
#include "dpfpdd.h"
#include <iostream>

using namespace std;

int main() {
	int result = dpfpdd_init();
	if(DPFPDD_SUCCESS != result){
		cout << "error when calling dpfpdd_init(), " <<  result << endl;
		return 0;
	}
	unsigned int* count;
	DPFPDD_DEV_INFO* m_pReaders;
	int res = dpfpdd_query_devices(count, m_pReaders);
	DPFPDD_DEV dev = NULL;
	int readeropen = dpfpdd_open_ext(m_pReaders[0].name, DPFPDD_PRIORITY_COOPERATIVE, &dev);
	dpfpdd_exit();
	return 0;
}
