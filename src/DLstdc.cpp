#include "DLstdc.h"

DLsint32
Dstdc_atoi( const DLchar* nptr )
{
	DLsint32 value = DL_0;
	DLsint32 sign = DL_1;
	int i = 0;

	assert( nptr != DL_NULL );

	if( *nptr == '\0' )
	{
		return DL_0;
	}

	if( nptr[0] == '-' )
	{
		sign = -DL_1;
		i++;
	}

	for( ; nptr[i] != '\0'; ++i )
	{
		if( isdigit(nptr[i]) == DL_FALSE )
		{
			return DL_0;
		}

		value = value * DL_10 + nptr[i] - '0';
	}

	return sign * value;
}
