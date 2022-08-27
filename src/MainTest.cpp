#include <DLstdc.h>
#include <DLpointer.h>


int main()
{
	const DLchar*  x = (const DLchar*)"123";
	int test_x = Dstdc_atoi( x );
	std::cout << test_x << std::endl;

	check_smart_ptr();
}